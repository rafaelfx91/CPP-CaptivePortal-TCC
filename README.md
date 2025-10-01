🛡️ TCC - Sistema de Captive Portal Educativo para Conscientização sobre Phishing

![ESP32](https://img.shields.io/badge/ESP32-NodeMCU-green)
![Platform](https://img.shields.io/badge/Platform-Arduino_IDE-blue)
![License](https://img.shields.io/badge/License-MIT-yellow)
![TCC](https://img.shields.io/badge/Project-TCC_Security-orange)

📋 Sobre o Projeto<br>
Este projeto foi desenvolvido como Trabalho de Conclusão de Curso (TCC) em Segurança da Informação, com o objetivo de demonstrar de forma prática e educativa os riscos associados a redes WiFi públicas e ataques de phishing através de captive portals.


🎯 Objetivo Educacional<br>
ATENÇÃO: Este projeto tem fins exclusivamente educacionais e de pesquisa acadêmica. O objetivo é conscientizar usuários sobre os perigos de redes WiFi não confiáveis, não promover atividades maliciosas.


</h3>⚠️ Aviso Legal e Ético</h3>
<ul> 
	<li>🔒 USO APENAS EDUCACIONAL - Nunca utilize em redes sem autorização</li>
	<li>📝 CONSENTIMENTO - Sempre informe participantes sobre a natureza do experimento</li>
	<li>🗑️ DADOS FICTÍCIOS - Use apenas dados de teste, destrua após pesquisa</li>
	<li>⚖️ CONFORMIDADE LEGAL - Obedeça às leis locais de privacidade e segurança</li>
</ul>	
	
</h3>🛠️ Tecnologias Utilizadas</h3>
<ul>
	<li>Componente	Descrição</li>
	<li>ESP32	Microcontrolador principal</li>
	<li>Arduino IDE	Ambiente de desenvolvimento</li>
	<li>SPIFFS	Sistema de arquivos para armazenamento</li>
	<li>DNS Server	Redirecionamento de tráfego</li>
	<li>Web Server	Servidor HTTP para páginas web</li>
</ul>

📁 Estrutura do Projeto <br>
TCC-Captive-Portal/<br>
├── src/<br>
│   └── captive_portal.ino      # Código principal<br>
└── README.md                   # Este arquivo<br>


<h2>🔧 Funcionalidades Implementadas</h2>

<h3>1. 🎣 Páginas de Phishing Educacionais</h3>
<ul>
  <li><strong>Facebook Clone</strong> - Página idêntica ao Facebook</li>
  <li><strong>Instagram Clone</strong> - Página idêntica ao Instagram</li>
  <li><strong>Google Clone</strong> - Página idêntica ao Google</li>
</ul>

<h3>2. 🌐 Captive Portal Automático</h3>
<ul>
  <li><strong>Redirecionamento DNS</strong> de todos os domínios</li>
  <li><strong>Detecção automática</strong> em Android, iOS e Windows</li>
  <li><strong>Página inicial</strong> com múltiplas opções de login</li>
</ul>

<h3>3. 📊 Sistema de Monitoramento</h3>
<ul>
  <li><strong>Armazenamento local</strong> de tentativas de login</li>
  <li><strong>Painel administrativo</strong> para visualização</li>
  <li><strong>Logs em tempo real</strong> via Serial Monitor</li>
</ul>


<h3>🚀 Como Funciona</h3>
<h3>Fluxo do Sistema:</h3>
<ul>
 <li>Usuário conecta na rede "WiFi 5G Livre"</li>
 <li>Captive portal detecta e redireciona para página inicial</li>
 <li>Usuário escolhe plataforma para "login"</li>
 <li>Credenciais são capturadas (apenas para demonstração)</li>
 <li>Acesso é liberado para internet real</li>
</ul>
 
URLs de Acesso:
<ul>
 <li><strong>Página Principal:</strong> http://192.168.4.1</li>
 <li><strong>Facebook Fake:</strong> http://192.168.4.1/facebook</li>
 <li><strong>Instagram Fake:</strong> http://192.168.4.1/instagram</li>
 <li><strong>Google Fake:</strong> http://192.168.4.1/google</li>
</ul>


<h3>🔌 Hardware Necessário</h3>
<table> <thead> <tr> <th>Componente</th> <th>Quantidade</th> <th>Observações</th> <th>📸</th> </tr> </thead> <tbody> <tr> <td><strong>ESP32</strong></td> <td>1 unidade</td> <td>NodeMCU-32S ou ESP32 DevKit V1</td> <td>🟢</td> </tr> <tr> <td><strong>Cabo USB</strong></td> <td>1 unidade</td> <td>USB-C ou Micro-USB para alimentação e programação</td> <td>🔌</td> </tr> <tr> <td><strong>Fonte de Energia</strong></td> <td>1 unidade</td> <td>Powerbank 5V/2A ou adaptador USB</td> <td>🔋</td> </tr> <tr> <td><strong>Computador</strong></td> <td>1 unidade</td> <td>Com Arduino IDE instalado</td> <td>💻</td> </tr> </tbody> </table>


<h3>⚙️ Instalação e Configuração</h3>

<h3>1. Preparação do Ambiente</h3>
<ul>
	<li># Instalar Arduino IDE</li>
	<li># Adicionar URL do ESP32 no Boards Manager:</li>
	<li>https://espressif.github.io/arduino-esp32/package_esp32_index.json</li>
</ul>

<h3>2. Instalação das Bibliotecas</h3>
<h4>// Bibliotecas necessárias:</h4>
<ul>
	<li>#include <WiFi.h></li>
	<li>#include <WebServer.h></li>
	<li>#include <DNSServer.h></li>
	<li>#include "SPIFFS.h"</li>
 </ul>
 
<h3>3. Configuração do Código</h3>
<h4>// Configurações principais:</h4>
<ul>
	<li>String wifiName = "WiFi 5G Livre";  // Nome da rede</li>
	<li>IPAddress apIP(192, 168, 4, 1);     // IP fixo do AP</li>
</ul>
 
<h3>4. Upload e Teste</h3>
<ul>
	<li>Conecte o ESP32 via USB</li>
	<li>Selecione a porta COM correta</li>
	<li>Faça upload do código</li>
	<li>Abra Serial Monitor (115200 baud)</li>
</ul>
 
 
<h3>📖 Metodologia de Pesquisa</h3>

Abordagem Educacional
<ul>
    <li>Demonstração Prática dos riscos de phishing</li>
    <li>Conscientização sobre redes WiFi públicas</li>
    <li>Identificação de páginas falsas</li>
</ul>

<h3>Coleta de Dados (Ética)</h3>
<ul>
    <li>Apenas dados fictícios para demonstração</li>
    <li>Participantes informados sobre o experimento</li>
    <li>Dados destruídos após pesquisa</li>
</ul>

<h3>🎓 Aplicação no TCC</h3>
<h4>Pontos de Análise:</h4>
<ul>
    <li>Eficácia do Phishing - Como usuários caem em páginas falsas</li>
    <li>Falhas Humanas - Fatores psicológicos explorados</li>
    <li>Prevenções - Medidas de proteção recomendadas</li>
</ul>

<h3>Resultados Esperados:</h3>
<ul>
    <li>Aumento da conscientização sobre segurança</li>
    <li>Identificação de padrões de comportamento de risco</li>
    <li>Desenvolvimento de melhores práticas de segurança</li>
</ul>

<h3>🛡️ Medidas de Proteção Demonstradas</h3>
<h4>O que aprendemos:</h4>
<ul>
   <li> ✅ Verificar certificados SSL</li>
    <li>✅ Não reutilizar senhas em redes públicas</li>
    <li>✅ Usar VPN em redes não confiáveis</li>
    <li>✅ Desativar WiFi automático</li>
    <li>✅ Verificar URLs antes de logins</li>
</ul>
 
<h3>📊 Estrutura do Código</h3>
<ul>
	<li>// Organização principal:</li>
	<li>1. Configurações iniciais e bibliotecas</li>
	<li>2. Variáveis globais e SPIFFS</li>
	<li>3. Setup - Inicialização do servidor</li>
	<li>4. Rotas HTTP - Páginas web</li>
	<li>5. Processamento de login</li>
	<li>6. Captive portal URLs</li>
	<li>7. Loop principal</li>
</ul>	
 
<h3>🤝 Contribuições</h3>
Este projeto é parte de um TCC acadêmico. Contribuições para melhorias educacionais são bem-vindas, desde que mantenham o foco ético e educativo.


<h3>📜 Licença</h3>
Este projeto está sob licença MIT. Veja o arquivo LICENSE para detalhes.


<h3>📚 Referências</h3>
<ul>  
	<li>OWASP - Open Web Application Security Project</li>
    <li>MITRE ATT&CK Framework</li>
    <li>NIST Cybersecurity Framework</li>
    <li>Artigos científicos sobre phishing awareness</li>
</ul>
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


⚙️ Instalação e Configuração
1. Preparação do Ambiente
	# Instalar Arduino IDE
	# Adicionar URL do ESP32 no Boards Manager:
	https://espressif.github.io/arduino-esp32/package_esp32_index.json
 

2. Instalação das Bibliotecas
// Bibliotecas necessárias:
#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include "SPIFFS.h"
 
 
3. Configuração do Código
// Configurações principais:
String wifiName = "WiFi 5G Livre";  // Nome da rede
IPAddress apIP(192, 168, 4, 1);     // IP fixo do AP
 
 
4. Upload e Teste
 .Conecte o ESP32 via USB
 .Selecione a porta COM correta
 .Faça upload do código
 .Abra Serial Monitor (115200 baud)
 
 
 📖 Metodologia de Pesquisa
Abordagem Educacional
    Demonstração Prática dos riscos de phishing
    Conscientização sobre redes WiFi públicas
    Identificação de páginas falsas


Coleta de Dados (Ética)
    Apenas dados fictícios para demonstração
    Participantes informados sobre o experimento
    Dados destruídos após pesquisa


🎓 Aplicação no TCC
Pontos de Análise:
    Eficácia do Phishing - Como usuários caem em páginas falsas
    Falhas Humanas - Fatores psicológicos explorados
    Prevenções - Medidas de proteção recomendadas


Resultados Esperados:
    Aumento da conscientização sobre segurança
    Identificação de padrões de comportamento de risco
    Desenvolvimento de melhores práticas de segurança


🛡️ Medidas de Proteção Demonstradas
O que aprendemos:
    ✅ Verificar certificados SSL
    ✅ Não reutilizar senhas em redes públicas
    ✅ Usar VPN em redes não confiáveis
    ✅ Desativar WiFi automático
    ✅ Verificar URLs antes de logins
 
 
📊 Estrutura do Código
	// Organização principal:
	1. Configurações iniciais e bibliotecas
	2. Variáveis globais e SPIFFS
	3. Setup - Inicialização do servidor
	4. Rotas HTTP - Páginas web
	5. Processamento de login
	6. Captive portal URLs
	7. Loop principal
 
🤝 Contribuições

Este projeto é parte de um TCC acadêmico. Contribuições para melhorias educacionais são bem-vindas, desde que mantenham o foco ético e educativo.


📜 Licença
Este projeto está sob licença MIT. Veja o arquivo LICENSE para detalhes.


📚 Referências
    OWASP - Open Web Application Security Project
    MITRE ATT&CK Framework
    NIST Cybersecurity Framework
    Artigos científicos sobre phishing awareness

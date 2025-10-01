🛡️ TCC - Sistema de Captive Portal Educativo para Conscientização sobre Phishing

![ESP32](https://img.shields.io/badge/ESP32-NodeMCU-green)
![Platform](https://img.shields.io/badge/Platform-Arduino_IDE-blue)
![License](https://img.shields.io/badge/License-MIT-yellow)
![TCC](https://img.shields.io/badge/Project-TCC_Security-orange)

📋 Sobre o Projeto<br>
Este projeto foi desenvolvido como Trabalho de Conclusão de Curso (TCC) em Segurança da Informação, com o objetivo de demonstrar de forma prática e educativa os riscos associados a redes WiFi públicas e ataques de phishing através de captive portals.
🎯 Objetivo Educacional


ATENÇÃO: Este projeto tem fins exclusivamente educacionais e de pesquisa acadêmica. O objetivo é conscientizar usuários sobre os perigos de redes WiFi não confiáveis, não promover atividades maliciosas.


⚠️ Aviso Legal e Ético
 .🔒 USO APENAS EDUCACIONAL - Nunca utilize em redes sem autorização
 .📝 CONSENTIMENTO - Sempre informe participantes sobre a natureza do experimento
 .🗑️ DADOS FICTÍCIOS - Use apenas dados de teste, destrua após pesquisa
 .⚖️ CONFORMIDADE LEGAL - Obedeça às leis locais de privacidade e segurança
	
	
🛠️ Tecnologias Utilizadas
Componente	Descrição
ESP32	Microcontrolador principal
Arduino IDE	Ambiente de desenvolvimento
SPIFFS	Sistema de arquivos para armazenamento
DNS Server	Redirecionamento de tráfego
Web Server	Servidor HTTP para páginas web


📁 Estrutura do Projeto
TCC-Captive-Portal/
├── src/
│   └── captive_portal.ino      # Código principal
├── docs/
│   ├── ethical_guidelines.md   # Diretrizes éticas
│   └── presentation/           # Arquivos da apresentação
├── schematics/                 # Diagramas de conexão
└── README.md                   # Este arquivo


🔧 Funcionalidades Implementadas
1. 🎣 Páginas de Phishing Educacionais
 .Facebook Clone - Página idêntica ao Facebook
 .Instagram Clone - Página idêntica ao Instagram
 .Google Clone - Página idêntica ao Google


2. 🌐 Captive Portal Automático
 .Redirecionamento DNS de todos os domínios
 .Detecção automática em Android, iOS e Windows
 .Página inicial com múltiplas opções de login


3. 📊 Sistema de Monitoramento
 .Armazenamento local de tentativas de login
 .Painel administrativo para visualização
 .Logs em tempo real via Serial Monitor


🚀 Como Funciona
Fluxo do Sistema:
 .Usuário conecta na rede "WiFi 5G Livre"
 .Captive portal detecta e redireciona para página inicial
 .Usuário escolhe plataforma para "login"
 .Credenciais são capturadas (apenas para demonstração)
 .Acesso é liberado para internet real
 
 
URLs de Acesso:
 .Página Principal: http://192.168.4.1
 .Facebook Fake: http://192.168.4.1/facebook
 .Instagram Fake: http://192.168.4.1/instagram
 .Google Fake: http://192.168.4.1/google
 

🔌 Hardware Necessário
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

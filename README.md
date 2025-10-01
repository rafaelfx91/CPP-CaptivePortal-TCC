<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>TCC - Sistema de Captive Portal Educativo</title>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }
        
        body {
            font-family: 'Segoe UI', Arial, sans-serif;
            line-height: 1.6;
            color: #333;
            background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
            min-height: 100vh;
        }
        
        .container {
            max-width: 1200px;
            margin: 0 auto;
            padding: 20px;
        }
        
        header {
            text-align: center;
            background: rgba(255, 255, 255, 0.95);
            padding: 40px 20px;
            border-radius: 15px;
            box-shadow: 0 10px 30px rgba(0,0,0,0.1);
            margin-bottom: 30px;
        }
        
        h1 {
            color: #2c3e50;
            font-size: 2.5em;
            margin-bottom: 20px;
        }
        
        .badges {
            display: flex;
            justify-content: center;
            gap: 15px;
            margin: 20px 0;
            flex-wrap: wrap;
        }
        
        .badge {
            padding: 8px 15px;
            border-radius: 20px;
            font-size: 0.9em;
            font-weight: bold;
            color: white;
        }
        
        .section {
            background: rgba(255, 255, 255, 0.95);
            padding: 30px;
            border-radius: 15px;
            box-shadow: 0 10px 30px rgba(0,0,0,0.1);
            margin-bottom: 30px;
        }
        
        h2 {
            color: #2c3e50;
            border-bottom: 3px solid #3498db;
            padding-bottom: 10px;
            margin-bottom: 20px;
        }
        
        h3 {
            color: #34495e;
            margin: 20px 0 10px 0;
        }
        
        .warning-box {
            background: #fff3cd;
            border: 2px solid #ffeaa7;
            border-left: 6px solid #f39c12;
            padding: 20px;
            border-radius: 10px;
            margin: 20px 0;
        }
        
        table {
            width: 100%;
            border-collapse: collapse;
            margin: 20px 0;
        }
        
        th, td {
            padding: 12px 15px;
            text-align: left;
            border-bottom: 1px solid #ddd;
        }
        
        th {
            background: #3498db;
            color: white;
        }
        
        tr:hover {
            background: #f5f5f5;
        }
        
        .feature-list {
            list-style: none;
            padding: 0;
        }
        
        .feature-list li {
            padding: 10px 0;
            border-bottom: 1px solid #eee;
        }
        
        .feature-list li:before {
            content: "✅ ";
            margin-right: 10px;
        }
        
        .code-block {
            background: #2c3e50;
            color: #ecf0f1;
            padding: 20px;
            border-radius: 10px;
            margin: 15px 0;
            overflow-x: auto;
            font-family: 'Courier New', monospace;
        }
        
        .file-structure {
            background: #34495e;
            color: #ecf0f1;
            padding: 20px;
            border-radius: 10px;
            font-family: 'Courier New', monospace;
            line-height: 1.8;
        }
        
        .step-list {
            list-style: none;
            padding: 0;
        }
        
        .step-list li {
            padding: 15px;
            margin: 10px 0;
            background: #ecf0f1;
            border-radius: 8px;
            border-left: 4px solid #3498db;
        }
        
        .step-number {
            background: #3498db;
            color: white;
            padding: 5px 10px;
            border-radius: 50%;
            margin-right: 10px;
            font-weight: bold;
        }
        
        footer {
            text-align: center;
            padding: 20px;
            color: white;
            margin-top: 40px;
        }
        
        @media (max-width: 768px) {
            .container {
                padding: 10px;
            }
            
            h1 {
                font-size: 2em;
            }
            
            .section {
                padding: 20px;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <header>
            <h1>🛡️ TCC - Sistema de Captive Portal Educativo</h1>
            <div class="badges">
                <div class="badge" style="background: #27ae60;">ESP32-NodeMCU</div>
                <div class="badge" style="background: #2980b9;">Arduino IDE</div>
                <div class="badge" style="background: #f39c12;">MIT License</div>
                <div class="badge" style="background: #e74c3c;">TCC Security</div>
            </div>
        </header>

        <section class="section">
            <h2>📋 Sobre o Projeto</h2>
            <p>Este projeto foi desenvolvido como <strong>Trabalho de Conclusão de Curso (TCC)</strong> em <strong>Segurança da Informação</strong>, com o objetivo de demonstrar de forma prática e educativa os riscos associados a redes WiFi públicas e ataques de phishing através de captive portals.</p>
            
            <div class="warning-box">
                <h3>🎯 Objetivo Educacional</h3>
                <p><strong>ATENÇÃO:</strong> Este projeto tem fins <strong>exclusivamente educacionais</strong> e de pesquisa acadêmica. O objetivo é <strong>conscientizar usuários</strong> sobre os perigos de redes WiFi não confiáveis, <strong>não promover atividades maliciosas</strong>.</p>
            </div>
        </section>

        <section class="section">
            <h2>⚠️ Aviso Legal e Ético</h2>
            <ul class="feature-list">
                <li>🔒 <strong>USO APENAS EDUCACIONAL</strong> - Nunca utilize em redes sem autorização</li>
                <li>📝 <strong>CONSENTIMENTO</strong> - Sempre informe participantes sobre a natureza do experimento</li>
                <li>🗑️ <strong>DADOS FICTÍCIOS</strong> - Use apenas dados de teste, destrua após pesquisa</li>
                <li>⚖️ <strong>CONFORMIDADE LEGAL</strong> - Obedeça às leis locais de privacidade e segurança</li>
            </ul>
        </section>

        <section class="section">
            <h2>🛠️ Tecnologias Utilizadas</h2>
            <table>
                <thead>
                    <tr>
                        <th>Componente</th>
                        <th>Descrição</th>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <td><strong>ESP32</strong></td>
                        <td>Microcontrolador principal</td>
                    </tr>
                    <tr>
                        <td><strong>Arduino IDE</strong></td>
                        <td>Ambiente de desenvolvimento</td>
                    </tr>
                    <tr>
                        <td><strong>SPIFFS</strong></td>
                        <td>Sistema de arquivos para armazenamento</td>
                    </tr>
                    <tr>
                        <td><strong>DNS Server</strong></td>
                        <td>Redirecionamento de tráfego</td>
                    </tr>
                    <tr>
                        <td><strong>Web Server</strong></td>
                        <td>Servidor HTTP para páginas web</td>
                    </tr>
                </tbody>
            </table>
        </section>

        <section class="section">
            <h2>📁 Estrutura do Projeto</h2>
            <div class="file-structure">
                TCC-Captive-Portal/<br>
                ├── src/<br>
                │   └── captive_portal.ino      # Código principal<br>
                ├── docs/<br>
                │   ├── ethical_guidelines.md   # Diretrizes éticas<br>
                │   └── presentation/           # Arquivos da apresentação<br>
                ├── schematics/                 # Diagramas de conexão<br>
                └── README.md                   # Este arquivo
            </div>
        </section>

        <section class="section">
            <h2>🔧 Funcionalidades Implementadas</h2>
            
            <h3>1. 🎣 Páginas de Phishing Educacionais</h3>
            <ul class="feature-list">
                <li><strong>Facebook Clone</strong> - Página idêntica ao Facebook</li>
                <li><strong>Instagram Clone</strong> - Página idêntica ao Instagram</li>
                <li><strong>Google Clone</strong> - Página idêntica ao Google</li>
            </ul>

            <h3>2. 🌐 Captive Portal Automático</h3>
            <ul class="feature-list">
                <li>Redirecionamento DNS de todos os domínios</li>
                <li>Detecção automática em Android, iOS e Windows</li>
                <li>Página inicial com múltiplas opções de login</li>
            </ul>

            <h3>3. 📊 Sistema de Monitoramento</h3>
            <ul class="feature-list">
                <li>Armazenamento local de tentativas de login</li>
                <li>Painel administrativo para visualização</li>
                <li>Logs em tempo real via Serial Monitor</li>
            </ul>
        </section>

        <section class="section">
            <h2>🚀 Como Funciona</h2>
            
            <h3>Fluxo do Sistema:</h3>
            <ol class="step-list">
                <li><span class="step-number">1</span> <strong>Usuário conecta</strong> na rede "WiFi 5G Livre"</li>
                <li><span class="step-number">2</span> <strong>Captive portal detecta</strong> e redireciona para página inicial</li>
                <li><span class="step-number">3</span> <strong>Usuário escolhe</strong> plataforma para "login"</li>
                <li><span class="step-number">4</span> <strong>Credenciais são capturadas</strong> (apenas para demonstração)</li>
                <li><span class="step-number">5</span> <strong>Acesso é liberado</strong> para internet real</li>
            </ol>

            <h3>URLs de Acesso:</h3>
            <div class="code-block">
                Página Principal: http://192.168.4.1<br>
                Facebook Fake: http://192.168.4.1/facebook<br>
                Instagram Fake: http://192.168.4.1/instagram<br>
                Google Fake: http://192.168.4.1/google
            </div>
        </section>

        <section class="section">
            <h2>🔌 Hardware Necessário</h2>
            <table>
                <thead>
                    <tr>
                        <th>Componente</th>
                        <th>Quantidade</th>
                        <th>Observações</th>
                        <th>📸</th>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <td><strong>ESP32</strong></td>
                        <td>1 unidade</td>
                        <td>NodeMCU-32S ou ESP32 DevKit V1</td>
                        <td>🟢</td>
                    </tr>
                    <tr>
                        <td><strong>Cabo USB</strong></td>
                        <td>1 unidade</td>
                        <td>USB-C ou Micro-USB para alimentação e programação</td>
                        <td>🔌</td>
                    </tr>
                    <tr>
                        <td><strong>Fonte de Energia</strong></td>
                        <td>1 unidade</td>
                        <td>Powerbank 5V/2A ou adaptador USB</td>
                        <td>🔋</td>
                    </tr>
                    <tr>
                        <td><strong>Computador</strong></td>
                        <td>1 unidade</td>
                        <td>Com Arduino IDE instalado</td>
                        <td>💻</td>
                    </tr>
                </tbody>
            </table>
        </section>

        <section class="section">
            <h2>⚙️ Instalação e Configuração</h2>
            
            <h3>1. Preparação do Ambiente</h3>
            <div class="code-block">
                # Instalar Arduino IDE<br>
                # Adicionar URL do ESP32 no Boards Manager:<br>
                https://espressif.github.io/arduino-esp32/package_esp32_index.json
            </div>

            <h3>2. Instalação das Bibliotecas</h3>
            <div class="code-block">
                // Bibliotecas necessárias:<br>
                #include &lt;WiFi.h&gt;<br>
                #include &lt;WebServer.h&gt;<br>
                #include &lt;DNSServer.h&gt;<br>
                #include "SPIFFS.h"
            </div>

            <h3>3. Configuração do Código</h3>
            <div class="code-block">
                // Configurações principais:<br>
                String wifiName = "WiFi 5G Livre";  // Nome da rede<br>
                IPAddress apIP(192, 168, 4, 1);     // IP fixo do AP
            </div>

            <h3>4. Upload e Teste</h3>
            <ul class="feature-list">
                <li>Conecte o ESP32 via USB</li>
                <li>Selecione a porta COM correta</li>
                <li>Faça upload do código</li>
                <li>Abra Serial Monitor (115200 baud)</li>
            </ul>
        </section>

        <section class="section">
            <h2>📖 Metodologia de Pesquisa</h2>
            
            <h3>Abordagem Educacional</h3>
            <ul class="feature-list">
                <li><strong>Demonstração Prática</strong> dos riscos de phishing</li>
                <li><strong>Conscientização</strong> sobre redes WiFi públicas</li>
                <li><strong>Identificação</strong> de páginas falsas</li>
            </ul>

            <h3>Coleta de Dados (Ética)</h3>
            <ul class="feature-list">
                <li>Apenas dados fictícios para demonstração</li>
                <li>Participantes informados sobre o experimento</li>
                <li>Dados destruídos após pesquisa</li>
            </ul>
        </section>

        <section class="section">
            <h2>🎓 Aplicação no TCC</h2>
            
            <h3>Pontos de Análise:</h3>
            <ul class="feature-list">
                <li><strong>Eficácia do Phishing</strong> - Como usuários caem em páginas falsas</li>
                <li><strong>Falhas Humanas</strong> - Fatores psicológicos explorados</li>
                <li><strong>Prevenções</strong> - Medidas de proteção recomendadas</li>
            </ul>

            <h3>Resultados Esperados:</h3>
            <ul class="feature-list">
                <li>Aumento da conscientização sobre segurança</li>
                <li>Identificação de padrões de comportamento de risco</li>
                <li>Desenvolvimento de melhores práticas de segurança</li>
            </ul>
        </section>

        <section class="section">
            <h2>🛡️ Medidas de Proteção Demonstradas</h2>
            <h3>O que aprendemos:</h3>
            <ul class="feature-list">
                <li>✅ Verificar certificados SSL</li>
                <li>✅ Não reutilizar senhas em redes públicas</li>
                <li>✅ Usar VPN em redes não confiáveis</li>
                <li>✅ Desativar WiFi automático</li>
                <li>✅ Verificar URLs antes de logins</li>
            </ul>
        </section>

        <section class="section">
            <h2>📊 Estrutura do Código</h2>
            <div class="code-block">
                // Organização principal:<br>
                1. Configurações iniciais e bibliotecas<br>
                2. Variáveis globais e SPIFFS<br>
                3. Setup - Inicialização do servidor<br>
                4. Rotas HTTP - Páginas web<br>
                5. Processamento de login<br>
                6. Captive portal URLs<br>
                7. Loop principal
            </div>
        </section>

        <section class="section">
            <h2>🤝 Contribuições</h2>
            <p>Este projeto é parte de um TCC acadêmico. Contribuições para melhorias educacionais são bem-vindas, desde que mantenham o foco ético e educativo.</p>
        </section>

        <section class="section">
            <h2>📜 Licença</h2>
            <p>Este projeto está sob licença MIT. Veja o arquivo LICENSE para detalhes.</p>
        </section>

        <section class="section">
            <h2>📚 Referências</h2>
            <ul class="feature-list">
                <li>OWASP - Open Web Application Security Project</li>
                <li>MITRE ATT&CK Framework</li>
                <li>NIST Cybersecurity Framework</li>
                <li>Artigos científicos sobre phishing awareness</li>
            </ul>
        </section>

        <footer>
            <p><strong>⚠️ LEMBRETE:</strong> Este projeto deve ser usado apenas para educação e pesquisa autorizada.</p>
            <p><strong>Educação em Segurança é a Melhor Defesa! 🔐</strong></p>
        </footer>
    </div>
</body>
</html>
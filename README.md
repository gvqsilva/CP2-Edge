<p align='center'>
  <img loading="lazy" src = "https://github.com/gvqsilva/CP-Edge/assets/110639916/e44b584a-f189-41b0-9876-63ff29b3bed5"/>
</p>
<h1 align="center">Projeto de Monitoramento de Ambiente</h1>

# Índice
* [Descrição do Projeto](#descrição-do-projeto)
* [Funcionalidades](#funcionalidades)
* [Regras de Funcionamento](#regras-de-funcionamento)
* [Componentes](#componentes)
* [Instalação](#instalacao)
* [Como usar](#como-usar)
* [Código do programa](#coódigo-do-programa)
* [Benefícios](#beneficios)


<h2 id="Descricao do Projeto">📘Descrição do projeto:</h2>
  O projeto de monitoramento de ambiente visa criar um sistema inteligente e acessível para monitorar diferentes variáveis ambientais em tempo real. O projeto oferece uma solução versátil e customizável para acompanhar condições ambientais em diversos contextos, desde residências até ambientes industriais.


<h2 id="Funcionalidades">🔨Funcionalidades do projeto:</h2>

  `Funcionalidade 1`: Medição contínua da luminosidade ambiente utilizando um sensor LDR;
  
  `Funcionalidade 2`: Medição contínua de temperatura e umidade do ambiente utilizando um sensor DHT11 ou DHT22;
  
  `Funcionalidade 3`: Indicação visual do estado de luminosidade utilizando LEDs verde, amarelo e vermelho e display LCD;
  
  `Funcionalidade 4`: Alerta sonoro em caso de nível crítico de luminosidade, umidade ou temperatura

<h2 id="Regras de Funcionamento">📑Regras de Funcionamento:</h2>

`1ª Regra`: Enquanto o ambiente estiver escuro, o LED Verde permanece aceso.

`2ª Regra`: Quando o ambiente estiver a meia luz, o LED Amarelo acende e a mensagem "Ambiente a meia luz" é exibida no Display.

`3ª Regra`: Quando o ambiente estiver totalmente iluminado, o LED Vermelho acende e a mensagem "Ambiente muito claro" é exibida no Display.

`4ª Regra`: Enquanto o ambiente estiver totalmente iluminado, o Buzzer fica ligado continuamente.

`5ª Regra`: Se a temperatura estiver ideal, entre 10°C e 15°C, o Display exibe "Temperatura OK" e o valor da temperatura.

`6ª Regra`: Se a umidade estiver ideal, entre 50% e 70%, o Display exibe "Umidade OK" e o valor da umidade

`7ª Regra`: Os valores apresentados no Display são a média de pelo menos 5 leituras dos sensores, e são atualizados a cada 5 segundos.

`8ª Regra`:Se a temperatura estiver fora da
faixa ideal, o LED Amarelo acende e o Buzzer é ativado continuamente. O Display informa "Temperatura Alta" para valores acima de 15°C e "Temperatura Baixa" para valores abaixo de 10°C, mostrando também a temperatura atual.

`9ª Regra`: Se a umidade estiver fora da faixa
ideal, o LED Vermelho acende e o Buzzer é ativado continuamente. O Display informa "Umidade Alta" para valores acima de 70% e "Umidade Baixa" para valores abaixo de 50%, mostrando também a umidade atual.

<h2 id='Componentes'>📖Componentes</h2>
<ul>
  <li>Arduino UNO R3;</li>
  <li>Sensor DHT11 (para medição de temperatura e umidade);</li>
  <li>Sensor de Luminosidade (LDR);</li>
  <li>LEDs Verde, Amarelo e Vermelho;</li>
  <li>Resistores (para limitar a corrente dos LEDs);</li>
  <li>Buzzer (para alerta sonoro);</li>
  <li>Display LCD (16x2);</li>
</ul>

<h2 id="Instalacao">Instalação</h2>
<ol>
  <li>Monte o circuito conforme a imagem contida mais abaixo;</li>
  <li>Conecte o sensor LDR e os outros componentes ao Arduino de acordo com o esquema elétrico;</li>
  <li>Carregue o código fonte para o seu Arduino utilizando a IDE do Arduino;</li>
  <li>Conecte os LEDs e o buzzer ao circuito, garantindo a polaridade correta.</li>
</ol>

<p align = "center">
<img loading="lazy" width="500px" src = 'https://github.com/gvqsilva/CP2-Edge/assets/110639916/f7841a85-f2c5-46fb-a82b-78d6cae4ef17'/>
</p>
<p align = "center">
Figura 1 - Esquema da montagem
</p>

<h2 id="Como usar">Como Usar:</h2>
<ol>
  <li>Ligue o sistema;</li>
  <li>O sensor LDR irá detectar a luminosidade ambiente, enquanto o DHT11 monitora ascondições de temperatura e umidade;</li>
  <li>Com base nas leituras dos sensores, o Arduino acionará os LEDs verde, amarelo ou vermelho conforme o estado de luminosidade, umidade ou temperatura;</li>
  <li>Observe as mensagens no Display LCD conforme as condições do ambiente;</li>
  <li>Se níveis críticos forem detectados, o buzzer será acionado por 3 segundos para alertar sobre a condição;</li>
  <li>Monitore a temperatura, umidade e luminosidade exibidas no Display LCD.</li>
</ol>

<h2 id="Beneficios">Benefícios</h2>
<ul>
  <li><strong>Versatilidade:</strong> O sistema pode ser adaptado para monitorar diferentes variáveis e ser implementado em diversos ambientes, desde residências até espaços industriais </li>
  <li><strong>Consciência do abiente:</strong> Ao fornecer informações detalhadas sobre as condições da sala, o projeto promove a preservação do vinho;</li>
  <li><strong>Customização:</strong> O usuário podem personalizar o display de acordo com seu gosto, mudando as mensagens, etc.</li>
  <li><strong>Integração com Sistemas de Segurança:</strong> Integra o sistema de monitoramento da adega com sistemas de segurança, como alarmes sonoros. Isso ajudaria a garantir a segurança dos vinhos</li>
  <li><strong>Sistema de Iluminação Controlada:</strong> Desenvolva um sistema de iluminação controlada que ajusta automaticamente a intensidade e o espectro da luz dentro da adega. Isso pode ser especialmente útil para garantir que as garrafas de vinho não sejam expostas à luz ultravioleta, que pode deteriorar a qualidade do vinho ao longo do tempo.</li>
</ul>



  
<h2 id="Codigo do programa">Código do programa:</h2>

https://github.com/gvqsilva/CP2-Edge/blob/main/codigo-cp2-edge.ino.ino

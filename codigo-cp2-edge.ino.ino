#include <dht.h>  // Carrega a biblioteca dht
#include <LiquidCrystal.h>

/*
  Frequência das notas:
  Dó - 262 Hz
  Ré - 294 Hz
  Mi - 330 Hz
  Fá - 349 Hz
  Sol - 392 Hz
  Lá - 440 Hz
  Si - 494 Hz
  #Dó - 528 Hz
  */

//byte dos emojis
byte triste[8] = {  B00000, B10001,  B00000,  B00000,  B01110,  B10001,  B00000,};
byte sorriso[8] = {  B00000,  B10001,  B00000,  B00000,  B10001,  B01110,  B00000,};
byte serio[8] = { B00000, B10001, B00000, B00000, B11111,  B00000,  B00000,};


//byte da logo
byte logo1[] = { B11111, B01111, B00111, B00111, B00011, B00001, B00001, B00000 };
byte logo2[] = { B11111, B11111, B11111, B11111, B11111, B11111, B11110, B11100 };
byte logo3[] = { B11111, B11111, B11111, B11111, B10111, B00111, B01111, B11111 };

byte logo4[] = { B00000, B10000, B11000, B11100, B11110, B11111, B11111, B11111 };
byte logo5[] = { B01000, B00001, B00001, B00011, B00111, B01111, B11111, B11111 };
byte logo6[] = { B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 };

int ledverde = 11;    //Declaração do led verde na porta 11
int ledamarelo = 10;  //Declaração do led amarelo na porta 10
int ledvermelho = 9;  //Declaração do led verde na porta 09
float LDR = A0;     //Declaração do LDR na porta 0
int valorLDR = 0;     //Valor inicial do LDR
int buzzer = 5;     //Declaração do buzzer
int tempo = 528;    //Nota que irá tocar no buzzer
int intluz;

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(13, 12, 8, 7, 6, 4, 3);
 
dht DHT; // Cria um objeto da classe dht
uint32_t timer = 0;
 
void setup()
{
  Serial.begin(9600); // Inicializa serial com taxa de transmissão de 9600 bauds
  lcd.begin(16, 2); // Define o display com 16 colunas e 2 linhas
  lcd.clear(); // limpa a tela do display

  //Declarando a logo - parte de cima
  lcd.createChar(1, logo1);
  lcd.createChar(2, logo2);
  lcd.createChar(3, logo3);
  
  //Declarando a logo - parte de baixo
  lcd.createChar(4, logo4);
  lcd.createChar(5, logo5);
  lcd.createChar(6, logo6);
  
  pinMode(ledverde , OUTPUT);   //Fixando variavel/port de saída
  pinMode(ledamarelo , OUTPUT); //Fixando variavel/port de saída
  pinMode(ledvermelho , OUTPUT);  //Fixando variavel/port de saída
  pinMode(LDR , INPUT);     //Fixando variavel/port de entrada
  pinMode(buzzer, OUTPUT);    //Fixando variavel/port de saída

//Exibe a logo no display
  lcd.display();
  lcd.setCursor(2, 0);  
  lcd.write(byte(1));
  lcd.setCursor(3, 0);  
  lcd.write(byte(2));
  lcd.setCursor(4, 0);  
  lcd.write(byte(3));
  lcd.setCursor(2, 1);  
  lcd.write(byte(4));
  lcd.setCursor(3, 1);  
  lcd.write(byte(5));
  lcd.setCursor(4, 1);  
  lcd.write(byte(6));
  lcd.print("G4 Tech");
  delay(3000);
  lcd.clear();

//Declarando os emojis
  lcd.createChar(0, triste);
  lcd.createChar(1, sorriso);
  lcd.createChar(2, serio);
}
 
void loop() {

// Exibir logo

  //TEMPERATURA
  //TEMPERATURA OK
  if (DHT.temperature >= 10 && DHT.temperature <= 15){           //Verifica valor LDR se menor que 100
    lcd.setCursor(0,0);         // Define o cursor na posição de início
    lcd.print("Temperatura OK");
    lcd.setCursor(0,1);
    lcd.print(DHT.temperature,1);
    lcd.write(B11011111);       // Imprime o símbolo de grau
    lcd.print("C");
    lcd.setCursor(12, 1);  
    lcd.write(byte(1));
    noTone(buzzer);
    delay(2500);
  }

  //TEMPERATURA BAIXA
  if(DHT.temperature < 10){
    lcd.setCursor(0,0);         // Define o cursor na posição de início
    lcd.print("Temp. Baixa");
    lcd.setCursor(0,1);
    lcd.print(DHT.temperature,1);
    lcd.write(B11011111);       // Imprime o símbolo de grau
    lcd.print("C");
    lcd.setCursor(12, 1);  
    lcd.write(byte(0));
    digitalWrite(ledamarelo, HIGH);     //Acende o led amarelo
    digitalWrite(ledverde, LOW);     //Acende o led amarelo   
    tone(buzzer,tempo);     //Liga/toca o buzzer
    delay(2500);
  }

  //TEMPERATURA ALTA
  if(DHT.temperature > 15){
    lcd.setCursor(0,0);
    lcd.print("Temp. Alta");
    lcd.setCursor(0,1);
    lcd.print(DHT.temperature,1);
    lcd.write(B11011111);       // Imprime o símbolo de grau
    lcd.print("C");
    lcd.setCursor(12, 1);  
    lcd.write(byte(0));
    digitalWrite(ledamarelo, HIGH);     //Acende o led amarelo
    digitalWrite(ledverde, LOW);     //Acende o led amarelo   
    tone(buzzer,tempo);     //Liga/toca o buzzer
    delay(2500);
  }

  //UMIDADE
  //UMIDADE OK
  if (DHT.humidity >= 50 && DHT.humidity <= 70){
    lcd.clear();
    lcd.setCursor(0,0);         // Define o cursor na posição de início
    lcd.print("Umidade OK");
    lcd.setCursor(0,1);
    lcd.print(DHT.humidity,1);
    lcd.print("%");
    lcd.setCursor(12, 1);  
    lcd.write(byte(1));
    noTone(buzzer);
    delay(2500);
  }
  
  //UMIDADE ALTA
  if (DHT.humidity > 70){
    lcd.clear();
    lcd.setCursor(0,0);         // Define o cursor na posição de início
    lcd.print("Umidade Alta");
    lcd.setCursor(0,1);
    lcd.print(DHT.humidity,1);
    lcd.print("%");
    lcd.setCursor(12, 1);  
    lcd.write(byte(0));
    digitalWrite(ledvermelho, HIGH);     //Acende o led amarelo
    digitalWrite(ledverde, LOW);     //Acende o led amarelo   
    tone(buzzer,tempo);     //Liga/toca o buzzer
    delay(2500);
  }        

  //UMIDADE BAIXA
  if (DHT.humidity <50 ){
    lcd.clear();
    lcd.setCursor(0,0);         // Define o cursor na posição de início
    lcd.print("Umidade Baixa  ");
    lcd.setCursor(0,1);
    lcd.print(DHT.humidity,1);
    lcd.print("%");
    lcd.setCursor(12, 1);  
    lcd.write(byte(0));
    digitalWrite(ledvermelho, HIGH);     //Acende o led amarelo
    digitalWrite(ledverde, LOW);     //Acende o led amarelo   
    tone(buzzer,tempo);     //Liga/toca o buzzer
    delay(2500);
  }        


  //LED'S
  
  valorLDR = analogRead(LDR);     //Especificando a leitura analogica para LDR
  intluz = map(valorLDR, 259, 969, 0, 100);   //Numerando a intensidade de luz
  Serial.print("Intensidade de Luz 0 - 1023 = "); //Valores no Monitor Serial
  Serial.println(valorLDR);     //valorLDR no Monitor Serial
  Serial.print("Intensidade de Luz 0 - 100% = "); //Porcentagem no Monitor Serial
  Serial.println(intluz);     //intluz no Monitor Serial
  delay(1000);        //tempo de 1 segundo
 
  //Luminosidade Baixa
  
  if (intluz < 30){      //Verifica valor LDR se menor que 100
    lcd.clear();
    digitalWrite(ledvermelho, LOW);                //Apagamento de leds
    digitalWrite(ledamarelo, LOW);          //Apagamento de leds
    digitalWrite(ledverde, HIGH); //Acende apenas o led verde
    noTone(buzzer);       //Não liga/toca o buzzer
    lcd.print("Ambiente OK");
    lcd.setCursor(12, 1);  
    lcd.write(byte(1));
    delay(2500);
  }
  
  //Luminosidade Media
  
  if (intluz >= 31 && intluz <= 90 ){  //Verifica valor LDR se maior/igual que 100 e menor que 150
    digitalWrite(ledverde, LOW);
    digitalWrite(ledvermelho, LOW);                //Apagamento de leds
    digitalWrite(ledamarelo, HIGH);     //Acende apenas o led amarelo
    noTone(buzzer);               //Não liga/toca o buzzer
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ambiente a meia");
    lcd.setCursor(0,1);
    lcd.print("luz");
    lcd.setCursor(12, 1);  
    lcd.write(byte(2));
    delay(2500);    
  }
  
  //Luminosidade Alta
  
  if (intluz > 91){        //Verifica valor LDR se maior que 150
    digitalWrite(ledverde, LOW);
    digitalWrite(ledamarelo, LOW);          //Apagamento de leds
    digitalWrite(ledvermelho, HIGH);  //Acende apenas o led vermelho
    delay(2000);            //Buzzer é ativado de 5 em 5 segundo
    tone(buzzer,tempo);     //Liga/toca o buzzer
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ambiente muito");
    lcd.setCursor(0,1);
    lcd.print("claro");
    lcd.setCursor(12, 1);  
    lcd.write(byte(0));
    delay(2500);    
  }  
  
  Serial.print(valorLDR);   //Impressão do valor LDR


  
  // Executa 1 vez a cada 5 segundos
  if(millis() - timer>= 5000){

    // chama método de leitura da classe dht conectado no pino A1      
    //DHT.read11(A1); // uso do sensor DHT11
    DHT.read22(A1);   // uso do sensor DHT22            
     
    // Exibe na serial o valor da temperatura
    Serial.print("Temperatura = ");
    Serial.print(DHT.temperature,1); 
    Serial.print("°C           ");
    
    // Exibe na serial o valor de umidade
    Serial.print("Umidade = ");
    Serial.print(DHT.humidity,1);
    Serial.println(" %  ");

    timer = millis(); // Atualiza a referência

  }
}
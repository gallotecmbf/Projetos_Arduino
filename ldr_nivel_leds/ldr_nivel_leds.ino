/* Autor: Márcio Bortoletto Fessel

Projeto utilizando sensor de LDR para 3 níveis de intensidade de luz.

Código baseado nos exemplos disponíveis na plataforma
do arduíno
https://www.arduino.cc/reference/pt/language/structure/control-structure/else/
https://projecthub.arduino.cc/SURYATEJA/arduino-light-senser-using-ldr-ce214a
*/
// C++ code
//
int VERMELHO = 8; //define uma variável com nome vermelho para a porta digital 8

int AMARELO = 9; //define uma variável com nome amarelo para a porta digital 9

int VERDE = 10; //define uma variável com nome verde para a porta digital 10

int LDR = A0; //define a variável LDR para a porta analógia zero

/*define a variável VLR_LDR que será utilizada para exibir
os valores lidos pela variável LDR no código iniciando
com o valor de zero */
int VLR_LDR =0;

void setup()
{
/* estabelece os pinos das variáveis como 
saída - envia 5 voltz para o circuito 
quando estiver em alta para cada uma
das variáveis direcionadas aos LEDS*/
  pinMode(VERMELHO ,OUTPUT); 
  pinMode(AMARELO ,OUTPUT); 
  pinMode(VERDE ,OUTPUT); 

/* configura a variável LDR como sistema
 de entrada de informações para ser lida
 as tensões/voltagem entre o LDR e o 
 resistor do circuito montado */
  pinMode(LDR, INPUT);   

/* Comando que permite/inicia o envio de 
informações do arduino para o computador
por meio de uma porta de comunicação do
tipo serial (dados em série) 
OBS: PARA USAR ESTE COMANDO OS 
PINOS/PORTAS 0 E 1 NÃO PODEM ESTAR COM
QUALQUER FUNÇÃO NO ARDUÍNO!*/
  Serial.begin(9600);

   }

void loop()
{

/*define que o valor de leitura da tensão
lida pela variável LDR (porta A0) será 
transferido para a variável VLR_LDR */  
 VLR_LDR=analogRead(LDR); 

 /*Condição para que, de acordo com o valor obtido
 pela variável VLR_LDR, execute ações específicas
 no circuito elétrico*/
 if (VLR_LDR<=250){
  digitalWrite(VERMELHO, HIGH); //define o led vermelho LIGADO
  digitalWrite(AMARELO, LOW);//define o led amarelo DESLIGADO
  digitalWrite(VERDE, LOW);//define o led verde DESLIGADO

  /*Escreve no monitor serial (leitor das informações) vindas 
  do circuito do arduino para o software do arduino*/
    Serial.print("Luz BAIXA - "); // se a condição for verdadeira, escreve o texto entre aspas
    Serial.println(VLR_LDR); // escreve o valor escrito (printado) na variável VLR_LDR
 }
/*Nova condição (condição secundária) para nova ação dentro da condição primária
agora para uma faixa intermediária de valores */
else if (250<VLR_LDR && VLR_LDR<=950){

  digitalWrite(VERMELHO, LOW); //define o led vermelho DESLIGADO
  digitalWrite(AMARELO, HIGH);//define o led amarelo LIGADO
  digitalWrite(VERDE, LOW);//define o led verde DESLIGADO

  /*Escreve no monitor serial (leitor das informações) vindas 
  do circuito do arduino para o software do arduino*/
    Serial.print("Luz MÉDIA - "); // se a condição for verdadeira, escreve o texto entre aspas
    Serial.println(VLR_LDR); // escreve o valor escrito (printado) na variável VLR_LDR

 
 }

else {
/* Caso nenhuma das condições anteriores sejam satisfeitas, executa
esta terceira condição */
  digitalWrite(VERMELHO, LOW); //define o led vermelho DESLIGADO
  digitalWrite(AMARELO, LOW);//define o led amarelo DESLIGADO
  digitalWrite(VERDE, HIGH);//define o led verde LIGADO

  /*Escreve no monitor serial (leitor das informações) vindas 
  do circuito do arduino para o software do arduino*/
    Serial.print("Luz ALTA - "); // se a condição for verdadeira, escreve o texto entre aspas
    Serial.println(VLR_LDR); // escreve o valor escrito (printado) na variável VLR_LDR

 
 }
}


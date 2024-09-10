/* Antes das funções de configuração (void setup) e de rotina
(void loop) é possível dar nomes para as portas do arduino
com o intuíto de facilitar a programação, deixando elas mais
amigável e de fácil compreensão sobre o que e como está
funcionando cada item da programação como os leds e demais
componentes conectados nas portas do arduino 
Em muitos casos também é utilizado para configurar
inicialmente variáveis (nomes que armazenarão informações)
para serem utilizadas como coleta e armazenamento de dados */

int LVerde = 4; // define a porta 4 para o LED VERDE
int LVermelho = 3; // define a porta 3 para o LED VERMELHO
int trig = 6; // define a porta 6 para o EMISSOR DE SOM
int echo = 5; // define a porta 4 para o RECEPTOR DE SOM


/*Esta seção da programação (void setup) é responsável por 
configurar todo o arduino e as portas para enviar ou 
receber sinal e energia (no caso dos sensores de recepção)
ou enviar sinal/energia para para os mais variados 
componentes elétricos/eletrônicos (leds, altofalantes, etc)*/
void setup()
{
  pinMode(LVermelho, OUTPUT); //Faz com que o led VERMELHO possa
                              //receber energia
  
  pinMode(LVerde, OUTPUT);//Faz com que o led VERDE possa
                              //receber energia
  
  pinMode(trig, OUTPUT); //Faz com que o ALTO FALANTE DE EMISSÃO
                         // (O TRIG) possa ENVIAR SINAL/energia
 
  pinMode(echo, INPUT); //Faz com que o ALTO FALANTE DE RECEPÇÃO
                         // (O ECHO) possa receber SINAL/energia
  
  
}

void loop()
{
  digitalWrite(trig, LOW); // Desativa o trig para emissão de sinal

  delayMicroseconds(2); // Espera por 2 micro segundos
  
  digitalWrite(trig, HIGH); // ativa o trig para emissão de sinal
  
  delayMicroseconds(10); // Espera por 2 micro segundos
  
  digitalWrite(trig, LOW); // Desativa o trig para emissão de sinal
  
  //Cria uma variável estilo long (para valores muito extensos
  //com nome de duração para receber o sinal enviado pelo trig
  long duracao = pulseIn(echo, HIGH);
  
  /*Cria uma variável estilo inteira (apenas números 
  inteiros - sem casas decimais convertendo o valor da duração como um valor
  de medida de distância, por esta razão o valor da variável 
  duracao deve ser dividido por 2. 
  Como a velocidade do som no ar à 20ºC é de aproximadamente
  340 m/s, temos que a distância é calculada como
  distância = (velocidade do som no ar)*(tempo de propagação)
  Com isto em mente, devemos utilizar a padronização para o
  resultado em centímetros dividindo-se o valor do 
  tempo dividido por 2 (uma vez que o som emitido foi e voltou)
  sendo este resultado multiplicado por 0,0343 ou divindo 
  por 29.1 (que é o resultado de 1 divido por 0,0343)
  padronizando a unidade medida em um valor em centímetros.*/
  int distancia = (duracao/2)/29.1;
  
  
  //estabelece um parâmetro de comparação para que execute uma ação
  //a partir de uma distância específica conforme coleta de
  //informação recebida no echo.
  //o valor 25 corresponde à 25cm de distância
  if (distancia<=25 ) {
  
//ação à ser realizada se a distância for menor que 25cm
    digitalWrite(LVermelho, HIGH); //acende o led vermelho
    digitalWrite(LVerde, LOW); //apaga o led verde
  
  } else { //o comando else (senão) realiza uma ação caso
    //o objeto esteja em uma distância diferente da condição
    //desejada
    
    
    digitalWrite(LVermelho, LOW); //acende o led vermelho
    digitalWrite(LVerde, HIGH); //apaga o led verde
 
  }
  
  delay(500); //estabelece um tempo de 500 milisegundos (meio segundo)
              //para iniciar novamente a rotina programada no loop
              //e desta maneira fazer medições constantemente.
  
}
  
  
 
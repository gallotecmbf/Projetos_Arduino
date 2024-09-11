// C++ code
//

int LDR=A0;
int Valor=0;
int LED=8;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT);

  Serial.begin(9600);
}

void loop()
{
  Valor=analogRead(LDR);

  if (Valor > 600){
  
  digitalWrite(LED, LOW);
  Serial.println(Valor);
  
  } else {
   
    digitalWrite(LED,HIGH);
      Serial.println(Valor);

  }
}
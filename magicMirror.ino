
int sensorLuz = A0;
float valorLuz = 0;

int Trigger = 3;
int Echo = 2;
float tiempo = 0;
float distancia = 0;

int led = 13;

int ledAzul = 11;
int intensidadLed = 0;

int rele = 12;

String toString= "";
String dato = "";

void setup () {
  Serial.begin(9600);
  
  //Sensor de luz
  pinMode (sensorLuz,INPUT);

  //Sensor untrasonido
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada

  //Salidas
  pinMode(led , OUTPUT);
  pinMode(ledAzul , OUTPUT);
  pinMode(rele, OUTPUT);
}

void loop () {
  valorLuz = analogRead(sensorLuz);
  valorLuz = map(valorLuz, 10, 920, 0, 1023);
  valorLuz = (valorLuz/1023)*100;
  
  intensidadLed = map(valorLuz,0,100,255,0);
  analogWrite(ledAzul, intensidadLed);

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  tiempo = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  distancia = tiempo/59.0; 

  toString = "valor de luz,"+String(valorLuz)+", valor de distancia: ,"+String(distancia);

   Serial.println(toString);

  if (distancia >= 5){
    digitalWrite(rele,LOW);
  }else {
    digitalWrite(rele,HIGH);
  }


  if (Serial.available()>0){
    int dato = Serial.read();
    if (dato == "1"){
      digitalWrite(led,HIGH);
    }else if (dato == "0"){
      digitalWrite(led,LOW);
    }
  }
 
  delay(1000);
}

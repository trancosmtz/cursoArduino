int lrojo = 53;
int lverde = 52;
int in2 = 6;
int in7 = 7;
int proxi = A15;
int poten = A13;
int sluz = A14;
int disponible = 1;
int ilum = 0;
int boton=49;
int pwm1, pwm2, encendido;


void setup() {
  pinMode(proxi,INPUT);
  pinMode(sluz,INPUT);
  pinMode(poten,INPUT);
  pinMode(lrojo,OUTPUT);
  pinMode(lverde,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in7,OUTPUT);
  pinMode(boton,INPUT);
  Serial.begin(9600);
}

void loop() {
  int proxiSense = analogRead(proxi);
  int brillo = map(analogRead(sluz),500,1023,0,100);
  if(proxiSense<=500)
    ocupado();
  else if(proxiSense>500)
    libre();
  if(brillo<=50){
    ilum=0;
  }else if(brillo>50){
    ilum=1;
  }
  if(ilum==1)
    prender();
  else if(ilum==0)
    apagar();
  if(encendido==1||digitalRead(boton)==1){
    pwm1 = map(analogRead(poten), 0, 1023, 0, 255);
    pwm2 = map(analogRead(poten), 0, 1023, 255, 0);
    analogWrite(in2,pwm2);
    analogWrite(in7,pwm1);
  }else if(encendido==0){
    analogWrite(in2,0);
    analogWrite(in7,0);
  }
  Serial.println(digitalRead(boton));
  delay(1);
}

void ocupado(){
  analogWrite(lrojo,HIGH);
  analogWrite(lverde,LOW);
  disponible = 0;
}

void libre(){
  analogWrite(lrojo,LOW);
  analogWrite(lverde,HIGH);
  disponible = 1;
}

void prender(){
  encendido=1;
}
void apagar(){
  encendido=0;
}


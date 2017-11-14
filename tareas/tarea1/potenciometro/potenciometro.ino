int led =2;  
int pot =1;
int brillo;  

void setup ()  {
  pinMode (led, OUTPUT); 
}

void loop (){
  brillo = analogRead (pot) / 4; 
  analogWrite(led, brillo);
}

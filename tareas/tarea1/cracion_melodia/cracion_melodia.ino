int pinzumbador = 8;    //se declara el pin 
int fr0 = 220;      // frecuencia correspondiente a la nota deseada sabiendo la frecuenca de cada nota
int fr1 = 409;

void setup()
{
}

void loop()
{
    tone(pinzumbador,fr0);    // inicia el zumbido, con la frecuencia declarada arriba
    delay(2000);    
tone(pinzumbador,fr1);    // inicia el zumbido, con la frecuencia declarada arriba
    delay(2000);    
    noTone(pinzumbador);               // lo detiene a los dos segundos
    delay(1000);
}
/*sabiendo las frecuencias de las notas y los tiempos de la melodia, se puede generar cualquier melida*/

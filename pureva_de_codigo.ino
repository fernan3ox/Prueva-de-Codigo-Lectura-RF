
int pwma=11;
int pwmb=6;
int ma1=7;
int ma2=8;
int mb1=9;
int mb2=10;

int prom=0;
//Variables
int lectura_linea_izq=0;
int lectura_linea_der=0;
int lectura_linea_atr=0;

int A=16;
int B=17;
int C=18;
int D=19;


void setup() {

  pinMode(pwma,OUTPUT);
  pinMode(pwmb,OUTPUT);
  pinMode(ma1,OUTPUT);
  pinMode(ma2,OUTPUT);
  pinMode(mb1,OUTPUT);
  pinMode(mb2,OUTPUT);
  pinMode(A,INPUT);
  pinMode(B,INPUT);
  pinMode(C,INPUT);
  pinMode(D,INPUT);

  
Serial.begin(9600);
}

void loop() {
int valor1;
int valor2;

medir();

valor1=digitalRead(A);
valor2=digitalRead(B);

prom = promedio();
if (prom < 200 && prom >100)
{
  
  if (valor1==HIGH){

    izquierda(10);
    delay(1000);
    
    adelante(150);
    delay(1000);
  
  
  }
if(valor2==LOW){
  
  
  adelante(150);
  delay(1000);
  
  
  
  
  
  }
    
  
}
else {

 detener();
 
  

  
  }







 
}

void adelante(int val){
digitalWrite(ma1,HIGH);
digitalWrite(ma2,LOW);
analogWrite(pwma, val);
digitalWrite(mb1,HIGH);
digitalWrite(mb2,LOW);
analogWrite(pwmb, val);
}
void derecha(int val){
digitalWrite(ma1,LOW);
digitalWrite(ma2,HIGH);
analogWrite(pwma, val);
digitalWrite(mb1,HIGH);
digitalWrite(mb2,LOW);
analogWrite(pwmb, val);
}
void izquierda(int val){
digitalWrite(ma1,HIGH);
digitalWrite(ma2,LOW);
analogWrite(pwma, val);
digitalWrite(mb1,LOW);
digitalWrite(mb2,HIGH);
analogWrite(pwmb, val);
}
void reversa(int val){
digitalWrite(ma1,LOW);
digitalWrite(ma2,HIGH);
analogWrite(pwma, val);
digitalWrite(mb1,LOW);
digitalWrite(mb2,HIGH);
analogWrite(pwmb, val);
}
void detener(){
digitalWrite(ma1,LOW);
digitalWrite(ma2,LOW);
digitalWrite(mb1,LOW);
digitalWrite(mb2,LOW);
}


void medir(){


lectura_linea_izq = analogRead(A7);
lectura_linea_der = analogRead(A1);
lectura_linea_atr = analogRead(A0);



}


int promedio(){

int promedio=0;
int lectura_linea_1;
int lectura_linea_2;
int lectura_linea_3;
lectura_linea_1 = analogRead(A0);
lectura_linea_2 = analogRead(A1);
lectura_linea_3 = analogRead(A7);

promedio = (lectura_linea_1 + lectura_linea_2 + lectura_linea_3)/3;

return (promedio);

}

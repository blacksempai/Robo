const int leftSpeed = 5;
const int rightSpeed = 10;
int a=40;

void forward()
{

    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
}



void right()
{

    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
}



void left()
{

    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
}

//@Deprecated
void carSpeed(int s)
{
  analogWrite(leftSpeed, s);
  analogWrite(rightSpeed, s);
}


void setup()
{ 
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(leftSpeed, OUTPUT);
  pinMode(rightSpeed, OUTPUT);
 // Serial.begin(9600);
}
int PA1,PA2,PA3,PA4,PA0;
void loop()
{
  if(analogRead(A0) < 100)   PA0 = 1; else  PA0 = 0;
  if(analogRead(A1) < 100)   PA1 = 1; else  PA1 = 0;
  if(analogRead(A2) < 100)   PA2 = 1; else  PA2 = 0;
  if(analogRead(A3) < 100)   PA3 = 1; else  PA3 = 0;
  if(analogRead(A4) < 100)   PA4 = 1; else  PA4 = 0;
  
//DEBUG
//Serial.println(PA0);
//Serial.println(PA1);
//Serial.println(PA2);
//Serial.println(PA3);
//Serial.println(PA4);
//Serial.println();
  

  if(PA2) {forward();carSpeed(150);}
  if(PA2 and PA1 ) {forward();carSpeed(150);}
  if(PA2 and PA3 ) {forward();carSpeed(150);}
  if(PA2 and PA1 and PD3 ) {forward();carSpeed(150);}
  if(PA1 or PA0) {left();carSpeed(50);}
  if(PA3 or PA4) {right(); carSpeed(50);}
    if(PA1 and PA0) {left();carSpeed(50);}
  if(PA3 and PA4) {right(); carSpeed(50);}

  
  
  
}

const int leftSpeed = 5;
const int rightSpeed = 10;
const int FRONT_LEFT_EYE = A3;
const int FRONT_RIGHT_EYE = A6;
const int SIDE_LEFT_EYE = A7;
const int SIDE_RIGHT_EYE = A2;

const int DOWN_LEFT_F = A0;
const int DOWN_RIGHT_F = A1;

void left()
{
    analogWrite(leftSpeed, 250);
    analogWrite(rightSpeed, 250);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
}

void right()
{
    analogWrite(leftSpeed, 250);
    analogWrite(rightSpeed, 250);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
}

void forward()
{
    analogWrite(leftSpeed, 50);
    analogWrite(rightSpeed, 50);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
}

void fastForward()
{
    analogWrite(leftSpeed, 200);
    analogWrite(rightSpeed, 200);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
}

void backward()
{
    analogWrite(leftSpeed, 100);
    analogWrite(rightSpeed, 100);
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
  Serial.begin(9600);
}
long unsigned int timer = 0;
void loop()
{
  boolean isRightWhite = analogRead(DOWN_LEFT_F) > 100 ? true : false;
  boolean isLeftWhite = analogRead(DOWN_RIGHT_F) > 100 ? true : false;  ]
  boolean isCarOnLeft = analogRead(SIDE_LEFT_EYE) > 400 ? true : false;
  boolean isCarOnRight = analogRead(SIDE_RIGHT_EYE) > 400 ? true : false;
  boolean isCarOnFrontL = analogRead(FRONT_LEFT_EYE) > 400 ? true : false;
  boolean isCarOnFrontR = analogRead(FRONT_RIGHT_EYE) > 400 ? true : false;
   
  if((isLeftWhite || isRightWhite)) {
    backward();
    delay(350);
    right();
    delay(250);
  }
  if(isCarOnLeft){
    do left();
    while(!(isCarOnFrontL ||  (millis() - timer) > 500));
    timer = millis();
  }
    if(isCarOnRight){
    do right();
    while(!(isCarOnFrontR ||  (millis() - timer) > 500));
    timer = millis();
  }
  if(isCarOnFrontL || isCarOnFrontR){
    fastForward();
  }
  else{
    forward();
  } 
}

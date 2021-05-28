
int speed_l = 5;
int speed_r = 10;

void setup() {
  Serial.begin(9600);
  for(int i=7;i<=9;i++){
    pinMode(i, OUTPUT);
  }
  
}

void speed_car(int a){
  analogWrite(speed_l, a);
  analogWrite(speed_r, a);
}
void forward(){
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 0);
}

void stop_car(){
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
}

void right(){
  digitalWrite(6, 0);
  digitalWrite(7, 1);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
}

void left(){
  digitalWrite(6, 1);
  digitalWrite(7, 0);
  digitalWrite(8, 1);
  digitalWrite(9, 0);
}



void loop() {
 if(Serial.available()){
  int a=Serial.read();
  if(a==49) //1 go
  {
    forward();
    speed_car(70);
  }

  if(a==50) //2 low speed
  {
    forward();
    speed_car(30);
  }
  if(a==3) //3 stop
  {
    stop_car();
  }
 }
}


#define trigpin D1      // Ultrasonic sensor trig pin
#define echopin D2      // Ultrasonic sensor echo pin
#define motor_pin D5     // Relay control pin for water pump
#define led D6    // Buzzer pin
#define buzzer D7
// const int trigpin = D1;
// const int echopin = D2;
// const int motor_pin = D5;
// const int 
long duration;
long distance;

bool motor;
bool automatic_mode = true;
bool manual_mode =false;


void setup(){
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(motor_pin,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);


}

void loop(){


  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);

  duration = pulseIn(echopin,HIGH);
  distance = duration * 0.034/2;
  int level = map(distance,0,100, 0,100);
  Serial.println(level);
  int motor_chalu=0;

  if(distance < 30){
    motor = true;
    // digitalWrite(led,HIGH);
  }
  if(distance >=100){
    motor = false;
    // digitalWrite(led,LOW);
  }

  if(motor){

    digitalWrite(motor_pin,HIGH);
    motor_chalu=0;
    digitalWrite(led,LOW);



  }

  else{
    digitalWrite(motor_pin,LOW);
    motor_chalu=1;
    digitalWrite(led,HIGH);

  }
  if(motor_chalu==1 && distance<35)
  {
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
  }

delay(1000);
}

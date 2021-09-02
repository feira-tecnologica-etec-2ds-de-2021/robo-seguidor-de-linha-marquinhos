//sensor HCSR-04
const byte HRSR04_trig_pin = 7;
const byte HRSR04_echo_pin = 6;
float distancia;
//Motor DC
int IN1 = 5; //roxo
int IN2 = 4; //cinza
int IN3 = 3; //azul
int IN4 = 2; //amarelo

float ultrassonicDistancy;

void setup(){
    //sensor HCSR-04
    pinMode(HRSR04_trig_pin, OUTPUT);
    pinMode(HRSR04_echo_pin, INPUT);
    
    //Motor DC
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

void loop(){
   //sensor HCSR-04
   //distancia = getUltrassonicDistance(); 
  
   //Motor DC
   //motor A = preto e branco
   //motor B = verde e cinza
   
   //Gira o Motor A no sentido horario
   digitalWrite(IN1, HIGH);
   delay(2000);
   digitalWrite(IN2, LOW);
   
   
   //Gira o Motor B no sentido horario
   digitalWrite(IN3, HIGH);
   delay(2000);
   digitalWrite(IN4, LOW);

 
}

//Sensor HCSR-04 código
float getUltrassonicDistance(){
  digitalWrite(HRSR04_trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(HRSR04_trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(HRSR04_trig_pin, LOW);
  float timeEcho = pulseIn(HRSR04_echo_pin, HIGH);
  float distancy = (timeEcho * 340.90) / 2;
  float distancyInCentimeters = distancy / 10000;
  Serial.begin(9600);
  Serial.print("Distancia em cm: ");
  Serial.println(distancia);
  delay(500);

  return distancyInCentimeters;
}

//Motor DC 3 A 6V código
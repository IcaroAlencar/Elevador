#define TRIG 4 // D2 pino trig
#define ECHO 5 // D1 pino echo
#define SOUND_SPEED 0.035 // cm/us
#define D5 14 // Sobe



long duration;
float distanceCm, distanceCmAnt;
int velocidade,j, tempo;

void setup() {
  Serial.begin(115200);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  velocidade = 150;
  j = 0;
  tempo = 0;
  distanceCmAnt = 0;
}

void loop() {
  //limpando a TRIG
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  //pulso de 10us
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  //buscando distancia
  duration = pulseIn(ECHO, HIGH);

  distanceCm = duration*SOUND_SPEED/2;
  Serial.print("Distance: ");
  Serial.println(distanceCm);

  // está em baixo, precisa subir
  if(distanceCm < 40 || distanceCm > 1000){

    if((distanceCm - distanceCmAnt) > 5){
      velocidade--;
    }else{
      velocidade++;
    }

    if(velocidade <= 255){
      analogWrite(D5,velocidade);
      Serial.print("velocidade: ");
      Serial.println(velocidade);
    }

  }
  delay(50);


  distanceCmAnt = distanceCm;
  
}

// RC
#define ch1 13
#define ch2 12

// Motor A
#define in1 7
#define in2 6

// Motor B
#define in3 5
#define in4 4

void setup() {
  Serial.begin(9600);

  //RC
  pinMode(ch1, INPUT);
  pinMode(ch2, INPUT);

  //DC A
  //pinMode(ena, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  //DC B
  //pinMode(enb, INPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

long x, y;

int velocidade = 10;

void loop() {
  x = pulseIn(ch1, HIGH);
  y = pulseIn(ch2, HIGH);

  Serial.print("x=");
  Serial.print(x);
  Serial.print(" y=");
  Serial.println(y);

  if (y < 1450) {
    paraTras();
    Serial.println("Para trás.");

  } else if (y > 1550) {
    paraFrente();
    Serial.println("Para frente.");
  }

  if (x < 1400) {
    vireEsquerda();
    Serial.println("Para esquerda.");

  } else if (x > 1550) {
    vireDiretira();
    Serial.println("Para direita.");
  }

  if ((y >= 1450 && y <= 1550) && (x >= 1400 && x <= 1550)) {
    pare();
    Serial.println("Parado.");
  }

  //delay(1000);
}

void paraTras() {
  // Motor A para trás
  digitalWrite(in1, LOW);
  digitalWrite(in2, velocidade);  //digitalWrite(in2, HIGH);
  // Motor B para trás
  digitalWrite(in3, LOW);
  digitalWrite(in4, velocidade);  //digitalWrite(in4, HIGH);
}

void paraFrente() {
  // Motor A para frente
  digitalWrite(in1, velocidade);  //digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // Motor B para frente
  digitalWrite(in3, velocidade);  //digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void vireEsquerda() {
  // Motor A frente
  digitalWrite(in1, velocidade);  //digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // Motor B trás
  digitalWrite(in3, LOW);
  digitalWrite(in4, velocidade);  //digitalWrite(in4, HIGH);
}

void vireDiretira() {
  // Motor A trás
  digitalWrite(in1, LOW);
  digitalWrite(in2, velocidade);  //digitalWrite(in2, HIGH);
  // Motor B frente
  digitalWrite(in3, velocidade);  //digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void pare() {
  // Motor A parado
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // Motor B parado
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

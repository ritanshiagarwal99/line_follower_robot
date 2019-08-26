int LeftSen = A0;
int LeftMSen = A1;
int MidSen = A2;
int RightMSen = A3;
int RightSen = A4;

int STBY = 10;
//Motor A
int PWMA = 3; //Speed control
int AIN1 = 9; //Direction
int AIN2 = 8; //Direction
//caliberation pin
int cal = 7;
//Motor B
int PWMB = 5; //Speed control
int BIN1 = 11; //Direction
int BIN2 = 12; //Direction

void setup() {
  // put your setup code here, to run once:
  pinMode(LeftSen, INPUT);
  pinMode(LeftMSen, INPUT);
  pinMode(MidSen, INPUT);
  pinMode(RightMSen, INPUT);
  pinMode(RightSen, INPUT);

  pinMode(STBY, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
//  caliberation();
}

void loop() {
  // put your main code here, to run repeatedly:

  if ((digitalRead(LeftSen) == 0) && (digitalRead(LeftMSen) == 0) && (digitalRead(MidSen) == 1) && (digitalRead(RightMSen) == 0) && (digitalRead(RightSen) == 0))
  {
    forward();
  }
  else if ((digitalRead(LeftSen) == 0) && (digitalRead(LeftMSen) == 1) && (digitalRead(MidSen) == 1) && (digitalRead(RightMSen) == 0) && (digitalRead(RightSen) == 0))
  {
    sharp_right();
  }
  else if ((digitalRead(LeftSen) == 0) && (digitalRead(LeftMSen) == 1) && (digitalRead(MidSen) == 0) && (digitalRead(RightMSen) == 0) && (digitalRead(RightSen) == 0))
  {
   forward();
  }
  else if ((digitalRead(LeftSen) == 1) && (digitalRead(LeftMSen) == 1) && (digitalRead(MidSen) == 0) && (digitalRead(RightMSen) == 0) && (digitalRead(RightSen) == 0))
  {
    left();
  }
  else if ((digitalRead(LeftSen) == 1) && (digitalRead(LeftMSen) == 1) && (digitalRead(MidSen) == 1) && (digitalRead(RightMSen) == 0) && (digitalRead(RightSen) == 0))
   sharp_left();
  else if ((digitalRead(LeftSen) == 1) && (digitalRead(LeftMSen) == 0) && (digitalRead(MidSen) == 0) && (digitalRead(RightMSen) == 0) && (digitalRead(RightSen) == 0))
  {
    left();
  }
  else if ((digitalRead(LeftSen) == 0) && (digitalRead(LeftMSen) == 0) && (digitalRead(MidSen) == 1) && (digitalRead(RightMSen) == 1) && (digitalRead(RightSen) == 0))
  {
    forward();
  }
  else if ((digitalRead(LeftSen) == 0) && (digitalRead(LeftMSen) == 0) && (digitalRead(MidSen) == 0) && (digitalRead(RightMSen) == 1) && (digitalRead(RightSen) == 0))
  {
    forward();
  }
  else if ((digitalRead(LeftSen) == 0) && (digitalRead(LeftMSen) == 0) && (digitalRead(MidSen) == 0) && (digitalRead(RightMSen) == 1) && (digitalRead(RightSen) == 1))
  {
    right();
  }
   else if((digitalRead(LeftSen) == 0) && (digitalRead(LeftMSen) == 0) && (digitalRead(MidSen) == 1) && (digitalRead(RightMSen) == 1) && (digitalRead(RightSen) == 1))
    sharp_right(); 
  else if ((digitalRead(LeftSen) == 0) && (digitalRead(LeftMSen) == 0) && (digitalRead(MidSen) == 0) && (digitalRead(RightMSen) == 0) && (digitalRead(RightSen) == 1))
  {
    right();
  }
  else if ((digitalRead(LeftSen) == 0) && (digitalRead(LeftMSen) == 0) && (digitalRead(MidSen) == 0) && (digitalRead(RightMSen) == 0) && (digitalRead(RightSen) == 0))
  {
    stay();
  }
  else if ((digitalRead(LeftSen) == 1) && (digitalRead(LeftMSen) == 1) && (digitalRead(MidSen) == 1) && (digitalRead(RightMSen) == 1) && (digitalRead(RightSen) == 1))
  {
   forward();
  }
  else  if ((digitalRead(LeftSen) == 1) && (digitalRead(LeftMSen) == 1) && (digitalRead(MidSen) == 1) && (digitalRead(RightMSen) == 1) && (digitalRead(RightSen) == 0))
   sharp_left();
   else  if ((digitalRead(LeftSen) == 0) && (digitalRead(LeftMSen) == 1) && (digitalRead(MidSen) == 1) && (digitalRead(RightMSen) == 1) && (digitalRead(RightSen) == 1))
   sharp_right();
  else
  forward();
}
void forward()
{
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMA, 255);
  analogWrite(PWMB, 255);
}

void sharp_right()
{
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMA, 50);
  analogWrite(PWMB, 50);
}

void right()
{
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMA, 100);
  analogWrite(PWMB, 100);
}

void sharp_left()
{
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMA, 50);
  analogWrite(PWMB, 50);
}

void left()
{
  digitalWrite(STBY, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMA, 100);
  analogWrite(PWMB, 100);
}

void stay()
{
  digitalWrite(STBY, LOW);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
}

/*void caliberation()
{
  digitalWrite(cal,HIGH);
  delay(750);
  digitalWrite(cal,LOW);
  delay(750);
  digitalWrite(cal,HIGH);
  delay(750);
  digitalWrite(cal,LOW);
  delay(750);
  digitalWrite(cal,HIGH);
  
}*/

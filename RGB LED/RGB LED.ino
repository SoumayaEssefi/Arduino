int  A;
int  b;
int  c;
int  num1;
int  num2;
int  num3;
void setup()
{
  A = 0;

  b = 0;

  c = 0;

  num1 = 0;

  num2 = 0;

  num3 = 0;

  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);

}


void loop()
{
    A = analogRead(A0);
    b = analogRead(A2);
    c = analogRead(A5);
    num1 = (map(A,0,1023,0,255));
    num2 = (map(b,0,1023,0,255));
    num3 = (map(c,0,1023,0,255));
    analogWrite(6,num2);
    analogWrite(10,num1);
    analogWrite(9,num3);

}
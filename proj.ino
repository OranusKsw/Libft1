int a = 0;  //For displaying segment "a"
int b = 1;  //For displaying segment "b"
int c = 2;  //For displaying segment "c"
int d = 3;  //For displaying segment "d"
int e = 4;  //For displaying segment "e"
int f = 5;  //For displaying segment "f"
int g = 6;  //For displaying segment "g"
const int buttonPin[4] = {14, 15, 16, 17}; 

int buttonState[4] = {0,0,0,0};
   

void setup() {               
  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G

  pinMode(8, OUTPUT);  //D
  pinMode(9, OUTPUT);  //E
  pinMode(10, OUTPUT);  //F
  pinMode(11, OUTPUT);

  pinMode(buttonPin[0], INPUT);  //D
  pinMode(buttonPin[1], INPUT);  //E
  pinMode(buttonPin[2], INPUT);  //F
  pinMode(buttonPin[3], INPUT);
}
void displayDigit(int digit)
{
 //Conditions for displaying segment a
 if(digit!=1 && digit != 4)
 digitalWrite(a,HIGH);
 
 //Conditions for displaying segment b
 if(digit != 5 && digit != 6)
 digitalWrite(b,HIGH);
 
 //Conditions for displaying segment c
 if(digit !=2)
 digitalWrite(c,HIGH);
 
 //Conditions for displaying segment d
 if(digit != 1 && digit !=4 && digit !=7)
 digitalWrite(d,HIGH);
 
 //Conditions for displaying segment e 
 if(digit == 2 || digit ==6 || digit == 8 || digit==0)
 digitalWrite(e,HIGH);
 
 //Conditions for displaying segment f
 if(digit != 1 && digit !=2 && digit!=3 && digit !=7)
 digitalWrite(f,HIGH);
 if (digit!=0 && digit!=1 && digit !=7)
 digitalWrite(g,HIGH);
 
}
void turnOff()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

void buttonn()
{
    buttonState[1] = digitalRead(buttonPin[1]);
  buttonState[2] = digitalRead(buttonPin[2]);
  buttonState[3] = digitalRead(buttonPin[3]);
  buttonState[0] = digitalRead(buttonPin[0]);

  for(int i = 0; i < 4; i++)
  {
   if (buttonState[i] == HIGH) {
    Serial.println(buttonPin[i]);
    digitalWrite(buttonPin[i]-6, HIGH);
  } 
  else {
    
    digitalWrite(buttonPin[i]-6, LOW);
  }
  }
}

void loop() {

Serial.println(buttonPin[0]);
buttonn();
 for(int i=0;i<10;i++)
 {
   displayDigit(i);
   delay(1000);
   turnOff();
 }
}

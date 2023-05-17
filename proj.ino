int a = 0;  //For displaying segment "a"
int b = 1;  //For displaying segment "b"
int c = 2;  //For displaying segment "c"
int d = 3;  //For displaying segment "d"
int e = 4;  //For displaying segment "e"
int f = 5;  //For displaying segment "f"
int g = 6;  //For displaying segment "g"
const int buttonPin[4] = {14, 15, 16, 17}; 
int score = 0;

int buttonState[4] = {0,0,0,0};
int randint;

void setup() {         
  Serial.begin(9600);      
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

Serial.println("Here2");
  while(digitalRead(14) == LOW && digitalRead(15) == LOW&& digitalRead(16) == LOW&& digitalRead(17) == LOW);
  Serial.println("Here3");
  for(int i = 14; i < 18; i++)
  {
   if (digitalRead(i) == HIGH)
   {
    if(i == randint + 6) {
      //Serial.println(digitalRead(i));
      digitalWrite(randint, LOW);
      score++;
      Serial.println(score);
      displayDigit(score);
     // while(digitalRead(i) == HIGH);
      loop();
    }
    else
    { 
      Serial.println("i");
    }
  } 
  else {
    Serial.println(i);
  }
  Serial.println("Here");
  }
  buttonn();
}


void displayseg()
{
   for(int i=0;i<10;i++)
 {
   displayDigit(i);
   turnOff();
 }
  }

 void mole()
 {
  randint= random(8, 12);
  digitalWrite(randint, HIGH);
  
  }
void loop() {
  for(int i = 8; i < 12; i++)
  {
    digitalWrite(i, LOW);  
  }
  mole();
  buttonn();
  Serial.println("Here1");
  delay(1000);
}

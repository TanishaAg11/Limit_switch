#define ENA 5
#define in1 4
#define in2 7


const int buttonPin1 = 2; 
const int buttonPin2 = 8;   //changed   
  
const int ledPin = 13;
       
int newButtonState1;
int newButtonState2;
int oldButtonState1 = HIGH;
int oldButtonState2 = HIGH;


void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(ENA, OUTPUT);
  Serial.begin(9600);


  pinMode(buttonPin1, INPUT_PULLUP);   
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);  
  digitalWrite(ledPin, HIGH);
}

void loop()
{
  digitalWrite(ENA,150);
  newButtonState1 = digitalRead(buttonPin1);

  if (newButtonState1 == HIGH && oldButtonState1 == LOW) {
      //forward
      digitalWrite(ledPin, HIGH);

      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      
  }
  
   oldButtonState1 = newButtonState1;

   newButtonState2 = digitalRead(buttonPin2);
if(newButtonState2 == HIGH && oldButtonState2 == LOW){
  
     digitalWrite(ledPin, LOW);

     digitalWrite(in1,LOW);
     digitalWrite(in2,HIGH);
      
  }
  oldButtonState2 = newButtonState2;
}

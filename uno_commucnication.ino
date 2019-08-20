//Serial Communication Between Arduino using RS-485

int enablePin = 8;  
int pushval = A0;
int potval =0 ;

void setup()
{
  Serial.begin(9600);           
  pinMode(enablePin, OUTPUT);
  pinMode(pushval,INPUT); 
  delay(10); 
  digitalWrite(enablePin, HIGH);  
}
void loop()
{
    int potval = analogRead(pushval);
    Serial.println(potval);          
    delay(100);
}

SLAVE CODE: (Arduino NANO):



#include <LiquidCrystal.h>           

int enablePin = 8; 
int ledpin = 10;

LiquidCrystal lcd(2,3,4,5,6,7);       

void setup() 
{
  lcd.begin(16,2);
  lcd.print("CIRCUIT DIGEST");
  lcd.setCursor(0,1);
  lcd.print("RS485 ARDUINO");
  delay(3000);
  lcd.clear();
  Serial.begin(9600);                   
  pinMode(ledpin,OUTPUT);
  pinMode(enablePin, OUTPUT);
  delay(10);
  digitalWrite(enablePin, LOW);        
  
}

void loop() 

{       
  //loop to get the flow
  while (Serial.available())                       {
        lcd.clear();             
        int pwmval = Serial.parseInt();            
        int convert = map(pwmval,0,1023,0,255);    
        analogWrite(ledpin,convert);               
        lcd.setCursor(0,0);
        lcd.print("PWM FROM MASTER");
        lcd.setCursor(0,1);
        lcd.print(convert);                     
        delay(100);
    }
 } 



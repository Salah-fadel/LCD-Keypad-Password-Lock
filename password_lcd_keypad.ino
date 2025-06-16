#include <Keypad.h>
#include <LiquidCrystal.h>
#define led 13

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {A0, A1, A2, A3};
byte colPins[COLS] = {A4, A5, 7, 8};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char Spass[]={"222AAA"};
int passS=sizeof(Spass)-1,i=0,count=0;
char Ipass[sizeof(Spass)-1];

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Enter  the  pass");
  lcd.setCursor(0,1);
}

void loop() {
    char key = keypad.getKey();
  
  if (key!='D'&&key>'1')
  {
  lcd.print('*');
  Ipass[i]=key;
  i++;
  }
  else if(key=='D')
  { 
      if(i==passS)
        {
         for(int j=0;j<=passS;j++)
          {
           if(Ipass[j]==Spass[j]) count++;
          }
         if(count==passS)
         {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Crrect  password");
          digitalWrite(led,HIGH);
          delay(2000);
          digitalWrite(led,LOW);
          lcd.setCursor(0,0);
          lcd.print("Enter  the  pass");
          lcd.setCursor(0,1);
          /*digitalWrite(led,HIGH);
          delay(2000);
          digitalWrite(led,LOW);*/
          count=0;
          i=0;
         }
        else
         {
          Wrongpass();
         }
        }
     else
      {
      Wrongpass();
      }
}
}
void Wrongpass()
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Wrong   password");
delay(2000);
lcd.setCursor(0,0);
lcd.print("Enter  the  pass");
lcd.setCursor(0,1);
count=0;
i=0;
}


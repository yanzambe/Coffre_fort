#include <Key.h>
#include <Keypad.h>

#include <LiquidCrystal.h>


LiquidCrystal lcd(15, 14, 13, 12, 11, 10);

const byte ROWS = 4;
const byte COLS = 4;
char keys [ROWS] [COLS] = {
  {'7','8','9','D'},
  {'4','5','6','C'},
  {'1','2','3','B'},
  {'*','0','#','A'}
  };
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

long Num1, Num2, Number;
char key, action;
boolean result = false;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("GDN-CODE");
  lcd.setCursor(0,1);
  lcd.print("Projects Presents");
  delay(3000);
  lcd.setCursor(0,0);
  lcd.print("Arduino Calculator");
  delay(2000);
  lcd.clear();
}

void loop() {
  Serial.print(key);
  key = myKeypad.getKey();

  if(key!=NO_KEY)
  DetectButtons();

  if(result==true)
  CalculateResult();

  DisplayResult();
}

void DetectButtons() {
  lcd.clear();
  if (key == '*'){
    Serial.println ("Button Cancel"); Number=Num1=Num2=0; result=false;
  }

  if (key == '1'){
    Serial.println ("Button 1");
    if (Number == 0){
      Number = 1;
    } else {
      Number = (Number * 10) + 1;
    }
  }
  
  if (key == '4'){
    Serial.println ("Button 4");
    if (Number == 0){
      Number = 4;
    } else {
      Number = (Number * 10) + 4;
    }
  }
  
  if (key == '7'){
    Serial.println ("Button 7");
    if (Number == 0){
      Number = 7;
    } else {
      Number = (Number * 10) + 7;
    }
  }




  if (key == '0'){
    Serial.println ("Button 0");
    if (Number == 0){
      Number = 0;
    } else {
      Number = (Number * 10) + 0;
    }
  }

  if (key == '2'){
    Serial.println ("Button 2");
    if (Number == 0){
      Number = 2;
    } else {
      Number = (Number * 10) + 2;
    }
  }

  if (key == '5'){
    Serial.println ("Button 5");
    if (Number == 0){
      Number = 5;
    } else {
      Number = (Number * 10) + 5;
    }
  }

  if (key == '8'){
    Serial.println ("Button 8");
    if (Number == 0){
      Number = 8;
    } else {
      Number = (Number * 10) + 8;
    }
  }




  if (key == '#'){
    Serial.println ("Button Equal");
    Num2 = Number;
    result = true;
  }

  if (key == '3'){
    Serial.println ("Button 3");
    if (Number == 0){
      Number = 3;
    } else {
      Number = (Number * 10) + 3;
    }
  }

  if (key == '6'){
    Serial.println ("Button 6");
    if (Number == 0){
      Number = 6;
    } else {
      Number = (Number * 10) + 6;
    }
  }

  if (key == '9'){
    Serial.println ("Button 9");
    if (Number == 0){
      Number = 9;
    } else {
      Number = (Number * 10) + 9;
    }
  }

  if (key == 'A'|| key == 'B'|| key == 'C'|| key == 'D'){
    Num1 = Number;
    Number = 0;
    if (key == 'A'){
      Serial.println ("Addition"); action = '+';
    }
    if (key == 'B'){
      Serial.println ("Subtraction"); action = '-';
    }
    if (key == 'C'){
      Serial.println ("Multiplication"); action = '*';
    }
    if (key == 'D'){
      Serial.println ("Devesion"); action = '/';
    }

    delay(100);
  }
}

void CalculateResult() {
  if (action == '+'){
    Number = Num1 + Num2;
  }

  if (action == '-'){
    Number = Num1 - Num2;
  }

  if (action == '*'){
    Number = Num1 * Num2;
  }

  if (action == '/'){
    Number = Num1 / Num2;
  }
}

void DisplayResult() {
  lcd.setCursor(0, 0);
  lcd.print(Num1); lcd.print(action); lcd.print(Num2);

  if (result == true){
    lcd.print(" ="); lcd.print(Number);
  }

  lcd.setCursor(0, 1);
  lcd.print(Number);

  //FIN
}

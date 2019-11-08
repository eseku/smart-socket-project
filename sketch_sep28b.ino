#include <LiquidCrystal.h>
#include <Keypad.h>

bool light = false;
int lamp = 6;
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
byte rowPins[ROWS] = {10, 9, 8, 7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {13, 12, 11}; //connect to the column pinouts of the keypad
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void turnOnTheLight(bool x){
  if(x == true) {
    digitalWrite(lamp, HIGH);
    lcd.setCursor(0,0);
    lcd.print("ON ");
  }else{
      digitalWrite(lamp, LOW);
      lcd.setCursor(0,0);
    lcd.print("OFF");
  
  }
 }

void lightSwitch(){
  if(light == false){
      light = true;
    }else{
      light = false;
      }
      turnOnTheLight(light);
  }


void setup() {

pinMode(lamp, OUTPUT);

 
// set up the LCD's number of columns and rows:
lcd.begin(20, 4);
lcd.setCursor(4,3);
lcd.print("Smart Home");
lcd.setCursor(0,0);
}

void loop() {
char key = keypad.getKey();

if (key) {
  if(key == '0'){
      lightSwitch();    
    }
 }

}

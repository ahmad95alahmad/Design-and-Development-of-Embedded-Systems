/*==================================== 
 * File name: exerc_5_1.ino
 * Date: 2018-02-23 
 * Group Number: 3 and 11 
 * Members That contributed: Kosara Golemshinska, Samer Daknache, Martin Chukaleski, Marko Stanoevich, Boyan Dai, Yazan Alsahhar
 * Demonstration code: [<37601>]        
 ======================================*/

//       CA1 G  F  A  B
//        |  |  |  |  |      -> pins and segments they control
//   ---------    ---------
//   |   A   |    |   A   |
//  F|       |B  F|       |B
//   |---G---|    |---G---|
//  E|       |C  E|       |C
//   |   D   |    |   D   |
//   ---------    ---------
//        |  |  |  |  |      -> pins and segments they control
//        D  DP E  C CA2         

// Segments that make each number when lit:
// 0 => -FEDCBA
// 1 => ----BC-
// 2 => G-ED-BA
// 3 => G--DCBA
// 4 => GF--CB-
// 5 => GF-DC-A
// 6 => GFEDC-A
// 7 => ----CBA
// 8 => GFEDCBA
// 9 => GF-DCBA

// Arduino digital pins used to light up
// corresponding segments on the LED display
#define A 4
#define B 9
#define C 8
#define D 6
#define E 7
#define F_SEG 5
#define G 2

// Pins driving common anodes
#define CA1 13 //Cathode D1, pin 5
#define CA2 12 //Cathode D2, pin 4

#define OFF LOW
#define ON HIGH

// Pin for temperature reading
const int S1 = 10;

// Variable for storing the temparature
int temp;
// Variable for storing raw data from the temperature sensor
int val;
// Variable for storing the maximum temperature
int tempMAX = -100;

//State of DIP switch 1
int s1state = HIGH;   //HIGH means off, LOW means on (INPUT_PULLUP)

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F_SEG, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(CA1, OUTPUT);
  pinMode(CA2, OUTPUT);

  analogReference(INTERNAL);
  pinMode(S1, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  // Reads and converts raw values to Celsius
  s1state = digitalRead(S1);
  val = analogRead(0);
  temp = val/ 10;

  // Keeps track of the maximum measuered temparature
  if(temp>tempMAX){
    tempMAX = temp;
  }

  // If DIP switch is toggled the maximum temperature is displayed
  // Only values between -9 to 99 inclusive can be displayed
  if(s1state==LOW){
    Serial.print("Max temperature is: ");
    Serial.println(tempMAX);
    
    if(tempMAX >= -9 && tempMAX < 0){
      selectSecondDigit();
      drawMinus();
      selectFirstDigit();
      drawNumber(tempMAX*(-1));
    }
    else if(tempMAX >= 0 && tempMAX<10){
      selectFirstDigit();
      drawNumber(tempMAX);
      delay(1000);
    }
    else if(tempMAX>=10){
      selectSecondDigit();
      drawNumber(tempMAX/10);
      delay(20);
      selectFirstDigit();
      delay(20);
      drawNumber(tempMAX%10);
      delay(20);
    }
  // DIP switch is toggled off so it displayes the current temperature
  // Only values between -9 to 99 inclusive can be displayed
  }else{
    Serial.print("Current temperature is: ");
    Serial.println(temp);

    if(temp >= -9 && temp < 0){
      selectSecondDigit();
      drawMinus();
      selectFirstDigit();
      drawNumber(temp*(-1));
    }
    else if(temp>=0 && temp<10){
      selectFirstDigit();
      drawNumber(temp);
      delay(1000);
    }
    else if(temp>=10){
      selectSecondDigit();
      drawNumber(temp/10);
      delay(20);
      selectFirstDigit();
      drawNumber(temp%10);
      delay(20);
    }
    
  }
}

// Selects the first digit
void selectFirstDigit(){
  digitalWrite(CA1, HIGH);
  digitalWrite(CA2, LOW);
}

// Selects the second digit
void selectSecondDigit(){
  digitalWrite(CA1, LOW);
  digitalWrite(CA2, HIGH);
}

// Draws a minus on the selected digit
void drawMinus(){
  digitalWrite(A, OFF);
  digitalWrite(B, OFF);
  digitalWrite(C, OFF);
  digitalWrite(D, OFF);
  digitalWrite(E, OFF);
  digitalWrite(F_SEG, OFF);
  digitalWrite(G, ON);
}

// Draws numbers 0-9 on selected digit
void drawNumber(int number){
  switch (number){
    case 0:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, ON);
        digitalWrite(F_SEG, ON);
        digitalWrite(G, OFF);
        break;
    case 1: //
        digitalWrite(A, OFF);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, OFF);
        digitalWrite(E, OFF);
        digitalWrite(F_SEG, OFF);
        digitalWrite(G, OFF);
        break;
    case 2:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, OFF);
        digitalWrite(D, ON);
        digitalWrite(E, ON);
        digitalWrite(F_SEG, OFF);
        digitalWrite(G, ON);
        break;
    case 3:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, OFF);
        digitalWrite(F_SEG, OFF);
        digitalWrite(G, ON);
        break;
    case 4:
        digitalWrite(A, OFF);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, OFF);
        digitalWrite(E, OFF);
        digitalWrite(F_SEG, ON);
        digitalWrite(G, ON);
        break;
    case 5:
        digitalWrite(A, ON);
        digitalWrite(B, OFF);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, OFF);
        digitalWrite(F_SEG, ON);
        digitalWrite(G, ON);
        break;
    case 6: //
        digitalWrite(A, ON);
        digitalWrite(B, OFF);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, ON);
        digitalWrite(F_SEG, ON);
        digitalWrite(G, ON);
        break;
    case 7: 
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, OFF);
        digitalWrite(E, OFF);
        digitalWrite(F_SEG, OFF);
        digitalWrite(G, OFF);
        break;
    case 8: //
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, ON);
        digitalWrite(F_SEG, ON);
        digitalWrite(G, ON);
        break;
    case 9:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, OFF);
        digitalWrite(F_SEG, ON);
        digitalWrite(G, ON);
        break;
  }
}



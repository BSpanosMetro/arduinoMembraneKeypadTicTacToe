#include <Keypad.h>

//LED PINS
int xPin = 8;
int yPin = 9;

//Tic Tac Toe Values
// 's' stands for square
char s1 = '_';
char s2 = '_';
char s3 = '_';
char s4 = '_';
char s5 = '_';
char s6 = '_';
char s7 = '_';
char s8 = '_';
char s9 = '_';

bool turn = true; //X is true, Y is false

String victoryState = "______"; 

//Keypad Setup
const byte ROWS = 3; 
const byte COLS = 3; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
};

byte rowPins[ROWS] = {7, 6, 5};
byte colPins[COLS] = {4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() { // Sets up serial monitor and LED pins
  Serial.begin(9600);
  pinMode(xPin, OUTPUT);
  pinMode(yPin, OUTPUT);
}

void loop() { // Runs the game of Tic Tac Toe
  Serial.println (s1+s2+s3); // Prints first row
  Serial.println (s4+s5+s6); // Prints second row
  Serial.println (s7+s8+s9); // Prints third row
  Serial.println (victoryState); // Prints either if someone has won or a break between game boards
  char customKey = customKeypad.getKey(); //Calls keypad
  if (customKey) { //Runs if key is pressed
    if (turn) { // Checks whose turn it is, see line 19
      turn = false; // Switches the turn
      digitalWrite(xPin, LOW); // Turns of Red LED
      digitalWrite(yPin, HIGH); // Turns on Blue LED
    } else {
      turn = true;
      digitalWrite(xPin, HIGH);
      digitalWrite(yPin, LOW);
    }

// Code to play a square
    if (customKey == '1'){ // Checks key pressed
      if (turn) { // Checks whose turn it is
        s1 = 'X'; // Claims the square of the number pressed
      } else {
        s1 = 'O';
      }
    } else if (customKey == '2') {
      if (turn) {
        s2 = 'X';
      } else {
        s2 = 'O';
      }
    } else if (customKey == '3') {
      if (turn) {
        s3 = 'X';
      } else {
        s3 = 'O';
      }
    } else if (customKey == '4') {
      if (turn) {
        s4 = 'X';
      } else {
        s4 = 'O';
      }
    } else if (customKey == '5') {
      if (turn) {
        s5 = 'X';
      } else {
        s5 = 'O';
      }
    } else if (customKey == '6') {
      if (turn) {
        s6 = 'X';
      } else {
        s6 = 'O';
      }
    } else if (customKey == '7') {
      if (turn) {
        s7 = 'X';
      } else {
        s7 = 'O';
      }
    } else if (customKey == '8') {
      if (turn) {
        s8 = 'X';
      } else {
        s8 = 'O';
      }
    } else if (customKey == '9') {
      if (turn) {
        s9 = 'X';
      } else {
        s9 = 'O';
      }
    }

// Code to check if game won
    if (s1 != '_') { // Checks if square is claimed
      if (s1 == s2 && s1 == s3) { // Checks if line is claimed by the same player
        if (s1 == 'X') { // Checks who won
          victoryState = "X Wins"; // Updates victoryState to display the winner
          turn = true; // Sets it to always be winners turn so appropriate led remains on
        } else {
          victoryState = "O Wins";
          turn = false;
        }
      } else if (s1 == s4 && s1 == s7) {
        if (s1 == 'X') {
          victoryState = "X Wins";
          turn = true;
        } else {
          victoryState = "O Wins";
          turn = false;
        }
      } else if (s1 == s5 && s1 == s9) {
        if (s1 == 'X') {
          victoryState = "X Wins";
          turn = true;
        } else {
          victoryState = "O Wins";
          turn = false;
        }
      }
    } else if (s2 != '_') {
      if (s2 == s5 && s2 == s8) {
        if (s2 == 'X') {
          victoryState = "X Wins";
          turn = true;
        } else {
          victoryState = "O Wins";
          turn = false;
        }
      }
    } else if (s3 != '_') {
      if (s3 == s6 && s3 == s9) {
        if (s3 == 'X') {
          victoryState = "X Wins";
          turn = true;
        } else {
          victoryState = "O Wins";
          turn = false;
        }
      } else if (s3 == s5 && s3 == s7) {
        if (s1 == 'X') {
          victoryState = "X Wins";
          turn = true;
        } else {
          victoryState = "O Wins";
          turn = false;
        }
      }
    } else if (s4 != '_') {
      if (s4 == s5 && s3 == s6) {
        if (s3 == 'X') {
          victoryState = "X Wins";
          turn = true;
        } else {
          victoryState = "O Wins";
          turn = false;
        }
      }
    } else if (s7 != '_') {
      if (s7 == s8 && s7 == s9) {
        if (s3 == 'X') {
          victoryState = "X Wins";
          turn = true;
        } else {
          victoryState = "O Wins";
          turn = false;
        }
      }
    }
  }
}

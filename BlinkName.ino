const short blink = 300;
const short B_long = 300;
const short pause = 3000;
const short let_pause = 2000;

int pushButton = 4;
int pushButtonState;

const char morseAlphabets[26][5] = {
  {'.', '-'},   // A
  {'.', '.'},         // I
  {'.', '-', '-', '-'},   // J
  {'-', '.', '-', '-'},   // Y
  {'-', '-', '.', '.'}    // Z
};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pushButton, INPUT_PULLUP);
}

void blinkDot() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(blink);
  digitalWrite(LED_BUILTIN, LOW);
  delay(blink);
}

void blinkDash() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(B_long);
  digitalWrite(LED_BUILTIN, LOW);
  delay(blink);
}

void blinkPause() {
  delay(pause);
}

void blinkLetterPause() {
  delay(let_pause);
}

void blinkMorseCode(char letter) {
  int index = letter - 'A';
  if (index >= 0 && index < 26) {
    for (int i = 0; i < 5 && morseAlphabets[index][i] != '\0'; i++) {
      if (morseAlphabets[index][i] == '.')
        blinkDot();
      else if (morseAlphabets[index][i] == '-')
        blinkDash();
    }
    blinkCharacterPause();
  }
}

void loop() {
  pushButtonState = digitalRead(pushButton);
  
  if (pushButtonState == LOW) {
    String name = "jiya"; 
    name.toUpperCase();
    
    for (int i = 0; i < name.length(); i++) {
      char alpha = name.charAt(i);
      blinkMorseCode(alpha);
    }
    
    blinkLetterPause();
  }
}

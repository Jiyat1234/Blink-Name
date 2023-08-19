const short SHORT_BLINK = 250;
const short LONG_BLINK = 500;
const short CHARACTER_PAUSE = 1000;
const short LETTER_PAUSE = 3000;

int pushButton = 3;
int pushButtonState;

const char morseAlphabets[26][5] = {
  {'.', '-'},   // A
  {'-', '.', '.', '.'},   // B
  {'-', '.', '-', '.'},   // C
  {'-', '.', '.'},       // D
  {'.'},             // E
  {'.', '.', '-', '.'},   // F
  {'-', '-', '.'},       // G
  {'.', '.', '.', '.'},   // H
  {'.', '.'},         // I
  {'.', '-', '-', '-'},   // J
  {'-', '.', '-'},       // K
  {'.', '-', '.', '.'},   // L
  {'-', '-'},         // M
  {'-', '.'},         // N
  {'-', '-', '-'},       // O
  {'.', '-', '-', '.'},   // P
  {'-', '-', '.', '-'},   // Q
  {'.', '-', '.'},       // R
  {'.', '.', '.'},       // S
  {'-'},             // T
  {'.', '.', '-'},       // U
  {'.', '.', '.', '-'},   // V
  {'.', '-', '-'},       // W
  {'-', '.', '.', '-'},   // X
  {'-', '.', '-', '-'},   // Y
  {'-', '-', '.', '.'}    // Z
};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pushButton, INPUT_PULLUP);
}

void blinkDot() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(SHORT_BLINK);
  digitalWrite(LED_BUILTIN, LOW);
  delay(SHORT_BLINK);
}

void blinkDash() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(LONG_BLINK);
  digitalWrite(LED_BUILTIN, LOW);
  delay(SHORT_BLINK);
}

void blinkCharacterPause() {
  delay(CHARACTER_PAUSE);
}

void blinkLetterPause() {
  delay(LETTER_PAUSE);
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
    String name = "jiya"; // Replace with the desired name
    name.toUpperCase();
    
    for (int i = 0; i < name.length(); i++) {
      char letter = name.charAt(i);
      blinkMorseCode(letter);
    }
    
    blinkLetterPause();
  }
}

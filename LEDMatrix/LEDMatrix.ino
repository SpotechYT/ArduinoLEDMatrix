/*

2x4 Matrix Code, simple animations
By: Haniel Mikhaiel

Credits to http://www.multiwingspan.co.uk/arduino.php?page=matrix
for the basic coding ideas and functions

*/

// anodes pins (- pins)
int col[] = {9,8};
// cathodes pins (+ pins)
int row[] = {5,4,3,2};

void setup()
{
  // intitalize the rows and columns
  for (int i = 0; i < 4; i++) // row[] has 4 elements
  {
    pinMode(row[i], OUTPUT);
  } 
  for (int j = 0; j < 2; j++) // col[] has 2 elements
  {
    pinMode(col[j], OUTPUT);
  }

  // turn off all the LEDS
  allOff();
}

void loop() // This constantly runs
{
  // Zig Zag Pattern
  for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 2; c++) {
      turnOnLED(r, c);
      delay(200);
    }
  }

  // Reverse Zig Zag Pattern
  for (int r = 3; r >= 0; r--) {
    for (int c = 1; c >= 0; c--) {
      turnOnLED(r, c);
      delay(200);
    }
  }

  //Rows going down
  for(int r = 0; r < 4; r++){
    turnOnRow(r);
    delay(200);
  }

  //Columns left to right
  for(int c = 0; c < 2; c++){
    turnOnCol(c);
    delay(200);
  }

  // Flash all on and off
  allOff();
  delay(200);
  allOn();
  delay(200);
  allOff();
  delay(200);
  allOn();
  delay(200);
}

void turnOnLED(int x, int y) // Truns on a specific coordinate
{
  allOff();
  digitalWrite(row[x], HIGH);
  digitalWrite(col[y], LOW);
}

void turnOnRow(int x) // Turns on a specific row
{
  allOff();
  digitalWrite(row[x], HIGH);
  digitalWrite(col[0], LOW);
  digitalWrite(col[1], LOW);
}

void turnOnCol(int y) // Turns on a specific column
{
  allOff();
  digitalWrite(row[0], HIGH);
  digitalWrite(row[1], HIGH);
  digitalWrite(row[2], HIGH);
  digitalWrite(row[3], HIGH);
  digitalWrite(col[y], LOW);
}

void allOff() // Turn off all the LEDs
{
  for (int i=0;i<2;i++) // Connect all the anodes to power
  {
    digitalWrite(col[i], HIGH);
  }
  for (int j=0;j<4;j++) // Connect all the cathodes to ground
  {
    digitalWrite(row[j], LOW);
  }
}

void allOn() // Turn off all the LEDs
{
  for (int i=0;i<2;i++) // Connect all the anodes to ground
  {
    digitalWrite(col[i], LOW);
  }
  for (int j=0;j<4;j++) // Connect all the cathodes to power
  {
    digitalWrite(row[j], HIGH);
  }
}

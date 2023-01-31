// Very first Arduboy program
// Not sure what to expect

#include <Arduboy2.h>
Arduboy2 arduboy;

int counter;

void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.clear();
  counter = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  arduboy.clear();
  arduboy.setCursor(0, 0);
  counter = counter + 1;
  arduboy.print(counter);
  arduboy.display();
}

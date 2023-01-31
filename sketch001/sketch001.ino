// Very first Arduboy program
// Not sure what to expect

#include <Arduboy2.h>
Arduboy2 arduboy;

void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.clear();
  arduboy.print("Hello, world");
  arduboy.display();
}

void loop() {
  // put your main code here, to run repeatedly:

}

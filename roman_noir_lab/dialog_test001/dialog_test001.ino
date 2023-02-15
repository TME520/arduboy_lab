#include <Arduboy2.h>
#include "Tinyfont.h"

Arduboy2 arduboy;
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
  arduboy.clear();
}

void loop() {
  if ( !arduboy.nextFrame() ) {
    return;
  }

  arduboy.clear();
  arduboy.pollButtons();

  tinyfont.setCursor(48, 2);
  tinyfont.print("SUZY");
  tinyfont.setCursor(48, 10);
  tinyfont.print("The quick brown\nfox jumps over\nthe lazy dog.");

  arduboy.display();
}

#include <Arduboy2.h>
Arduboy2 arduboy;

int gamestate = 0;
int counter = 0;

void setup() {
  arduboy.begin();
  arduboy.initRandomSeed();
  arduboy.setFrameRate(60);
  arduboy.clear();
}

void loop() {

  counter += 1;
  
  if ( !arduboy.nextFrame() ) {
    return;
  }
  
  arduboy.clear();
  arduboy.pollButtons();

  if ( arduboy.justPressed(A_BUTTON) ) {
    gamestate += 1;
    counter = 0;
    if ( gamestate > 3 ) {
      gamestate = 0;
    }
  }

  switch ( gamestate ) {
    case 0:
      arduboy.setCursor(0, 0);
      arduboy.print("Title screen");
      arduboy.print("\n");
      arduboy.print(gamestate);
      arduboy.print("\n");
      break;
    case 1:
      arduboy.setCursor(0, 0);
      arduboy.print("Gameplay");
      arduboy.print("\n");
      arduboy.print(gamestate);
      arduboy.print("\n");
      break;
    case 2:
      arduboy.setCursor(0, 0);
      arduboy.print("Win screen");
      arduboy.print("\n");
      arduboy.print(gamestate);
      arduboy.print("\n");
      break;
    case 3:
      arduboy.setCursor(0, 0);
      arduboy.print("Game over screen");
      arduboy.print("\n");
      arduboy.print(gamestate);
      arduboy.print("\n");
      break;
  }

  arduboy.print("Counter: ");
  arduboy.print(counter);
  
  arduboy.display();
}

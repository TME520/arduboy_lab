#include <Arduboy2.h>
Arduboy2 arduboy;

const unsigned char PROGMEM background[] =
{
// width, height,
8, 8,
0x81, 0x00, 0x12, 0x40, 0x04, 0x11, 0x00, 0x04, 
};

const unsigned char PROGMEM player[] =
{
// width, height,
16, 16,
0xfe, 0x01, 0x3d, 0x25, 0x25, 0x3d, 0x01, 0x01, 0xc1, 0x01, 0x3d, 0x25, 0x25, 0x3d, 0x01, 0xfe, 
0x7f, 0x80, 0x9c, 0xbc, 0xb0, 0xb0, 0xb2, 0xb2, 0xb3, 0xb0, 0xb0, 0xb0, 0xbc, 0x9c, 0x80, 0x7f, 
};

int playerx = 5;
int playery = 10;

void setup() {
  arduboy.begin();
  arduboy.clear();
}

void loop() {
  arduboy.clear();
  arduboy.pollButtons();

  if ( arduboy.justPressed(LEFT_BUTTON) ) {
    playerx = playerx - 1;
    if ( playerx < 0 ) {
      playerx = 0;
    }
  }
  if ( arduboy.justPressed(RIGHT_BUTTON) ) {
    playerx = playerx + 1;
    if ( playerx > 127 ) {
      playerx = 127;
    }
  }
  if ( arduboy.justPressed(UP_BUTTON) ) {
    playery = playery - 1;
    if ( playery < 0 ) {
      playery = 0;
    }
  }
  if ( arduboy.justPressed(DOWN_BUTTON) ) {
    playery = playery + 1;
    if ( playery > 63) {
      playery = 63;
    }
  }

  for ( int backgroundx = 0; backgroundx < 128; backgroundx += 8 ) {
    for ( int backgroundy = 0; backgroundy < 64; backgroundy += 8 ) {
      Sprites::drawOverwrite(backgroundx, backgroundy, background, 0);
    }
  }
  
  Sprites::drawOverwrite(playerx, playery, player, 0);
  arduboy.display();
}

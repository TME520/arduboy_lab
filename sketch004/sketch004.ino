// Very first Arduboy program
// Not sure what to expect

#include <Arduboy2.h>
Arduboy2 arduboy;

int playerwin;
int attempts;
int guessednumber;
int randomnumber;
int lastguess;

void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.clear();
  arduboy.initRandomSeed();
  playerwin = 0;
  attempts = 0;
  guessednumber = 0;
  randomnumber = random(1, 101);
}

void loop() {
  // put your main code here, to run repeatedly:
  arduboy.clear();
  arduboy.pollButtons();
  if ( playerwin == 0 ) {
    if ( attempts == 7 ) {
      arduboy.setCursor(0, 0);
      arduboy.print("You lost :-(");
      arduboy.print("\n");
      arduboy.print("Correct number: ");
      arduboy.print(randomnumber);
      if ( arduboy.justPressed(A_BUTTON) ) {
        randomnumber = random(1, 101);
        attempts = 0;
        playerwin = 0;
      }
    }
    else {
      if ( arduboy.justPressed(UP_BUTTON) ) {
        guessednumber = guessednumber + 1;
        if ( guessednumber > 100 ) {
          guessednumber = 100;
        }
      }
      if ( arduboy.justPressed(DOWN_BUTTON) ) {
        guessednumber = guessednumber - 1;
        if ( guessednumber < 1 ) {
          guessednumber = 1;
        }
      }
      if ( arduboy.justPressed(A_BUTTON) ) {
        if ( guessednumber == randomnumber ) {
          playerwin = 1;
        }
        else {
          attempts = attempts + 1;
          lastguess = guessednumber;
        }
      }
      arduboy.setCursor(0, 0);
      arduboy.print("Attempt: ");
      arduboy.print(attempts);
      arduboy.print("\n");
      arduboy.print("Proposed number: ");
      arduboy.print(guessednumber);
      arduboy.print("\n");
      if ( attempts == 0 ) {
        arduboy.print("Good luck !");
      }
      else {
        arduboy.print(lastguess);
        if ( lastguess > randomnumber ) {
          arduboy.print(" is too high !");
        }
        else {
          arduboy.print(" is too low !");
        }
      }
    }
  }
  else {
    arduboy.setCursor(0, 0);
    arduboy.print("You won :-)");
    arduboy.print("\n");
    arduboy.print("Correct number: ");
    arduboy.print(randomnumber);
    if ( arduboy.justPressed(A_BUTTON) ) {
      randomnumber = random(1, 101);
      attempts = 0;
      playerwin = 0;
    }
  }
  arduboy.display();
}

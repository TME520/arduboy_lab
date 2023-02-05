//Jonathan Holmes (crait)
//December 7th, 2016
//A simple Pong clone

#include <Arduboy2.h>
Arduboy2 arduboy;
 
//Variables declared here
int gamestate = 0;
int ballx = 62;
int bally = 0;
int ballsize = 4;
int ballright = 1;
int balldown = 1;
int paddlewidth = 4;
int paddleheight = 9;
int playerx = 0;
int playery = 0;
int computery = 0;
int computerx = 127 - paddlewidth;
int playerscore = 0;
int computerscore = 0;

void resetGame() {
  ballx = 63;
  playerscore = 0;
  computerscore = 0;
}

void setup() {
  arduboy.begin();
  //Seed the random number generator
  arduboy.initRandomSeed();
  //Set the game to 60 frames per second
  arduboy.setFrameRate(60);
  arduboy.clear();
}

void loop() {

  //Prevent the Arduboy from running too fast
  if(!arduboy.nextFrame()) {
    return;
  }
  arduboy.clear();
  arduboy.pollButtons();

  //Game code here
  switch( gamestate ) {

    case 0:
      //Title screen
      arduboy.setCursor(0, 0);
      arduboy.print("Title Screen");
      //Change the gamestate
      if (arduboy.justPressed(A_BUTTON)) {
        gamestate = 1;
      }
      break;

    case 1:
      //Gameplay screen
      //Display the player's score
      arduboy.setCursor(20, 0);
      arduboy.print(playerscore);
      //Display the computer's score
      arduboy.setCursor(101, 0);
      arduboy.print(computerscore);
      //Draw the ball
      arduboy.fillRect(ballx, bally, ballsize, ballsize, WHITE);
      //Move the ball right
      if(ballright == 1) {
        ballx = ballx + 1;
      }
      //Move the ball left
      if(ballright == -1) {
        ballx = ballx - 1;
      }

      //Move the ball down
      if(balldown == 1) {
        bally = bally + 1;
      }
      //Move the ball up
      if(balldown == -1) {
        bally = bally - 1;
      }
      //Reflect the ball off of the top of the screen
      if(bally == 0) {
        balldown = 1;
      }
      //Reflect the ball off of the bottom of the screen
      if(bally + ballsize == 63) {
        balldown = -1;
      }
      //Draw the player's paddle
      arduboy.fillRect(playerx, playery, paddlewidth, paddleheight, WHITE);
      //If the player presses Up and the paddle is not touching the top of the screen, move the paddle up
      if(arduboy.pressed(UP_BUTTON) && playery > 0) {
        playery = playery - 1;
      }
      //If the player presses down and the paddle is not touching the bottom of the screen, move the paddle down
      if(arduboy.pressed(DOWN_BUTTON) && playery + paddleheight < 63) {
        playery = playery + 1;
      }
      //Draw the computer's paddle
      arduboy.fillRect(computerx, computery, paddlewidth, paddleheight, WHITE);
      //If the ball is higher than the computer's paddle, move the computer's paddle up
      if (ballx > 115 || random(0, 20) == 1) {
        if (bally < computery) {
          computery = computery - 1;
        }
        //If the bottom of the ball is lower than the bottom of the computer's paddle, move the comptuer's paddle down
        if (bally + ballsize > computery + paddleheight) {
          computery = computery + 1;
        }
      }
      //If the ball moves off of the screen to the left...
      if(ballx < -10) {
        //Move the ball back to the middle of the screen
        ballx = 63;
        //Give the computer a point
        computerscore = computerscore + 1;
      }
      //If the ball moves off of the screen to the right....
      if(ballx > 130) {
        //Move the ball back to the middle of the screen
        ballx = 63;
        //Give the player a point
        playerscore = playerscore + 1;
      }

      //Check if the player wins
      if(playerscore == 5) {
        gamestate = 2;
      }
      //Check if the computer wins
      if(computerscore == 5) {
        gamestate = 3;
      }

      //If the ball makes contact with the player's paddle, bounce it back to the right
      if (ballx == playerx + paddlewidth && playery < bally + ballsize && playery + paddleheight > bally) {
        ballright = 1;
      }
      //If the ball makes contact with the computer's paddle, bounce it back to the left
      if (ballx + ballsize == computerx && computery < bally + ballsize && computery + paddleheight > bally) {
        ballright = -1;
      }
      //Change the gamestate
      if (arduboy.justPressed(A_BUTTON)) {
        gamestate = 2;
      }
      break;
 
    case 2:
      //Win screen
      arduboy.setCursor(0, 0);
      arduboy.print("Win Screen"); 
      //Change the gamestate
      if (arduboy.justPressed(A_BUTTON)) {
        resetGame();
        gamestate = 0;
      }
      break;

    case 3:
      //Game over screen
      arduboy.setCursor(0, 0);
      arduboy.print("Game Over Screen");
      //Change the gamestate
      if (arduboy.justPressed(A_BUTTON)) {
        resetGame();
        gamestate = 0;
      }
      break;
  }

  arduboy.display();
}

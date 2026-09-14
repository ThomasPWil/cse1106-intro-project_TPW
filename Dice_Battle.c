#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
Name: Thomas Wilson
Course: CSE 1320
Assignment: Dice Battle
Description: Game where player and computer roll dices between 1 and 6.
whoever gets the highest role gets a point first to 10 points wins
*/

int playerScore = 0;
int compScore = 0;
int winScore = 10;
int roll = 0;
int min = 0;
int max = 6;

int playerRoll;
int compRoll;

void printTitle()
{
  printf("================================ \n");
  printf("         DICE BATTLE  \n");
  printf("================================ \n");
}

void showScores()
{
  printf("Player Score: %d\n", playerScore);
  printf("Computer Score %d\n", compScore);
}

int rollDie()
{
  int roll = (rand() % max) + 1;
  return roll;
}

void updateScore(int *score, int points)
{
  *score += points;
  
}

void checkForCritFailure()
{
  if(playerRoll == 1 && compRoll != 1)
  {
    printf("Critical Failure player loses a point! \n");
    updateScore(&playerScore, -1);
  }
  else if(compRoll == 1 && playerRoll != 1)
  {
    printf("Critical Failure computer loses a point! \n");
    updateScore(&compScore, -1);
  }
  else if(playerRoll == 1 && compRoll == 1)
  {
    printf("Critical Failure both parties lose a point! \n");
    updateScore(&playerScore, -1);
    updateScore(&compScore, -1);
  }

 
}

void decideWinner(int playerNum, int compNum)
{
  checkForCritFailure();

  if(playerNum > compNum)
  {
    printf("you win the round +1 points! \n");
    updateScore(&playerScore, 1);
  }
  else if(playerNum < compNum)
  {
    printf("Computer wins the round +1 points! \n");
    updateScore(&compScore, 1);
  }
  else if(playerNum == compNum && (playerNum != 1 && compNum != 1))
  {
    printf("Tie! Both players get a point! \n");
    updateScore(&playerScore, 1);
    updateScore(&compScore, 1);
  }

  showScores();

  
}

int quitGame()
{
  printf("quitting game \n");
  exit(0);
  return 0;
}




int mainGame()
{
    char str[100];
    while(playerScore != winScore && compScore != winScore)
    {
      printf("Press 1 to roll the dice...\n");
      fgets(str, sizeof(str), stdin); 
      str[strcspn(str, "\n")] = 0;

      while(strcmp(str, "1") != 0)
      {
       printf("Press 1 to roll the dice...\n");
       fgets(str, sizeof(str), stdin); 
       str[strcspn(str, "\n")] = 0;
      }
     
      playerRoll = rollDie();
      compRoll = rollDie();
    
      printf("-----------------\n");
      printf("Player Rolled: %d\n", playerRoll);
      printf("Computer Rolled: %d\n", compRoll);
      printf("-----------------\n");
  
      decideWinner(playerRoll,compRoll);
     
      if(playerScore != winScore && compScore != winScore)
      {
       printf("-----------------\n");
       printf("NEXT ROUND\n");
       printf("-----------------\n");
      }
    
     if(playerScore == winScore)
     {
        printf("Player wins!\n");
        quitGame();
     }
     else if (compScore == winScore)
     {
       printf("Computer wins!\n");
       quitGame();
       
     }
    }

    str[100] = '\0';
    
   
}




void printOptions()
{
  printf("1. Start Game\n");
  printf("2. Instructions\n");
  printf("3. Quit\n");

  char str[100];
  fgets(str, sizeof(str), stdin); 
  str[strcspn(str, "\n")] = 0;

  while(strcmp(str, "1") != 0 || strcmp(str, "2") != 0 || strcmp(str, "3") != 0)
  {
   if(strcmp(str, "1") == 0)
   {
    mainGame();
   }
   else if(strcmp(str, "2") == 0)
   {
    printInstructions();
   }
   else if(strcmp(str, "3") == 0)
   {
     quitGame();
   }
   else if(strcmp(str, "1") != 0 || strcmp(str, "2") != 0 || strcmp(str, "3") != 0)
   {
    printf("invalid choice \n");
   }
   fgets(str, sizeof(str), stdin); 
   str[strcspn(str, "\n")] = 0;
   str[100] = '\0';
  }

}

void printInstructions()
{
  printf("click 1 to roll the dice \n");
  printf("Dice values for players and computers are randomly generated between (1-6) \n");
  printf("whoever has the highest number gets a point \n");
  printf("However rolling a 1 causes the roller to lose a point \n");
  printf("First to %d wins \n", winScore);
  printf("\n");

  printOptions();
}


int main()
{
  srand(time(NULL));
  printTitle();
  printOptions();
     
  mainGame();
    
  return 0;
    
}

/* reflection questions
1. the program needs a pointer to help modify the players and computers score in one function without having to write extra boilerplate
   by making copies and assigning the copies values to the orginal scores

2.rand() % 6 + 1 is how we generate random numbers between 1 and 6 for the rolls of our dice in the program.

3. one Problem I had was handling edge cases for user inputs so I learned how to use fgets and how to clear the buffer to prevent issues with the input

*/
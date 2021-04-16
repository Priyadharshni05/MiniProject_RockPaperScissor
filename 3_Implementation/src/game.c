#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include "game.h"

//Analyzing User's Choice

int get_user_choice()
{
  char buffer[50];
  char *pos;

  while(1)
  {
    printf("\nPlease select your choice: Rock, Paper, Scissors or Exit: "); //Getting input from user // Should be same as the Choice given (Case Sesitive)
    fgets(buffer,sizeof(buffer), stdin);

    pos = strrchr(buffer, '\n');
    if (pos != NULL)
      *pos = '\0'; // remove trailing \n

    if (strcmp(buffer, "Rock") == EQUAL)
      return ROCK;
    else if (strcmp(buffer, "Scissors") == EQUAL)
      return SCISSORS;
    else if (strcmp(buffer, "Paper") == EQUAL)
      return PAPER;
    else if (strcmp(buffer, "Exit") == EQUAL)
      return EXIT;
  }
  return 0;
}

//Generating Computer's Choice

int get_pc_choice()
{
  return rand() % 3;
}

//Determining the winer
int get_result(int user, int pc)
{
  int i;

  REQUIRE(user >= 0 && user <= 2);
  REQUIRE(pc >= 0 && pc <= 2);

  for (i = 0; i < NUM_RESULTS; ++i)
  {
    if (results[i].user == user && results[i].pc == pc)
      break;
  }
  ENSURE(i >= 0 && i < NUM_RESULTS);

  return results[i].result;
}

//Displaying the Winner
void output_result(int user, int pc, int result)
{
  const char *result_names[] = {"Computer won", "Player won", "Draw"};
  const char *choices[] = {"Rock", "Paper", "Scissors"};

  REQUIRE(result >= COMPUTER_WON && result <= DRAW);
  REQUIRE(user >= ROCK && user <= SCISSORS);
  REQUIRE(pc >= ROCK && pc <= SCISSORS);

  printf("\nYour choice: %s", choices[user]);
  printf("\nComputer's choice: %s", choices[pc]);
  printf("\nResult: %s", result_names[result - 4]);
}

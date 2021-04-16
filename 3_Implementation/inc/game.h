/**
* @file game.h
* Played against Computer
* @author Priyadharshni N
* @brief This program is to implement the RockPaperScissors Game
* 
* @copyright Copyright (c) 2021
*/
#ifndef __GAME_H__
#define __GAME_H__

#define EQUAL   0

/* The choices for player and computer */

#define   ROCK   0
#define   PAPER    1
#define   SCISSORS 2
#define   EXIT    3

/* Game results */

#define   COMPUTER_WON  4
#define   PLAYER_WON    5
#define   DRAW          6


#define   REQUIRE(cnd)  assert(cnd);
#define   ENSURE(cnd)   assert(cnd);

typedef struct
{
  int user;
  int pc;
  int result;
}output;

/* lookup table for all possible outcomes */

static const output results[] =
{
  {PAPER, PAPER, DRAW},
  {PAPER, ROCK, PLAYER_WON},
  {PAPER, SCISSORS, COMPUTER_WON},

  {ROCK, ROCK, DRAW},
  {ROCK, SCISSORS, PLAYER_WON},
  {ROCK, PAPER, COMPUTER_WON},

  {SCISSORS, SCISSORS, DRAW},
  {SCISSORS, PAPER, PLAYER_WON},
  {SCISSORS, ROCK, COMPUTER_WON},
};

#define NUM_RESULTS   sizeof(results) / sizeof(results[0])

/* Function prototypes */
/**
 * @brief Get the user choice object
 * Gets the user choice 
 * @return int 
 */
int get_user_choice();

/**
 * @brief Get the pc choice object
 * Generate the PC's choice randomly
 * @return int 
 */
int get_pc_choice();

/**
 * @brief Get the result object
 * 
 * @param user ->User's Choice
 * @param pc ->PC's Choice
 * @return int ->Result
 */
int get_result(int user, int pc);

/**
 * @brief Prints the Result
 * 
 * @param user ->User's Choice
 * @param pc ->PC's Choice
 * @param result ->Result
 */
void output_result(int user, int pc, int result);

#endif  /* #define __GAME_H__ */

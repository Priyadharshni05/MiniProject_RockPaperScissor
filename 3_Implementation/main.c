#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "game.h"

int main()
{
    int user,pc,result;
    srand(time(NULL));
    while(1)
    {
        user = get_user_choice(); //Getting input from user
        if(user==EXIT) // game ends
        {
            test_main();
            return 0;
        }
        pc = get_pc_choice(); //Randomly generate PC's choice
        result = get_result(user, pc); //Compte the result
        output_result(user, pc, result); //Display the result
    }
    return 0;
}

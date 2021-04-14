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
        user = get_user_choice();
        if(user==EXIT)
        {
            test_main();
            return 0;
        }
        pc = get_pc_choice();
        result = get_result(user, pc);
        output_result(user, pc, result);
    }
    return 0;
}

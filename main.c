#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers.h"

#define MIN_VALUE 0
#define MAX_VALUE 9 
#define DEFAULT_SIZE 4

int main(int ac, char **argv)
{
    printf("Will you find the secret code?\nPlease enter a valid guess\n");

    int round = 0;//keeps track of rounds played
    int attempts = 10; 
    bool game_over = false;//starts false because it wont stop until gameover is true, when user guesses correct or 10 attempts reaches
    int user_guess[DEFAULT_SIZE]; 
    int secret_code[DEFAULT_SIZE];
    int calculated_correct_guess;//variable for determining if game is over
    bool custom_code = false;//its assumed no custom code has been chosen

    //setting custom number of attempts
    for(int i = 1; i < ac; i++)
    {
        if(strcmp(argv[i], "-t") == 0)
        {
            attempts = atoi(argv[i + 1]);

        }
    }

    //flags for setting your own seceret code
    for(int i = 1; i < ac; i++) //starting at the second(1st index) argument. 
    {
        if(strcmp(argv[i], "-c") == 0)
        {
            //take input at 2nd indices ac as a string
            //printf("argv[%i + 1]%s\n",i, argv[i + 1]);
            custom_code = true;
            i++;
            for(int j = 0; j < DEFAULT_SIZE && i < ac ; j++)//finds each digit inside string input
            {
                if (i < ac)
                {
                    //secret_code[j] = atoi(argv[i]);//didnt work because changes string to integer itself, not each character
                    secret_code[j] = argv[i][j] - '0';
                    //printf("secret_code[%i]\n", secret_code[j]);
                }
              
            }
            //index = i + 1; //program compiles and runs seemingly without errors when this removed?                 
        }
        //printf("secret_code [%i %i %i %i], argv[%s]\n",secret_code[0], secret_code[1], secret_code[2], secret_code[3], argv[i]);
    }

    //If no custom, computer generates a custom code
    if(custom_code != true)
    {
        generate_code(secret_code, DEFAULT_SIZE);
     
    }

    int eof_checker = 0;
    //game flow
    while(round < attempts && !game_over)
    {
        printf("---\nRound %i\n", round);
        get_user_input(user_guess, &eof_checker);
        
        //printf("EOF-> %d\n", eof_checker);

        if (eof_checker == 0) {
            printf("exit");
            return 1;
        }

        calculated_correct_guess = calculate_user_input(user_guess, secret_code);

        if(calculated_correct_guess == 4)
        {
            printf("Congratz! You did it!");
            game_over = true;
            break;
        }
        
        
        round++;
    }

    return 0;
}
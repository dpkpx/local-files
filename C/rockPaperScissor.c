#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

int generateRandom()
{
    srand(time(NULL));
    return rand() % 3;
}

int main(int argc, char const *argv[])

{
    char r;
    int player;
    int game;
    int playerScore = 0;
    int computerScore = 0;
start:

    playerScore = 0;
    computerScore = 0;

    for (int i = 1; i <= 3; i++)
    {

        system("cls");

        printf("Welcome to Rock Paper Scissor Game\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n        Please Enter\n        0 : For Rock\n        1 : For Paper\n        2 : For Scissor\n        ESC to exit anytime\n        Player Score : %d\n        Computer Score : %d\n        Game Left : %d\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n< It's your turn >\n", playerScore, computerScore, (3 - i));
    input:
        r = getch();

        switch (r)
        
        {
        case 48:
            printf(" ----------------------\n| You have chosen Rock |\n ----------------------\n");
            player = 0;

            break;

        case 49:
            printf(" -----------------------\n| You have chosen Paper |\n -----------------------\n");
            player = 1;
            break;
        case 50:
            printf(" -------------------------\n| You has chosen Scissor |\n -------------------------\n");
            player = 2;
            break;
        case 27:
            goto end;
            break;

        default:
            printf("Please enter a valid choice (0-1)\n");
            goto input;
        }
        printf("\n< Now its computer's turn > \n");
        for (int i = 0; i < 1000000000 / 2; i++)
            ;

        int computer = generateRandom();

        switch (computer)
        {
        case 0:
            printf(" ---------------------------\n| Computer has chosen Rock |\n ---------------------------\n");

            break;

        case 1:
            printf(" ----------------------------\n| Computer has chosen Paper |\n ----------------------------\n");

            break;
        case 2:
            printf(" ------------------------------\n| Computer has chosen Scissor |\n ------------------------------\n");

            break;
        }

        if (player == computer)
        {
            printf("< It's a tie >\n");
            i--;
        }
        else if (player == 0 && computer == 2 || player == 2 && computer == 1 || player == 1 && computer == 0)
        {
            printf("\n< Player wins this time >\n");
            playerScore += 1;
        }
        else
        {
            printf("\n< Computer wins this time >\n");
            computerScore += 1;
        }
        printf("Press any key to continue...\n");
       if( getch()==27)goto end;
    }
    system("cls");
    if (playerScore > computerScore)
    {
        printf("\n< Player wins the whole Game >\n  ~~~~~~~~~~~~~~~~~~~~~~~~~~ \n        Player Score : %d \n       Computer Score : %d \n", playerScore, computerScore);
    }
    else if (playerScore < computerScore)
    {
        printf("\n< Computer wins the whole Game >\n  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n        Player Score : %d \n       Computer Score : %d \n", playerScore, computerScore);
    }
    else
    {
        printf("\n< The Game DRAW \n  ~~~~~~~~~~~~~ >\n");
    }

    printf("\n\nWant to play more ?(y/n)");
    game = getch();
    if (game == 'y')
    {
        goto start;
    }
end:
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

char checkResult(char arr[])
{
    int emptyPos=0;

    for (int i = 0; i <= 8; i++)
    {
        if (arr[i] != '@' && arr[i] != 'X')
        {
            emptyPos += 1;
        }
    }

    if (arr[0] == arr[1] && arr[1] == arr[2])
    {
        return arr[0];
    }
    else if (arr[3] == arr[4] && arr[4] == arr[5])
    {
        return arr[3];
    }
    else if (arr[6] == arr[7] && arr[7] == arr[8])
    {
        return arr[6];
    }
    else if (arr[0] == arr[3] && arr[3] == arr[6])
    {
        return arr[0];
    }
    else if (arr[1] == arr[4] && arr[4] == arr[7])
    {
        return arr[1];
    }
    else if (arr[2] == arr[5] && arr[5] == arr[8])
    {
        return arr[2];
    }
    else if (arr[0] == arr[4] && arr[4] == arr[8])
    {
        return arr[0];
    }
    else if (arr[2] == arr[4] && arr[4] == arr[6])
    {
        return arr[2];
    }
    else if (emptyPos == 0)
    {
        return 'T';



    }



    return 48 ;
}



int miniMax(char fchArr[], bool isMax)
{

    // char fchArr[9];

    // fchArr[0] = arr[0];
    // fchArr[1] = arr[1];
    // fchArr[2] = arr[2];
    // fchArr[3] = arr[3];
    // fchArr[4] = arr[4];
    // fchArr[5] = arr[5];
    // fchArr[6] = arr[6];
    // fchArr[7] = arr[7];
    // fchArr[8] = arr[8];

    if (checkResult(fchArr) == 'X')
    {
        return 10;
    }
    else if (checkResult(fchArr) == '@')
    {
        return -10;
    }
    else if (checkResult(fchArr) == 'T')
    {
        return 0;
    }

    if (isMax)
    {
        
        int bestScore = -1000;
        char temp;
        for (int i = 0; i <= 8; i++)
        {

            if (fchArr[i] != '@' && fchArr[i] != 'X')
            {
                temp=fchArr[i];

                fchArr[i] = 'X';

                bestScore = max(bestScore,miniMax(fchArr, !isMax));
                fchArr[i]=temp;

                
            }
        }
        // printf("[best score %d ]", bestScore);
        return bestScore;
    }
    else
    {
        int bestScore = 1000;
        char temp;
        
        for (int i = 0; i <= 8; i++)
        {

            if (fchArr[i] != '@' && fchArr[i] != 'X')
            { temp=fchArr[i];
                

                fchArr[i] = '@';

                bestScore = min(miniMax(fchArr, !isMax), bestScore);
                fchArr[i]=temp;
                
            }
        }
        return bestScore;
    }
}

int move(char fchArr[])
{
    


    int bestScore = -1000;
    int position = -1;
    char temp;

    // char fchArr[9];
    // fchArr[0] = arr[0];
    // fchArr[1] = arr[1];
    // fchArr[2] = arr[2];
    // fchArr[3] = arr[3];
    // fchArr[4] = arr[4];
    // fchArr[5] = arr[5];
    // fchArr[6] = arr[6];
    // fchArr[7] = arr[7];
    // fchArr[8] = arr[8];

    for (int i = 0; i <= 8; i++)
    {

        if (fchArr[i] != '@' && fchArr[i] != 'X')
        { temp=fchArr[i];
            
            fchArr[i] = 'X';

            int score = miniMax(fchArr, false);

            fchArr[i]=temp;
            // printf("{score %d }", score);
            
            if (score > bestScore)
            {
                bestScore = score;
                position = i;
            }
        }
    }
    return position;
}

int main(int argc, char const *argv[])

{
    int compTurn;
    char input;
    int turn;

    char chArr[9];

start:

    turn = 1;

    chArr[0] = '1';
    chArr[1] = '2';
    chArr[2] = '3';
    chArr[3] = '4';
    chArr[4] = '5';
    chArr[5] = '6';
    chArr[6] = '7';
    chArr[7] = '8';
    chArr[8] = '9';

    system("cls");

    printf("\n......................\n|      |      |      |\n|  %c   |  %c   |  %c   |\n|......|......|......|\n|      |      |      |\n|  %c   |  %c   |  %c   |\n|......|......|......|\n|      |      |      |\n|  %c   |  %c   |  %c   |\n|......|......|......|\n", chArr[0], chArr[1], chArr[2], chArr[3], chArr[4], chArr[5], chArr[6], chArr[7], chArr[8]);
next:
// gotoxy(3,3);//for  1
// printf("z");
// gotoxy(10,3);//for  2
// printf("z");
// gotoxy(17,3);//for  3
// printf("z");
// gotoxy(3,6);//for  4
// printf("z");
// gotoxy(10,6);//for  5
// printf("z");
// gotoxy(17,6);//for  6
// printf("z");
// gotoxy(3,9);//for  7
// printf("z");
// gotoxy(10,9);//for  8
// printf("z");
// gotoxy(17,9);//for  9
// printf("z");
// getch();
// return 0;
    
    if (checkResult(chArr) == 'T')
    {
        printf("\nIts a Tie");
        goto end;
    }
    else if (checkResult(chArr) == 'X')
    {
        printf("\nX won the Game");
        goto end;
    }
    else if (checkResult(chArr) == '@')
    {
        printf("\nO won the Game");
        goto end;
    }
    
    if (turn == 0)
    {
        printf("\nYour turn (O's)\nPlease choose between 1 - 9 to fill the position : ");

        do
        {
            input = getch();
        } while (!(input > 48 && input < 58 || input == 27));

        if (input == 27)
        {
            goto end;
        }
        else if (chArr[input - 49] != '@' && chArr[input - 49] != 'X')
        {
            chArr[input - 49] = '@';
            system("cls");
            printf("\n......................\n|      |      |      |\n|  %c   |  %c   |  %c   |\n|......|......|......|\n|      |      |      |\n|  %c   |  %c   |  %c   |\n|......|......|......|\n|      |      |      |\n|  %c   |  %c   |  %c   |\n|......|......|......|\n", chArr[0], chArr[1], chArr[2], chArr[3], chArr[4], chArr[5], chArr[6], chArr[7], chArr[8]);
        }
        else
        {
            printf("\nPosition already taken \nPlease choose another position\n");
            goto next;
        }
        turn = 1;
        goto next;
    }
    else if (turn == 1)
    {
        printf("Computer's turn (X's)");
        for (long double i = 0; i < 1000000000 / 4; i++)
            ;

    again:

        compTurn = move(chArr);

        if (chArr[compTurn] != '@' && chArr[compTurn] != 'X')
        {
            chArr[compTurn] = 'X';
            // getch();
            system("cls");
            printf("\n......................\n|      |      |      |\n|  %c   |  %c   |  %c   |\n|......|......|......|\n|      |      |      |\n|  %c   |  %c   |  %c   |\n|......|......|......|\n|      |      |      |\n|  %c   |  %c   |  %c   |\n|......|......|......|\n", chArr[0], chArr[1], chArr[2], chArr[3], chArr[4], chArr[5], chArr[6], chArr[7], chArr[8]);
        }
        else
        {

            goto again;
        }
        turn = 0;
        goto next;
    }

end:
    printf("\n\nWant to play more ?(y/n)");

    if (getch() == 'y')
    {
        goto start;
    }
    return 0;
}

//MinMax
#include <iostream>
#include <conio.h>
#include <stdbool.h>
using std::cin;
using std::cout;
using std::endl;
char result(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {

        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
    }
    for (int i = 0; i < 3; i++)
    {

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];
    return '0';
}
void update(char board[3][3])
{
    system("cls");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << "\t";
        }
        cout << endl
             << endl
             << endl;
    }
}
bool posLeft(char board[3][3])
{
    for (int i = 0; i < 9; i++)
    {
        if (*(*board + i) != 'X' && *(*board + i) != 'O')
        {
            return true;
        }
    }
    return false;
}
int minMax(char board[3][3], bool isMaxmising)
{
    if (result(board) == 'X')
    {
        return 10;
    }
    if (result(board) == 'O')
    {
        return -10;
    }
    if (!posLeft(board) && result(board) == '0')
    {
        return 0;
    }

    if (isMaxmising)
    {
        int score = -10000;
        for (int i = 0; i < 9; i++)
        {
            if (*(*board + i) != 'X' && *(*board + i) != 'O')
            {
                char temp = *(*board + i);
                *(*board + i) = 'X';
                if (minMax(board, false) > score)
                {
                    score = minMax(board, false);
                }
                *(*board + i) = temp;
            }
        }
        return score;
    }
    else
    {
        int score = 10000;
        for (int i = 0; i < 9; i++)
        {
            if (*(*board + i) != 'X' && *(*board + i) != 'O')
            {
                char temp = *(*board + i);
                *(*board + i) = 'O';
                if (minMax(board, true) < score)
                {
                    score = minMax(board, true);
                }
                *(*board + i) = temp;
            }
        }
        return score;
    }
}
int bestMove(char board[3][3])
{
    int bestScore = -10000;
    int pos;
    for (int i = 0; i < 9; i++)
    {
        if (*(*board + i) != 'X' && *(*board + i) != 'O')
        {
            char temp = *(*board + i);
            *(*board + i) = 'X';
            if (minMax(board, false) > bestScore)
            {
                bestScore = minMax(board, false);
                pos = i;
            }
            *(*board + i) = temp;
        }
    }
    return pos;
}
int main(void)
{
    char player = 'X';

    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

    update(board);
    while (result(board) == '0' && posLeft(board))
    {
        if (player == 'X')
        {
            cout << "X's Turn please choose a valid pos :";
            *(*board + bestMove(board))='X';
            update(board);
            player='O';
            continue;
        }
        else
        {
            cout << "O's Turn please choose a valid pos :";
        }

        int pos = getch();
        if (*(*board + pos - 49) != 'X' && *(*board + pos - 49) != 'O')
        {
            *(*board + pos - 49) = player;
            update(board);
            if (player == 'O')
            {
                player = 'X';
            }
            else
            {
                player = 'O';
            };
        }
        else
        {
            cout << "Please enter a valid position";
            update(board);
        }
    }
    if (result(board) != '0')
    {
        cout << "winner is : " << result(board);
    }
    else if (!posLeft(board))
    {
        cout << "Game Draw ";
    }
}

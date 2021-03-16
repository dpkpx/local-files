#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int main(int argc, char const *argv[])
{
    int p = 4;
    int q =   9;
    int input = max(p, q);
    printf("max is : %d", input);


    return 0;
}



char checkResult(char arr[])
{
    int emptyPos=0;
    int i;

    
    for (i = 0; i <= 8; i++)
    {
        if (arr[i] != 'O' && arr[i] != 'X')
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
    }else if (emptyPos <= 0)
    {
        return 't';
    }
    
    
}

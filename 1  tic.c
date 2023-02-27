//tic tac toe 2 player;
#include <stdio.h>

int counter = 0;

void printboard(char board[4][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkstate(int x, int y, char board[4][4])
{
    if (board[x][y] != '.')
    {
        return 1;
    }
    return 0;
}

int checkwin(char board[4][4], char toCheck)
{
    int i, j, colum, row, diag, revdiag;

    for (j = 1; j < 4; j++)
    {
        colum = 0, row = 0, diag = 0, revdiag = 0;
        for (i = 1; i < 4; i++)
        {
            if (board[j][i] == toCheck)
            {
                colum++;
            }
            if (board[i][j] == toCheck)
            {
                row++;
            }
            if (board[i][i] == toCheck)
            {
                diag++;
            }
            if (board[i][3 - i + 1] == toCheck)
            {
                revdiag++;
            }
        }
        if (colum == 3 || row == 3 || diag == 3 || revdiag == 3)
        {
            counter += 10;
        }
    }
}

void white(char board[4][4])
{
    int x, y;
    printf("enter where you wnat to play X (with x y cordinate)");
    scanf("%d%d", &x, &y);

    if (checkstate(x, y, board) == 1)
    {
        printf("alreay occupied\n");
        counter--;
    }
    else
    {
        board[x][y] = 'X';
    }

    printboard(board);
    checkwin(board, 'X');
}

void black(char board[4][4])
{
    int x, y;
    printf("enter where you wnat to play O (with x y cordinate)");
    scanf("%d%d", &x, &y);

    if (checkstate(x, y, board) == 1)
    {
        printf("alreay occupied\n");
    }
    else
    {
        board[x][y] = 'O';
    }

    printboard(board);
    checkwin(board, 'O');
}

int main()
{
    printf("2 player tic tac toe\n");
    char board[4][4] = {
        'c', '1', '2', '3',
        '1', '.', '.', '.',
        '2', '.', '.', '.',
        '3', '.', '.', '.'};

    printboard(board);

    while (counter < 9)
    {

        if (counter % 2 == 0)
        {
            white(board);
        }
        else if (counter % 2 != 0)
        {
            black(board);
        }
        if (counter < 10)
        {
            printf("\n\nnext turn\n");
        }

        counter++;
    }

    if (counter % 2 == 0)
    {
        printf("O wins");
    }
    else if (counter % 2 != 0)
    {
        printf("X wins");
    }
    printf("\ngame over");

    return 0;
}
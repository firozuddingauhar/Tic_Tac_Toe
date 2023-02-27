// tic tac toe 2 player (version 2.0);
#include <stdio.h>

int counter = 0;

void printboard(char board[9])
{
    printf("%c %c %c\n", board[0], board[1], board[2]);
    printf("%c %c %c\n", board[3], board[4], board[5]);
    printf("%c %c %c\n", board[6], board[7], board[8]);
    printf("\n");
}

int checkwin(char board[9], char toCheck)
{
    if (board[0] == board[1] && board[1] == board[2] && board[2] == toCheck ||
        board[3] == board[4] && board[4] == board[5] && board[5] == toCheck ||
        board[6] == board[7] && board[7] == board[8] && board[8] == toCheck ||
        board[0] == board[3] && board[3] == board[6] && board[6] == toCheck ||
        board[1] == board[4] && board[4] == board[7] && board[7] == toCheck ||
        board[2] == board[5] && board[5] == board[8] && board[8] == toCheck ||
        board[0] == board[4] && board[4] == board[8] && board[8] == toCheck ||
        board[2] == board[4] && board[4] == board[6] && board[6] == toCheck)
    {
        counter += 10;
        printf("%c Wins", toCheck);
        return 1;
    }
}

void playerMove(char board[9], char piece)
{
    int x;
    printf("Enter where you wnat to play %c (with refrence to rule board)", piece);
    scanf("%d", &x);
    intertLetterandCheck(board,x,piece);
    if (board[x] != '.')
    {
        printf("Alreay occupied\n");
        counter--;
    }
    else
    {
        board[x] = piece;
    }

    printboard(board);
    if (checkwin(board, piece) != 1)
    {
        printf("\n\nnext turn\n");
    }
}

int main()
{
    printf("2 player tic tac toe\n");
    printf("To play you enter a number corresponding to a tile ,like so\n");
    printf("0 1 2\n3 4 5\n6 7 8\n");
    printf("\n");
    char board[9] = {
        '.', '.', '.',
        '.', '.', '.',
        '.', '.', '.'};

    printboard(board);

    while (counter < 9)
    {

        if (counter % 2 == 0)
        {
            playerMove(board,'X');
        }
        else if (counter % 2 != 0)
        {
            playerMove(board, 'O');
        }

        counter++;
    }
    if (counter == 9)
    {
        printf("Draw");
    }

    printf("\nGame over");

    return 0;
}
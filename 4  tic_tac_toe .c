// tic tac toe 1 player  2.0
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[9] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};

void printboard()
{
    printf("%c %c %c\n", board[0], board[1], board[2]);
    printf("%c %c %c\n", board[3], board[4], board[5]);
    printf("%c %c %c\n", board[6], board[7], board[8]);
    printf("\n");
}

int checkwin(char toCheck)
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
        return 1;
    }
}

int checkDraw()
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == '.')
        {
            return 0;
        }
    }
    return 1;
}

void intertLetterandCheck(char letter, int postion)
{
    if (board[postion] == '.')
    {
        board[postion] = letter;
        printboard(board);
        if (checkwin(letter) == 1)
        {
            printf("%c Won", letter);
            exit(0);
        }
        else if (checkDraw() == 1)
        {
            printf("Draw");
            exit(0);
        }
    }
    else
    {
        int x;
        printf("Invalid move");
        printf("Enter another position: ");
        scanf("%d", &x);
        intertLetterandCheck('O', x);
    }
}

int playMove()
{
    int x;
    printf("Enter whree you want to play: ");
    scanf("%d", &x);
    intertLetterandCheck('O', x);
}

int minimax(char board[9], bool isMaximizing)
{
    int bestScore;
    int score, i;

    if (checkwin('X') == 1)
    {
        return 1;
    }
    else if (checkwin('O') == 1)
    {
        return -1;
    }
    else if (checkDraw() == 1)
    {
        return 0;
    }

    if (isMaximizing)
    {
        bestScore = -69;
        for (i = 0; i < 9; i++)
        {
            if (board[i] == '.')
            {
                board[i] = 'X';
                score = minimax(board, 0);
                board[i] = '.';
                if (score > bestScore)
                {
                    bestScore = score;
                }
            }
        }
        return bestScore;
    }
    else
    {
        bestScore = 69;
        for (i = 0; i < 9; i++)
        {
            if (board[i] == '.')
            {
                board[i] = 'O';
                score = minimax(board, 1);
                board[i] = '.';
                if (score < bestScore)
                {
                    bestScore = score;
                }
            }
        }
        return bestScore;
    }
}

void botMove()
{
    int i, bestScore = -69;
    int score, bestMove = 0;
    for (i = 0; i < 9; i++)
    {
        if (board[i] == '.')
        {
            board[i] = 'X';
            score = minimax(board, 0);
            board[i] = '.';
            if (score > bestScore)
            {
                bestScore=score;
                bestMove = i;
            }
        }
    }
    intertLetterandCheck('X', bestMove);
}

int main()
{
    printf("Tic Tac Toe game");
    printf("Refrence board:\n");
    printf("0 1 2\n3 4 5\n6 7 8\n\n");
    while (1)
    {
        botMove();
        playMove();
    }
}
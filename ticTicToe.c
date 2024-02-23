#include <stdio.h>

char gameboard[3][3];

void initializeGameBoard() {
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            gameboard[row][column] = '_';
        }
    }
}

int checkForWin() {
    // Check all horizontals and verticals
    for (int i = 0; i < 3; i++) {
        if (gameboard[i][0] == gameboard[i][1] && gameboard[i][1] == gameboard[i][2] && gameboard[i][1] != '_')
            return gameboard[i][0] == 'X' ? 1 : 0;

        if (gameboard[0][i] == gameboard[1][i] && gameboard[1][i] == gameboard[2][i] && gameboard[1][i] != '_')
            return gameboard[0][i] == 'X' ? 1 : 0;
    }

    // Check main diagonal (top-left to bottom-right)
    if (gameboard[0][0] == gameboard[1][1] && gameboard[1][1] == gameboard[2][2] && gameboard[1][1] != '_')
        return gameboard[1][1] == 'X' ? 1 : 0;

    // Check anti-diagonal (top-right to bottom-left)
    if (gameboard[0][2] == gameboard[1][1] && gameboard[1][1] == gameboard[2][0] && gameboard[1][1] != '_')
        return gameboard[1][1] == 'X' ? 1 : 0;

    return -1; // No winner yet
}


int markBoard(int x, int y, char marker) {
    if (x >= 3 || y >= 3 || x < 0 || y < 0 || gameboard[x][y] != '_') {
        printf("Invalid position\n");
        return -1;
    } else {
        gameboard[x][y] = marker;
    }
    return 1;
}

void printBoard() {
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            printf("%c ", gameboard[row][column]);
        }
        printf("\n");
    }
}

int main() {
    // initialize the gameboard with "_"
    initializeGameBoard();

    char currentPlayer = 'X';

    while (checkForWin() == -1 || checkForWin() == 0) {
        printBoard();

        int x, y;

        printf("Current player: %c\n", currentPlayer);
        printf("Enter the x y coordinate:-\n");

        scanf("%d %d", &x, &y);

        while (markBoard(x, y, currentPlayer) == -1) {
            printf("Enter a valid position:\n");
            scanf("%d %d", &x, &y);
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // print who won by using checkForWin
    if (checkForWin() == 1)
        printf("Player X wins!\n");
    else if (checkForWin() == 0)
        printf("Player O wins!\n");
    else
        printf("It's a draw!\n");

    return 0;
}

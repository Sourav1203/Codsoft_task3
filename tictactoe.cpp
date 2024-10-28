#include<iostream>
#include<ctime>
using namespace std;

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main() {
    char spaces[9];
    char player = 'X';
    char computer = 'O';
    bool running = true;
    char playAgain;

    do {
        // Reset board for a new game
        for (int i = 0; i < 9; i++) {
            spaces[i] = ' ';
        }

        running = true;
        drawBoard(spaces);

        while (running) {
            playerMove(spaces, player);
            drawBoard(spaces);
            if (checkWinner(spaces, player, computer)) {
                running = false;
                break;
            } else if (checkTie(spaces)) {
                running = false;
                break;
            }

            computerMove(spaces, computer);
            drawBoard(spaces);
            if (checkWinner(spaces, player, computer)) {
                running = false;
                break;
            } else if (checkTie(spaces)) {
                running = false;
                break;
            }
        }

        // Ask if players want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

void drawBoard(char *spaces) {
    cout << "\n";
    cout << "     |     |     " << endl;
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << endl;
    cout << "     |     |     " << endl;
    cout << "\n";
}

void playerMove(char *spaces, char player) {
    int num;
    do {
        cout << "Enter a spot to place a marker (1-9): ";
        cin >> num;
        num--;
        if (spaces[num] == ' ') {
            spaces[num] = player;
            break;
        } else {
            cout << "Spot already taken! Try again.\n";
        }
    } while (num < 0 || num > 8);
}

void computerMove(char *spaces, char computer) {
    int num;
    srand(time(0));

    while (true) {
        num = rand() % 9;
        if (spaces[num] == ' ') {
            spaces[num] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer) {
    if ((spaces[0] == spaces[1] && spaces[1] == spaces[2] && spaces[0] != ' ') ||
        (spaces[3] == spaces[4] && spaces[4] == spaces[5] && spaces[3] != ' ') ||
        (spaces[6] == spaces[7] && spaces[7] == spaces[8] && spaces[6] != ' ') ||
        (spaces[0] == spaces[3] && spaces[3] == spaces[6] && spaces[0] != ' ') ||
        (spaces[1] == spaces[4] && spaces[4] == spaces[7] && spaces[1] != ' ') ||
        (spaces[2] == spaces[5] && spaces[5] == spaces[8] && spaces[2] != ' ') ||
        (spaces[0] == spaces[4] && spaces[4] == spaces[8] && spaces[0] != ' ') ||
        (spaces[2] == spaces[4] && spaces[4] == spaces[6] && spaces[2] != ' ')) {
        
        if (spaces[0] == player || spaces[1] == player || spaces[2] == player || 
            spaces[3] == player || spaces[4] == player || spaces[5] == player || 
            spaces[6] == player || spaces[7] == player || spaces[8] == player) {
            cout << "YOU WIN!\n";
        } else {
            cout << "YOU LOSE!\n";
        }
        return true;
    }
    return false;
}

bool checkTie(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    cout << "IT'S A TIE!\n";
    return true;
}

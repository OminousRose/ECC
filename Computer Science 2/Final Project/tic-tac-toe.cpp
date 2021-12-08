#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

// Dimensions of game board
#define ROWS 5
#define COLS 5

using namespace std;

// Validates player character
bool validateChoice(const string &playerChoice)
{

    if (playerChoice.length() != 1 || !isalpha(playerChoice[0]))
    {
        cout << "Invalid selection. Please pick only one alphabet keyboard." << endl;
        return false;
    }

    return true;
}

// Validates player names
bool validateName(const string &playerName)
{
    if (playerName.length() < 2)
    {
        cout << "Invalid name. Name has to be more than one character." << endl;
        return false;
    }

    return true;
}

// Sets up the game board for the beginning
void initializeBoard(char board[][COLS])
{
    board[0][0] = ' ', board[0][1] = '|', board[0][2] = ' ', board[0][3] = '|', board[0][4] = ' ';
    board[1][0] = '-', board[1][1] = '+', board[1][2] = '-', board[1][3] = '+', board[1][4] = '-';
    board[2][0] = ' ', board[2][1] = '|', board[2][2] = ' ', board[2][3] = '|', board[2][4] = ' ';
    board[3][0] = '-', board[3][1] = '+', board[3][2] = '-', board[3][3] = '+', board[3][4] = '-';
    board[4][0] = ' ', board[4][1] = '|', board[4][2] = ' ', board[4][3] = '|', board[4][4] = ' ';
}

// Goes through matrix and prints the game board
void printGameBoard(char board[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void displayInstructions(int turnCount, string playerOneName, string playerTwoName)
{
    if (turnCount % 2 == 0)
    {
        cout << endl;
        cout << "Player " + playerOneName + ", place a character on location (1-9) on board" << endl;
    }
    else
    {
        cout << endl;
        cout << "Player " + playerTwoName + ", place a character on location (1-9) on board" << endl;
    }

    cout << endl;
}

// Validates move and places character on board
bool validateMove(char board[][COLS], vector<int> &validMovesVector, string playerOneChoice, string playerTwoChoice, int turnCount)
{
    int playerMove;
    cin >> playerMove;

    string playerCharacter = "";

    // Input validation for location on board
    if (playerMove > 9 || playerMove < 1)
    {
        cout << "Invalid move. Move must be (1-9)" << endl;
        // This stops cin bad input flag if entered info is incorrect type
        cin.clear();
        cin.ignore();

        return false;
    }
    else
    {
        // Returns iterator based on whether element is found
        auto it = find(validMovesVector.begin(), validMovesVector.end(), playerMove);

        // Not found, thus space is available - Add to vector
        if (it == validMovesVector.end())
            validMovesVector.push_back(playerMove);
        // If iterator returned, that means element is found, thus occupied space
        else
        {
            cout << "Invalid move. Move must not be occupied" << endl;
            return false;
        }
    }

    // Decides what character we're using based on turn
    if (turnCount % 2 == 0)
        playerCharacter = playerOneChoice;
    else
        playerCharacter = playerTwoChoice;

    // Places character on desired location on board
    switch (playerMove)
    {
    case 1:
        board[0][0] = playerCharacter[0];
        break;
    case 2:
        board[0][2] = playerCharacter[0];
        break;
    case 3:
        board[0][4] = playerCharacter[0];
        break;
    case 4:
        board[2][0] = playerCharacter[0];
        break;
    case 5:
        board[2][2] = playerCharacter[0];
        break;
    case 6:
        board[2][4] = playerCharacter[0];
        break;
    case 7:
        board[4][0] = playerCharacter[0];
        break;
    case 8:
        board[4][2] = playerCharacter[0];
        break;
    case 9:
        board[4][4] = playerCharacter[0];
        break;
    default:
        break;
    }
    return true;
}

// Checks win conditions for tic tac toe
bool gameStatus(char board[][COLS], string playerOneName, string playerTwoName, string playerOneChoice, string playerTwoChoice)
{
    cout << endl;

    if (board[0][0] == playerOneChoice[0] && board[0][2] == playerOneChoice[0] && board[0][4] == playerOneChoice[0] ||
        board[2][0] == playerOneChoice[0] && board[2][2] == playerOneChoice[0] && board[2][4] == playerOneChoice[0] ||
        board[4][0] == playerOneChoice[0] && board[4][2] == playerOneChoice[0] && board[4][4] == playerOneChoice[0] ||
        board[0][0] == playerOneChoice[0] && board[2][0] == playerOneChoice[0] && board[4][0] == playerOneChoice[0] ||
        board[0][2] == playerOneChoice[0] && board[2][2] == playerOneChoice[0] && board[4][2] == playerOneChoice[0] ||
        board[0][4] == playerOneChoice[0] && board[2][4] == playerOneChoice[0] && board[4][4] == playerOneChoice[0] ||
        board[0][0] == playerOneChoice[0] && board[2][2] == playerOneChoice[0] && board[4][4] == playerOneChoice[0] ||
        board[0][4] == playerOneChoice[0] && board[2][2] == playerOneChoice[0] && board[4][0] == playerOneChoice[0])
    {
        cout << "Congratulations " + playerOneName + "!" << endl;
        return true;
    }

    if (board[0][0] == playerTwoChoice[0] && board[0][2] == playerTwoChoice[0] && board[0][4] == playerTwoChoice[0] ||
        board[2][0] == playerTwoChoice[0] && board[2][2] == playerTwoChoice[0] && board[2][4] == playerTwoChoice[0] ||
        board[4][0] == playerTwoChoice[0] && board[4][2] == playerTwoChoice[0] && board[4][4] == playerTwoChoice[0] ||
        board[0][0] == playerTwoChoice[0] && board[2][0] == playerTwoChoice[0] && board[4][0] == playerTwoChoice[0] ||
        board[0][2] == playerTwoChoice[0] && board[2][2] == playerTwoChoice[0] && board[4][2] == playerTwoChoice[0] ||
        board[0][4] == playerTwoChoice[0] && board[2][4] == playerTwoChoice[0] && board[4][4] == playerTwoChoice[0] ||
        board[0][0] == playerTwoChoice[0] && board[2][2] == playerTwoChoice[0] && board[4][4] == playerTwoChoice[0] ||
        board[0][4] == playerTwoChoice[0] && board[2][2] == playerTwoChoice[0] && board[4][0] == playerTwoChoice[0])
    {
        cout << "Congratulations " + playerTwoName + "!" << endl;
        return true;
    }

    return false;
}

int main()
{

    // Player names variables
    string playerOneName = "", playerTwoName = "";
    string playerOneChoice = "", playerTwoChoice = "";

    // Win condition
    bool gameWon = false;

    // Valid inputs
    bool oneNameValid = false, oneCharValid = false, twoNameValid = false, twoCharValid = false, validMove = false;

    // Game board
    char gameBoard[ROWS][COLS] = {};

    // Player turns
    int turnCount = 0;

    vector<int> validMovesVector = {};

    // Enter player one's name. Validation of at least length 2.
    while (!oneNameValid)
    {
        cout << "Enter player one's name: " << endl;
        cin >> playerOneName;

        oneNameValid = validateName(playerOneName);
    }

    // Enter player two's name. Validation of at least length 2.
    while (!twoNameValid)
    {
        cout << "Enter player two's name: " << endl;
        cin >> playerTwoName;

        twoNameValid = validateName(playerTwoName);
    }

    // Enter player one's character selection. Validation of only 1 alphabet character.
    while (!oneCharValid)
    {
        cout << "Enter " + playerOneName + "'s alphabet character (a-z)" << endl;
        cin >> playerOneChoice;

        oneCharValid = validateChoice(playerOneChoice);
    }
    // Enter player two's character selection. Validation of only 1 alphabet character.
    while (!twoCharValid)
    {
        cout << "Enter " + playerTwoName + "'s alphabet character (a-z)" << endl;
        cin >> playerTwoChoice;

        // Validate Player Selection
        twoCharValid = validateChoice(playerTwoChoice);
    }

    // Draw out initial game board
    initializeBoard(gameBoard);

    cout << "Welcome to the game of Tic-Tac-Toe!" << endl;
    cout << endl;

    // Execute as long as the game has not been won
    while (!gameWon)
    {
        // Read instructions per player
        displayInstructions(turnCount, playerOneName, playerTwoName);

        // Print game board every round
        printGameBoard(gameBoard);

        // Get player move and validate
        while (!validMove)
        {
            validMove = validateMove(gameBoard, validMovesVector, playerOneChoice, playerTwoChoice, turnCount);
        }

        gameWon = gameStatus(gameBoard, playerOneName, playerTwoName, playerOneChoice, playerTwoChoice);

        // Increase turn
        turnCount++;
        // Reset valid move
        validMove = false;
    }

    cout << endl;

    // Display board final time
    printGameBoard(gameBoard);

    // Clear vector elements
    validMovesVector.clear();

    cout << endl;

    cout << "Game over" << endl;

    return 0;
}
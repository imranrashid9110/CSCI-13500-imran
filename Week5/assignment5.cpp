#include <iostream>  // lets us use cout and cin
#include <string>    // lets use use strings
#include <cstdlib>   // lets us use rand() and srand()
#include <ctime>     // lets us use time()

using namespace std;

void welcomeMessage() { // function that shows the game title and rules
    cout << "Rock Paper Scissor Game" << endl; // prints the game title
    cout << "First to get 2 points wins." << endl; // prints the rule of the game
} 

bool validMove(string move) { // bool function that checks if the player's move is valid
    if (move == "rock") { // if statement, if its equal to rock, it will return true
        return true; // returns true 
    } 
    else if (move == "paper") { // if the move is paper, it will return true
        return true; // returns true 
    } 
    else if (move == "scissor") { // if the move is scissor
        return true; // returns true 
    } // 
    else { // this makes sure it takes into account of other inputs besides rock paper scissor
        return false; // returns false because the input is invalid
    }  
} // end of the bool function

string playerMove() { // string function that gets the player's move
    string playerMove; // creates a string variable to store the player's input

    cout << "Enter rock, paper, or scissor: "; // asks the player for a move
    cin >> playerMove; // stores the player's input in the variable playerMove

    while (validMove(playerMove) == false) { // loops intul the player inputs a valid move
        cout << "Invalid move. Enter rock, paper, or scissor: "; // tells the player to try again
        cin >> playerMove; // stores the new input in playerMove variable
    } 

    return playerMove; 
} // playerMove function ends

string botMove() { // string function unction that gets the bots move
    int randomNum; // creates an int variable f

    randomNum = rand() % 3; // generates a random number between 0 and 2

    if (randomNum == 0) { // if the random number is 0
        return "rock"; // it returns rock 
    } 
    else if (randomNum== 1) { // if its not 0 then it checks if its 1
        return "paper"; // returns paper
    } 
    else if (randomNum == 2) { // if the random number is 2
        return "scissor"; // Computer chooses scissor
    } 
} // botmove function ends

bool playerWins(string playerMove, string computerMove) { // this bool function checks if the player won
    if (playerMove == "rock" && computerMove == "scissor") { // makes a and conditional, if the player chose rock and the bot chose scissor, the player wins
        return true; // returns true if the player won
    } 
    else if (playerMove == "paper" && computerMove == "rock") { // if the player chooses paper and the bot chose rock, the player wins
        return true; // returns true if the player won
    } 
    else if (playerMove == "scissor" && computerMove == "paper") { // if the player chose scissor and the bot chose paper, the player wins
        return true; // returns true if the player won
    } 
    else { 
        return false; // returns false if the player did not win
    } 
} // playerWins function ends

void scoreUpdate(string playerMove, string computerMove, int& playerScore, int& computerScore) { // this is a pass by reference function that updates the score
    if (playerMove == computerMove) { // checks if the player and computer chose the same move
        cout << "This round is a tie." << endl; 
    } 
    else if (playerWins(playerMove, computerMove) == true) { // if the player won
        playerScore = playerScore + 1; // it adds 1 point to the players score
        cout << "You won this round." << endl; 
    } 
    else { 
        computerScore = computerScore + 1; // if the top if isnt true, it adds 1 point to the bots score
        cout << "Computer won this round." << endl; 
    } 
} 

void displayScore(int playerScore, int computerScore) { // this function displays the score
    cout << "Player Score: " << playerScore << endl; // prints the player score
    cout << "Computer Score: " << computerScore << endl; // prints the bots score
} // displayScore function ends

bool gameOver(int playerScore, int computerScore) { // this function determines if the game is over
    if (playerScore == 2 || computerScore == 2) { // makes a or condition, if either the player or computer has 2 points, the game is over
        return true; // returns true if the game is over
    } 
    else { // if no one scores 2 points, the game is not over
        return false; // game is not over
    } 
} // gameOver function ends

void finalDisplayWinner(int playerScore, int computerScore) { // this function displays the final winner
    if (playerScore > computerScore) { // if player score has more points than the computer, the player wins
        cout << "Player wins the game!" << endl; 
    } 
    else if (computerScore > playerScore) { // if the computer score has more points than the player, the computer wins 
        cout << "Computer wins the game!" << endl; 
    } 
    else { // if they have the same score, the result is a tie
        cout << "The game is a tie." << endl; 
    } 
} // end of finalDisplayWinner function

int main() { // the program starts from here
    srand(time(0)); // gives a random number based on the time

    int playerScore = 0; // player score starts at 0
    int computerScore = 0; // computer score starts at 0

    string playerMove; // creates a string variable for the player's move
    string computerMove; // creates a string variable for the computer's move

    int round = 1; // the counter starts at 1

    welcomeMessage(); // Calls the function that shows the title and rules

    while (gameOver(playerScore, computerScore) == false && round <= 3) { // while loop runs until either they have 2 points or the round is greater than 3, the game will continue, i wasnt able to write this part without ai help.
        cout << endl; 
        cout << "Round " << round << endl; // prints the round number

        playerMove = playerMove(); // players move
        computerMove = botMove(); // bots move

        cout << "Computer picked: " << computerMove << endl; // prints the computer's move

        scoreUpdate(playerMove, computerMove, playerScore, computerScore); 

        displayScore(playerScore, computerScore); // shows the currernt score

        round = round + 1; // adds 1 to the answer to go to the next round
    } // end of while loop

    cout << endl; 

    finalDisplayWinner(playerScore, computerScore); // gets the final winner and displays it

    return 0; 
} // main function ends
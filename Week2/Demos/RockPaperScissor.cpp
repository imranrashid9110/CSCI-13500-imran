#include <iostream>
#include <random>
#include <string>

int main(){

    int player_score = 0;
    int bot_score = 0;
    std::string player_move = "";
    int bot_move = 0;
    std::string bot_pick = ""; 

    std::cout << "Rock Paper Scissor Game" << std::endl;
    std::cout << "First to 2 points wins." << std::endl;

    for (int rounds = 0; rounds < 3; rounds++){

        if (player_score >= 2 || bot_score >= 2){
            break;
        }

        std::cout << "\nRound " << rounds + 1 << std::endl;
        std::cout << "Choose rock, paper or scissor: ";
        std::cin >> player_move;

        while (player_move != "rock" && player_move != "paper" && player_move != "scissor"){
            std::cout << "Wrong input. Choose rock, paper or scissor: ";
            std::cin >> player_move;
        }

        bot_move = rand() % 3;

        if (bot_move == 0){
            bot_pick = "rock";
        }
        else if (bot_move == 1){
            bot_pick = "paper";
        }
        else{
            bot_pick = "scissor";
        }

        std::cout << "Bot picked: " << bot_pick << std::endl;

        if (player_move == bot_pick){
            std::cout << "Tie round." << std::endl;
        }
        else if (player_move == "rock" && bot_pick == "scissor"){
            player_score++;
            std::cout << "You won this round." << std::endl;
        }
        else if (player_move == "paper" && bot_pick == "rock"){
            player_score++;
            std::cout << "You won this round." << std::endl;
        }
        else if (player_move == "scissor" && bot_pick == "paper"){
            player_score++;
            std::cout << "You won this round." << std::endl;
        }
        else{
            bot_score++;
            std::cout << "Bot won this round." << std::endl;
        }

        std::cout << "Score: Player " << player_score << " - Bot " << bot_score << std::endl;
    }

    if (player_score > bot_score){
        std::cout << "\nPlayer wins!" << std::endl;
    }
    else if (bot_score > player_score){
        std::cout << "\nBot wins!" << std::endl;
    }
    else{
        std::cout << "\nTie!" << std::endl;
    }

}
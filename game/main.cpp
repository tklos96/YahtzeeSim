#include "Yahtzee.h"

#include <iostream>


int main() {
    const int nRerolls = 2; //max number of rerolls allowed

    // Print welcome message
    std::cout << "Welcome to YahtzeeSim!" << std::endl;

    // Game mode select
    int gameNum;
    bool fun;
    std::cout << "Which game mode would you like to play?" << std::endl;
    std::cout << "(1) Standard Yahtzee\n(2) Fun Yahtzee" << std::endl;
    std::cout << "Choose mode: (1/2) ";
    std::cin >> gameNum;
    if(gameNum==2) fun=true;
    else fun=false;

    //Set up session
    //auto dist = std::uniform_int_distribution(0,6);
    int winnings = 0;

    std::string cont = "y";
    while(cont == "y") {

        Yahtzee game = Yahtzee(fun);
        
        std::cout << "Rolling initial dice..." << std::endl;
        std::cout << game.printDice() << std::endl;

        // ask for rerolls
        std::string reroll;
        for(int r=0; r<nRerolls; ++r) {
            std::cout << "Reroll? (y/n) ";
            std::cin >> reroll;
            if (reroll=="y") {
                game.reroll(6);
                std::cout << "Rerolling dice..." << std::endl;
                std::cout << game.printDice() << std::endl;
            } else {
                break;
            }
        }

        int payout = game.payout();
        winnings += payout;
        if (payout>0) {
            std::cout << "Congratulations! You won $" << payout << std::endl;
        } else {
            std::cout << "Try again next time!" << std::endl;
        }

        std::cout << "Your total winnings: $" << winnings << std::endl;
        std::cout << "Continue playing? (y/n) ";
        std::cin >> cont;

    }



    return 0;
}

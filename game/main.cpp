#include "Yahtzee.h"

#include <iostream>
#include <random>


int main() {
    // Seed pseudo-random number generator with a non-deterministic
    // random number from the device.
    std::random_device rd;
    std::default_random_engine generator{rd()};

    // Print welcome message and game mode select
    std::cout << "\n==============================\n" << std::endl;
    std::cout << "Welcome to YahtzeeSim!\n" << std::endl;

    int gameNum;
    bool fun;
    std::cout << "Which game mode would you like to play?" << std::endl;
    std::cout << "(1) Standard Yahtzee\n(2) Fun Yahtzee" << std::endl;
    std::cout << "Choose mode: (1/2) ";
    std::cin >> gameNum;
    if(gameNum==2) fun=true;
    else fun=false;
    std::cout << "\n==============================\n" << std::endl;

    int winnings = 0;

    // Main game loop
    std::string cont = "y";
    while(cont == "y") {

        // Initialize game and do initial rolls
        Yahtzee game = Yahtzee(fun,generator);
        
        std::cout << "Rolling initial dice..." << std::endl;
        std::cout << game.printDice() << std::endl;

        // Ask for rerolls, up to 2
        std::string reroll;
        for(int r=0; r<2; ++r) {
            std::cout << "Reroll? (y/n) ";
            std::cin >> reroll;
            if (reroll=="y") {
                game.reroll(6,generator);
                std::cout << "Rerolling dice..." << std::endl;
                std::cout << game.printDice() << std::endl;
            } else {
                break;
            }
        }

        // Give player payout depending on results, add to total winnings
        int payout = game.payout();
        winnings += payout;
        if (payout>0) {
            std::cout << "Congratulations! You won $" << payout << std::endl;
        } else {
            std::cout << "Good luck next time!" << std::endl;
        }

        // Play again if the player wants
        std::cout << "Your total winnings: $" << winnings << std::endl;
        std::cout << "Continue playing? (y/n) ";
        std::cin >> cont;
        std::cout << "\n==============================\n" << std::endl;

    }



    return 0;
}

#include "Yahtzee.h"


int main() {
    const int nRerolls = 2; //max number of rerolls allowed

    // Print welcome message
    std::cout << "Welcome to YahtzeeSim!" << std::endl;

    // Game mode select
    int gameNum;
    bool fun;
    std::cout << "Which game mode would you like to play?" << std::endl;
    std::cout << "(1) Standard Yahtzee\n(2)Fun Yahtzee" << std::endl;
    std::cout << "Choose mode: (1/2) ";
    gameNum << std::cin;
    if(gameNum==2) fun=true;
    else fun=false;

    //Set up session
    auto dist = std::uniform_int_distribution(0,6);
    int winnings = 0;

    std::string cont = "y";
    while(cont == "y") {

        Yahtzee game = Yahtzee(dist,fun);

        std::cout << game.printDice();

        // ask for rerolls
        std::string reroll;
        for(int r=0; r<nRerolls; ++r) {
            std::cout << "Reroll? (y/n) ";
            reroll << std::cin;
            if (reroll=="y") {
                game.reroll();
                std::cout << "Current dice: " << std::endl;
                std::cout << game.printDice();
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
        cont << std::cin;

    }



    return 0;
}

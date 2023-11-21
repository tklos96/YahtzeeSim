#include "Yahtzee.h"

#include <string>
#include <iostream>
#include <random>


int main() {
    const int nTrials = 500;
    const int nLogSteps = 10;

    //Set up session
    std::random_device rd;
    std::default_random_engine generator{rd()};

    std::vector<int> rollCountsFair(6,0);
    std::vector<int> rollCountsFixed(6,0);
    
    {
    //Run Trials for Standard Yahtzee
    std::cout << "Standard Yahtzee\n";
    std::cout << "nTrials=" << nTrials << "\n";
    std::cout << "trials,nYahtzee,nFourOfAKind,winnings\n";
    int l=0;
    int nYahtzee=0, nFourOfAKind=0;
    int winnings = 0;
    for(int n=0; n<nTrials; ++n) {

        Yahtzee game = Yahtzee(false,generator);
        game.reroll(6,generator);
        game.reroll(6,generator);
        int payout = game.payout();
        winnings += payout;
        if(payout==20) nFourOfAKind++;
        else if(payout==100) nYahtzee++;
        //get num rolls, add to rollCountsFair
        for(int i=0; i<6; ++i) {
            rollCountsFair[i] += game.getRollCount(i+1);
        }

        if(n==nTrials-1 or n>= l*(nTrials/nLogSteps)) {
            l++;
            std::cout << n+1 <<","<< nYahtzee <<","<<nFourOfAKind<<","<<winnings;
            std::cout << "\n";
        }
    }
    //write logfile1 to file
    }


    // Run trials for FunYahtzee
    {
    std::cout << "FunYahtzee\n";
    std::cout << "nTrials=" <<nTrials <<"\n";
    std::cout << "trials,nYahtzee,nFourOfAKind,winnings\n";
    int l=0;
    int nYahtzee=0, nFourOfAKind=0;
    int winnings=0;
    for(int n=0; n<nTrials; ++n) {

        Yahtzee game = Yahtzee(true,generator);
        game.reroll(6,generator);
        game.reroll(6,generator);
        int payout = game.payout();
        winnings += payout;
        if(payout==20) nFourOfAKind++;
        else if(payout==100) nYahtzee++;
        //get num rolls, add to rollCountsFixed
        for(int i=0; i<6; ++i) {
            rollCountsFixed[i] += game.getRollCount(i+1);
        }

        if(n==nTrials-1 or n>= l*nTrials/nLogSteps) {
            l++;
            std::cout << n+1 <<","<< nYahtzee <<","<<nFourOfAKind<<","<<winnings;
            std::cout << "\n";
        }
    }
    //write logfile2 to file
    }

    // Output rollCountsFair and Fixed to logfile3
    for(int i=0; i<6; ++i) {
        std::cout << rollCountsFair[i];
        if(i<5) std::cout << ",";
    }
    std::cout << "\n";
    for(int i=0; i<6; ++i) {
        std::cout << rollCountsFixed[i];
        if(i<5) std::cout << ",";
    }
    std::cout << "\n";
    //write logfile3 to file


    return 0;
}
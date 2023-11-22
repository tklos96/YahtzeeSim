#include "Yahtzee.h"
#include "Logfile.h"

#include <string>
#include <iostream>
#include <sstream>
#include <random>


int main() {
    const int nTrials = 1000;
    const int nLogSteps = 100;

    //Set up session
    std::random_device rd;
    std::default_random_engine generator{rd()};

    std::vector<int> rollCountsFair(6,0);
    std::vector<int> rollCountsFixed(6,0);
    
    //Run Trials for Standard Yahtzee
    {
        Logfile log_st{"log_standard.txt"};
        std::ostringstream header;
        header << "Standard Yahtzee\n";
        header << "nTrials=" << nTrials << "\n";
        header << "trials,nYahtzee,nFourOfAKind,winnings";
        log_st.write(header.str());
        int l=1;
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

            if(n==nTrials-1 or n>= (l*nTrials/nLogSteps-1)) {
                l++;
                std::ostringstream line;
                line << n+1 <<","<< nYahtzee <<","<<nFourOfAKind<<","<<winnings;
                log_st.write(line.str());
            }
        }
    }


    // Run trials for FunYahtzee
    {
        Logfile log_fun{"log_fun.txt"};
        std::ostringstream header;
        header << "Fun Yahtzee\n";
        header << "nTrials=" << nTrials << "\n";
        header << "trials,nYahtzee,nFourOfAKind,winnings";
        log_fun.write(header.str());
        int l=1;
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

            if(n==nTrials-1 or n>= (l*nTrials/nLogSteps-1)) {
                l++;
                std::ostringstream line;
                line << n+1 <<","<< nYahtzee <<","<<nFourOfAKind<<","<<winnings;
                log_fun.write(line.str()); 
            }
        }
    }

    // Output rollCountsFair and Fixed to logfile3
    Logfile log_rolls{"log_rolls.txt"};
    log_rolls.write("Roll counts for Standard and Fun Yahtzee");
    std::ostringstream rolls;
    for(int i=0; i<6; ++i) {
        rolls << rollCountsFair[i];
        if(i<5) rolls << ",";
    }
    rolls << "\n";
    for(int i=0; i<6; ++i) {
        rolls << rollCountsFixed[i];
        if(i<5) rolls << ",";
    }
    log_rolls.write(rolls.str());


    return 0;
}

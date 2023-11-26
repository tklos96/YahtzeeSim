#include "Yahtzee.h"
#include "Logfile.h"

#include <string>
#include <iostream>
#include <sstream>
#include <random>

void runTrials(const int nTrials,
               const bool fun,
               const std::string& filename,
               std::default_random_engine& gen) {

        // Write logfile header
        Logfile log{filename};
        std::ostringstream header;
        header << "Standard Yahtzee\n";
        header << "nTrials=" << nTrials << "\n";
        header << "trials,nYahtzee,nFourOfAKind,winnings,1s,2s,3s,4s,5s,6s";
        log.write(header.str());

        // Initialize variables
        int l=1;
        int nYahtzee=0, nFourOfAKind=0;
        int winnings = 0;
        std::vector<int> rollCounts(6,0);

        // Start trials
        for(int n=0; n<nTrials; ++n) {

            // Play each game with 2 rerolls
            Yahtzee game = Yahtzee(fun,gen);
            game.reroll(6,gen);
            game.reroll(6,gen);

            // Get payout and roll counts
            int payout = game.payout();
            winnings += payout;
            if(payout==20) nFourOfAKind++;
            else if(payout==100) nYahtzee++;
            for(int i=0; i<6; ++i) {
                rollCounts[i] += game.getRollCount(i+1);
            }

            // Write results to logfile
            if(n==nTrials-1 or n>= (l*nTrials/100-1)) {
                l++;
                std::ostringstream line;
                line << n+1 <<","<< nYahtzee <<","<<nFourOfAKind<<","<<winnings;
                for(int i=0; i<6; ++i){
                    line << "," << rollCounts[i];
                }
                log.write(line.str());
            }
        }
    }

int main() {
    const int nTrials = 10000;

    // Seed pseudo-random number generator with a non-deterministic
    // random number from the device.
    std::random_device rd;
    std::default_random_engine generator{rd()};
   
    // Run trials for both variants.
    runTrials(nTrials,false,"log_standard.txt",generator);
    runTrials(nTrials,true ,"log_fun.txt"     ,generator);

    return 0;
}

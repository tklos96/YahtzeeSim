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
        Logfile log{filename};
        std::ostringstream header;
        header << "Standard Yahtzee\n";
        header << "nTrials=" << nTrials << "\n";
        header << "trials,nYahtzee,nFourOfAKind,winnings,1s,2s,3s,4s,5s,6s";
        log.write(header.str());
        int l=1;
        int nYahtzee=0, nFourOfAKind=0;
        int winnings = 0;
        std::vector<int> rollCounts(6,0);
        for(int n=0; n<nTrials; ++n) {

            Yahtzee game = Yahtzee(fun,gen);
            game.reroll(6,gen);
            game.reroll(6,gen);
            int payout = game.payout();
            winnings += payout;
            if(payout==20) nFourOfAKind++;
            else if(payout==100) nYahtzee++;
            //get num rolls, add to rollCountsFair
            for(int i=0; i<6; ++i) {
                rollCounts[i] += game.getRollCount(i+1);
            }

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
    const int nTrials = 1000;
    //const int nLogSteps = 100;

    //Set up session
    std::random_device rd;
    std::default_random_engine generator{rd()};

    //std::vector<int> rollCountsFixed(6,0);
    
    //Run Trials for Standard Yahtzee
    runTrials(nTrials,false,"log_standard.txt",generator);
    runTrials(nTrials,true ,"log_fun.txt"     ,generator);
    //{
    //    Logfile log_st{"log_standard.txt"};
    //    std::ostringstream header;
    //    header << "Standard Yahtzee\n";
    //    header << "nTrials=" << nTrials << "\n";
    //    header << "trials,nYahtzee,nFourOfAKind,winnings,1s,2s,3s,4s,5s,6s";
    //    log_st.write(header.str());
    //    int l=1;
    //    int nYahtzee=0, nFourOfAKind=0;
    //    int winnings = 0;
    //    for(int n=0; n<nTrials; ++n) {

    //        Yahtzee game = Yahtzee(false,generator);
    //        game.reroll(6,generator);
    //        game.reroll(6,generator);
    //        int payout = game.payout();
    //        winnings += payout;
    //        if(payout==20) nFourOfAKind++;
    //        else if(payout==100) nYahtzee++;
    //        //get num rolls, add to rollCountsFair
    //        for(int i=0; i<6; ++i) {
    //            rollCountsFair[i] += game.getRollCount(i+1);
    //        }

    //        if(n==nTrials-1 or n>= (l*nTrials/nLogSteps-1)) {
    //            l++;
    //            std::ostringstream line;
    //            line << n+1 <<","<< nYahtzee <<","<<nFourOfAKind<<","<<winnings;
    //            for(int rollCount : rollCountsFair) {
    //                line << "," << rollCount;
    //            }
    //            log_st.write(line.str());
    //        }
    //    }
    //}


    // Run trials for FunYahtzee
    //{
    //    Logfile log_fun{"log_fun.txt"};
    //    std::ostringstream header;
    //    header << "Fun Yahtzee\n";
    //    header << "nTrials=" << nTrials << "\n";
    //    header << "trials,nYahtzee,nFourOfAKind,winnings";
    //    log_fun.write(header.str());
    //    int l=1;
    //    int nYahtzee=0, nFourOfAKind=0;
    //    int winnings=0;
    //    for(int n=0; n<nTrials; ++n) {

    //        Yahtzee game = Yahtzee(true,generator);
    //        game.reroll(6,generator);
    //        game.reroll(6,generator);
    //        int payout = game.payout();
    //        winnings += payout;
    //        if(payout==20) nFourOfAKind++;
    //        else if(payout==100) nYahtzee++;
    //        //get num rolls, add to rollCountsFixed
    //        for(int i=0; i<6; ++i) {
    //            rollCountsFixed[i] += game.getRollCount(i+1);
    //        }

    //        if(n==nTrials-1 or n>= (l*nTrials/nLogSteps-1)) {
    //            l++;
    //            std::ostringstream line;
    //            line << n+1 <<","<< nYahtzee <<","<<nFourOfAKind<<","<<winnings;
    //            for(int rollCount : rollCountsFixed) {
    //                line << "," << rollCount;
    //            }
    //            log_fun.write(line.str()); 
    //        }
    //    }
    //}

    // Output rollCountsFair and Fixed to logfile3
    //Logfile log_rolls{"log_rolls.txt"};
    //log_rolls.write("Roll counts for Standard and Fun Yahtzee");
    //std::ostringstream rolls;
    //for(int i=0; i<6; ++i) {
    //    rolls << rollCountsFair[i];
    //    if(i<5) rolls << ",";
    //}
    //rolls << "\n";
    //for(int i=0; i<6; ++i) {
    //    rolls << rollCountsFixed[i];
    //    if(i<5) rolls << ",";
    //}
    //log_rolls.write(rolls.str());


    return 0;
}

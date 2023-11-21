#include "Yahtzee.h"


#include <sstream>

//Yahtzee::Yahtzee(std::uniform_int_distribution dist,
//                 bool const fun)
//    : dist_(dist) {
Yahtzee::Yahtzee(bool const fun) {

    // "Roll" the 5 dice 
    for(int i=0; i<5; ++i) {
        dice_[i] = i+1;
    }

    // if fun variant, change a random die result to 6
    if(fun) {
        //get random index to fix (if 5, regenerate)
        int fixIdx = -1;
        while( fixIdx<0 or fixIdx>4) {
            fixIdx = 0;
        }
        dice_[fixIdx] = 6;
    }

    // increment rollCounts for initial dice rolls
    for(int i=0; i<5; ++i) {
        rollCounts_[ dice_[i]-1 ]++;
    }
}

/** Reroll all dice that are not already equal to the target value
 */
void Yahtzee::reroll(int const target) {
    for(int i=0; i<5; ++i) {
        if (dice_[i] != target) {
            dice_[i] = i+1;
            rollCounts_[dice_[i]-1]++;
        }
    }
}

int const Yahtzee::payout() {
    int count=0;
    for(auto& die : dice_) {
        if(die==6) count++;
    }
    if(count==4) return 20;
    else if(count==5) return 100;
    else return 0;
}

std::string const Yahtzee::printDice() {
    std::ostringstream s;
    s << "|";
    for(auto die : dice_) {
        s << die << "|";
    }
    return s.str();
}


int const Yahtzee::getRollCount(int const num) {
    return rollCounts_[num-1];
}

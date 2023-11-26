#include "Yahtzee.h"

#include <sstream>


// Default constructor. Does initial dice rolls.
// If the Fun variant is selected, a random die has its initial roll set to 6.
Yahtzee::Yahtzee(bool const fun,std::default_random_engine& gen) {

    // Roll the 5 dice 
    auto dieDist = std::uniform_int_distribution<int>(1,6);
    for(int i=0; i<5; ++i) {
        dice_[i] = dieDist(gen);
    }

    // If fun variant, change a random die result to 6
    if(fun) {
        auto idxDist = std::uniform_int_distribution<int>(0,4);
        int fixIdx = idxDist(gen);
        dice_[fixIdx] = 6;
    }

    // Increment rollCounts_ for initial dice rolls
    for(int i=0; i<5; ++i) {
        rollCounts_[ dice_[i]-1 ]++;
    }
}

// Reroll all dice that are not already equal to the target value
void Yahtzee::reroll(int const target, std::default_random_engine& gen) {
    auto dieDist = std::uniform_int_distribution<int>(1,6);
    for(int i=0; i<5; ++i) {
        if (dice_[i] != target) {
            dice_[i] = dieDist(gen);
            rollCounts_[dice_[i]-1]++;
        }
    }
}

// Get payout based on dice results
// Returns 100 if 5 6s, 20 if 4 6s, 0 otherwise
int const Yahtzee::payout() {
    int count=0;
    for(auto& die : dice_) {
        if(die==6) count++;
    }
    if(count==4) return 20;
    else if(count==5) return 100;
    else return 0;
}

// Print the dice results
std::string const Yahtzee::printDice() {
    std::ostringstream s;
    s << " _ _ _ _ _\n";
    s << "|";
    for(auto die : dice_) {
        s << die << "|";
    }
    s << "\n ‾ ‾ ‾ ‾ ‾";
    return s.str();
}


// Get the number of times a given die result (1-6) was rolled
int const Yahtzee::getRollCount(int const num) {
    return rollCounts_[num-1];
}

#ifndef YAHTZEE_H__
#define YAHTZEE_H__

#include <string>
#include <vector>
#include <random>

// Class for simulating games of Yahtzee
class Yahtzee {
    public:
        Yahtzee(bool const fun, std::default_random_engine& gen);

        void reroll(int const target, std::default_random_engine& gen );

        int const payout();
        std::string const printDice();
        int const getRollCount(int const num);

    private:
        // Values of dice (range 1-6)
        std::vector<int> dice_ = std::vector<int>(5,0);

        // Roll count of die results:
        // rollCounts_[i] is the number of times (i+1) was rolled during the game.
        std::vector<int> rollCounts_ = std::vector<int>(6,0);
};



#endif

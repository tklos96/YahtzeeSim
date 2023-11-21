#ifndef YAHTZEE_H__
#define YAHTZEE_H__

#include <string>
#include <vector>

class Yahtzee {
    public:
        //Constructor
        //Yahtzee(std::uniform_int_distribution dist,
        //        bool const fun);
        Yahtzee(bool const fun);

        //void setDice(std::vector<int>& const diceIn);
        void reroll(int const target);

        int const payout();
        std::string const printDice();
        int const getRollCount(int const num);

    private:
        //stores value of dice (range 1-6)
        std::vector<int> dice_ = std::vector<int>(5,0);

        //std::uniform_int_distribution dist_;

        //stores roll count of possible results (r=i+1)
        std::vector<int> rollCounts_ = std::vector<int>(6,0);
};



#endif

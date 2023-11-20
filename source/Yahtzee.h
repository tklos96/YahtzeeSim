#ifndef YAHTZEE_H__
#define YAHTZEE_H__

#include <rand>
#include <string>
#include <vector>

class Yahtzee() {
    public:
        //Constructor
        Yahtzee(std::uniform_int_distribution dist,
                bool const fun);

        void setDice(std::vector<int>& const diceIn);
        void reroll(int const target);

        int const payout();
        std::string const printDice();
        int const getRollCount(int const num);

    private:
        std::vector<int> dice_(5,-1);
        std::uniform_int_distribution dist_;
        std::vector<int> rollCounts_(6,0);
}



#endif

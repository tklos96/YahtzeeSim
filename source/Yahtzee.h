#import <rand>
#import <string>
#import <vector>

class Yahtzee() {
    public:
        Yahtzee( dist ); //Default constructor

        void setDice(std::vector<int>& const diceIn);
        void reroll(int const target);

        int const payout();
        std::string const printDice();

    private:
        std::vector<int> dice_(5);
}

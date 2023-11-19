# YahtzeeSim
Simulating a simplified version of Yahtzee

# Setup
To play the game in your console, use `build_game.sh`. To run the full simulation test suite, use `build_test_suite.sh`.

# Rules
Yahtzee is a dice-rolling game. The objective is to get as many 6s as possible. The game will start with 5 random dice rolls. Then the player has two opportunies to reroll any dice that aren't 6. After the rerolls, the player is awarded a payout if they rolled enough 6s.

Payout:
Yahtzee! (5 6s) - $100
4-of-a-kind (4 6s) - $20


# FunYahtzee
In order to make the game more fun, there is a variant - FunYahtzee - in which the player is guaranteed to start with at least 1 6 in their starting roll. Correspondingly, the average payout is significantly higher, which is investigated in the `analysis` folder.


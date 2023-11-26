# Setup
In order to build the game application, run `make` from this folder. To play the game, run `make play`.

# Rules
Yahtzee is a dice-rolling game. Although the full ruleset has many possible results, in this simplified version the goal is to get as many 6s as possible. The game will start with 5 random dice rolls. Then the player has two opportunies to reroll any dice that aren't 6. Finally, the player is awarded a payout if they rolled enough 6s.

| Result | Payout |
|--------|--------:|
|Yahtzee (5 6s) | $ 100 |
|Four-of-a-kind (4 6s) | $ 20 |


# Fun Yahtzee
In order to make the game more fun, there is a variant&mdash;Fun Yahtzee&mdash;in which the player is guaranteed to start with at least 1 6 in their initial roll. Correspondingly, the average payout is significantly higher. See the `test` folder for an analysis of the differences between the Standard and Fun variants.

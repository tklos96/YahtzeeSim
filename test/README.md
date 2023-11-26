Setup
=====
To set up the test, run `make`. The test can be executed with `make test`. Use `python analysis.py` to analyze the resulting logfiles and generate graphs.



Roll Counts
===========


Plot here
![Roll Frequencies](dieResults.png)

chi\_squared for Standard Yahtzee =    4.383
chi\_squared for FunYahtzee       =  414.741

The critical value with n=5 degrees of freedom and alpha=0.05 is 11.070. Thus, we can reject the dice being fair for Fun Yahtzee but not for Standard Yahtzee. This is as expected, since Fun Yahtzee always rigs a 6 roll at the start of the game.


Comparison to Expected

|Variant    | $P(\text{Yahtzee})$ | $P(\text{Four-of-a-kind})$|
|-----------|-------------:|-------------------:|
|Standard   |      0.013057|            0.091154|
|Fun        |      0.031503|            0.173093|

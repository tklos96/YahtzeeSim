#include "Yahtzee.h"

Yahtzee::Yahtzee(std::uniform_int_distribution dist,
                 bool const fun)
    : dist_(dist) {
    for(int i=0; i<5; ++i) {
        dice_[i] = dist+1;
    }

    if(fun) {
        //get random index to fix (if 5, regenerate)
        fixIdx = -1;
        while( fixIdx<0 or fixIdx>4) {
            fixIdx = dist;
        }
        dice_[fixIdx] = 6;
    }

    for(int i=0; i<5; ++i) {
        rollCounts_[ dice_[i] ]++;
    }
}

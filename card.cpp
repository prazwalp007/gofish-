//
// Created by prajwal on 4/6/19.
//

#include "card.h"

// default, ace of spades
Card :: Card(){
    myRank = 1;
    mySuit = spades;
    toString();
}


Card:: Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
    toString();

}
// return string version e.g. Ac 4h Js
string Card:: toString() const{
    return (rankString(myRank)+suitString(mySuit));
}

// true if suit same as c
bool Card :: sameSuitAs(const Card& c) const{
 if (mySuit == c.mySuit){
     return true;
 }else{
     return false;
 }

}

// return rank, 1..13
int  Card :: getRank() const{
    return myRank;
}
// return "s", "h",...
string Card :: suitString(Suit s) const{
    //check suitType
    string suitType;
    if (s == spades){
        suitType = "s";
    }else if (s == hearts){
        suitType = "h";
    }else if (s == diamonds){
        suitType = "d";
    }else if (s == clubs){
        suitType = "c";
    }

    return suitType;

}
// return "A", "2", ..."Q"
string Card :: rankString(int r) const{
    //check rank
    string rankType;
    switch (r) {
        case 1:
            rankType = "A";
            break;
        case 2:
            rankType = "2";
            break;
        case 3:
            rankType = "3";
            break;
        case 4:
            rankType = "4";
            break;
        case 5:
            rankType = "5";
            break;
        case 6:
            rankType = "6";
            break;
        case 7:
            rankType = "7";
            break;
        case 8:
            rankType = "8";
            break;
        case 9:
            rankType = "9";
            break;
        case 10:
            rankType = "10";
            break;
        case 11:
            rankType = "J";
            break;
        case 12:
            rankType = "Q";
            break;
        case 13:
            rankType = "K";
            break;
    }
    return rankType;

}


bool Card:: operator == (const Card& rhs) const {
    if (myRank == rhs.myRank) {
        if (mySuit == rhs.mySuit) {
            return true;
        }
    }
    return false;
}

bool Card :: operator != (const Card& rhs) const {
    if ((myRank != rhs.myRank)||(mySuit != rhs.mySuit))
    {
        return true;
    }else{
        return false;
    }
}


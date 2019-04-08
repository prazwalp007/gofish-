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

    string cardType;

    //check rank
    if (myRank == 1){
        cardType = "A";
    }else if (myRank == 11){
        cardType = "J";
    }else if (myRank == 12){
        cardType = "Q";
    }else if (myRank == 13) {
        cardType = "K";
    }else{
        cardType = to_string(myRank);
    }

    //check suit
    if (mySuit == spades){
        cardType  = cardType + "s";
    }else if (mySuit == hearts){
        cardType  = cardType + "h";
    }else if (mySuit == diamonds){
        cardType  = cardType + "d";
    }else if (mySuit == clubs){
        cardType = cardType + "c";
    }
   // cout<<cardType<<endl;
    return cardType;
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

    if (r == 1){
        rankType = "A";
    }else if (r == 11){
        rankType = "J";
    }else if (r == 12){
        rankType = "Q";
    }else if (r == 13) {
        rankType = "K";
    }else{
        rankType = to_string(r);
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


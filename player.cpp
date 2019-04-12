//
// Created by prajwal on 4/6/19.
//

#include "player.h"


void Player:: addCard(Card c){
    myHand.push_back(c);
}

void Player:: bookCards(Card c1, Card c2) {

    myBook.push_back(c1);
    myBook.push_back(c2);
    vector<Card>:: iterator it = myHand.begin();
    while (*it != c1) {
        it++;
    }
    it = myHand.erase(it);

    it = myHand.begin();
    while (*it != c2) {
        it++;
    }
    it = myHand.erase(it);



}

bool Player:: checkHandForBook(Card &c1, Card &c2){
    for(vector<Card>::iterator it1 = myHand.begin(); it1 != myHand.end(); it1++){
        for(vector<Card>::iterator it2 = it1+1; it2 != myHand.end(); it2++){
            if(it1->getRank() == it2->getRank()){
                c1 = *it1;
                c2 = *it2;
                return true;
            }
        }
    }
    return false;
}

bool Player:: rankInHand(Card c) const{
    for(vector<Card>::const_iterator it = myHand.begin(); it != myHand.end(); it++){
        if (it->getRank() == c.getRank()){
            return true;
        }
    }
    return false;
}

Card Player:: chooseCardFromHand() const {

    vector<Card>::const_iterator it = myHand.begin();
      if (myHand.size()>0) {
        int random = rand() % myHand.size();
        Card c1 = *(it + random);
        return c1;
      }

}

bool Player:: cardInHand(Card c) const{
    for(vector<Card>::const_iterator it = myHand.begin(); it != myHand.end(); it++){
        if(it->getRank() == c.getRank()){
            return true;
        }
    }
    return false;
}

Card Player:: removeCardFromHand(Card c){
    for(vector<Card>::iterator it = myHand.begin(); it != myHand.end(); it++){
       if(it->getRank() == c.getRank()) {
           Card c1 = *it;
           it = myHand.erase(it);
           return c1;
       }
    }
}


string Player :: showHand() const{
   //string hands;
    for (vector<Card>::const_iterator it = myHand.begin(); it != myHand.end(); it++){
        //hands = hands + it->toString() + " ";
        cout << it->toString()<<" ";

    }
    cout << endl;
    return "0";
}

string Player :: showBooks() const{
    string books;
    for (vector<Card>::const_iterator it = myBook.begin(); it != myBook.end(); it++){
         //  books = books + it->toString() + " ";
        cout << it->toString()<<" ";
    }
    cout << endl;
    return "0";

}

int Player :: getHandSize() const{
    return myHand.size();
}

int Player:: getBookSize() const{
    return myBook.size();
}




/*
bool Player::checkHandForPair(Card &c1, Card &c2){


}


bool Player:: sameRankInHand(Card c) const{



}
 */
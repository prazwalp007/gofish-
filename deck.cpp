//
// Created by prajwal on 4/6/19.
//

#include "deck.h"
// pristine, sorted deck
Deck::Deck(){

    //seed for random number generator
    srand(time(0));
    myIndex = -1;
    int num = 0;

    for (int i = 0; i < sizeof(Card::Suit); i++ ){
        for (int j = 1; j < 14; j++){
            Card c (j, Card::Suit(i));
            myCards[num] = c;
            num++;
        }
    }

    for (int i = 0; i < SIZE; i++){
       cout <<  myCards[i].toString()<<endl;
    }

}

// shuffle the deck, all 52 cards present
void Deck:: shuffle(){

    for (int i = 0; i < (SIZE); i++){
        int random = rand()%SIZE;
        swap(myCards[i], myCards[random]);
        //swap(myCards[i], myCards[random]);
    }

    for (int i = 0; i < SIZE; i++){
        cout << myCards[i].toString()<<endl;
    }

}
// get a card, after 52 are dealt, fail
Card Deck :: dealCard(){
    myIndex = myIndex + 1;
    return myCards[myIndex];

}

// # cards left in the deck
int Deck :: size() const{
    return SIZE - (myIndex + 1);
}
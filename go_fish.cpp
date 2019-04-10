// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
//void dealHand(Deck &d, Player &p, int numCards);




int main( )
{

    Deck d;
   // Card p1 = d.dealCard();
   // Card p2 = d.dealCard();
   // cout<<"First dealt Card is "<<p1.toString()<<endl;
   // cout<<"Second dealt Card is "<<p2.toString()<<endl;

    d.shuffle();
    Player s1("Shishir");
    Player s2 ("Sakar");

    Card c1, c2;

    for (int i = 0; i < 7; i ++){
       Card c = d.dealCard();
       s1.addCard(c);
      // s2.addCard(c2);
    }

    s1.showHand();
    s1.showBooks();



    //Check if s1 has any pair when the card is dealt for the first time
    if (s1.checkHandForBook(c1, c2)){
       // cout << endl<< c1.toString()<<" "<< c2.toString();
        s1.bookCards(c1, c2);
    }
    s1.showBooks();
    s1.showHand();










    /*
    Card c1(10, Card::clubs);
    Card c2 (10, Card::clubs);

    if (c1.sameSuitAs(c2)){
        cout<<"c1 and c2 suits are same"<<endl;
    }

    if (c1 == c2){
        cout << "c1 and c2 are same"<<endl;
    }
     */



/*

    int numCards = 5;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    return EXIT_SUCCESS;


}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
        */

}

   



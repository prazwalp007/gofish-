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


void gameResult(vector <Player> gofishPlayers);
void gameInfo (const Player &p);
int calculateCurrentPlayersBookSize (vector <Player> gofishPlayers);

int main( ) {

    Deck d;
    int cardsInFullDeck = d.size();
    d.shuffle();
    //vector of Players
    vector<Player> gofishPlayers;

    //create players
    Player s1("Jane");
    Player s2("Joe");
    //Player s3("Mira");
    gofishPlayers.push_back(s1);
    gofishPlayers.push_back(s2);
    //gofishPlayers.push_back(s3);

    //Temporary cards to store values
    Card c1, c2;

    //Determine number of cards to deal
    int numCardsForPLayers;
    if (gofishPlayers.size() == 2) {
        numCardsForPLayers = 7;
    } else {
        numCardsForPLayers = 5;
    }


    //Deal Cards to Players
    int numPlayers = gofishPlayers.size();
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < numCardsForPLayers; j++) {
            c1 = d.dealCard();
            gofishPlayers[i].addCard(c1);
        }
    }

    //Show cards of both players when the cards are dealt for first time
    for (int i = 0; i < gofishPlayers.size(); i++) {
       gameInfo(gofishPlayers[i]);
    }


    //Check if Player 1 and Player 2 has any pair when the card is dealt for the first time
    for (int i = 0; i < gofishPlayers.size(); i++) {
        while (gofishPlayers[i].checkHandForBook(c1, c2)) {
            gofishPlayers[i].bookCards(c1, c2);
        }
    }


    //Players take their turn
    for (int i = 0; calculateCurrentPlayersBookSize(gofishPlayers) < cardsInFullDeck; i++) {

        c1 = gofishPlayers[i].chooseCardFromHand();
        cout << gofishPlayers[i].getName() << " asks - Do you have any " << c1.rankString(c1.getRank()) << " ? "<< endl;


        while ((gofishPlayers[(i + 1) % numPlayers].cardInHand(c1)) && (gofishPlayers[i].getHandSize() > 0)) {    //If yes then reply yes and add it to Player 1 hand

            cout << gofishPlayers[(i + 1) % numPlayers].getName() << " - Yes, I have a " << c1.getRank()<< endl;

            c2 = gofishPlayers[(i + 1) % numPlayers].removeCardFromHand(c1);
            gofishPlayers[i].addCard(c2);
            gofishPlayers[i].bookCards(c1, c2);

            c1 = gofishPlayers[i].chooseCardFromHand();

            if (gofishPlayers[i].getHandSize() > 0) {
                cout << gofishPlayers[i].getName() << " asks - Do you have any " << c1.rankString(c1.getRank())<< " ? " << endl;
            }
        }


        if (d.size() > 0 && !(gofishPlayers[(i + 1) % numPlayers].cardInHand(c1))) {
            cout << gofishPlayers[(i + 1) % numPlayers].getName() << " Says - Go Fish!" << endl;
            c2 = d.dealCard();
            gofishPlayers[i].addCard(c2);
            cout << gofishPlayers[i].getName() << " draws  " << c2.toString() << endl;

            if (gofishPlayers[i].checkHandForBook(c1, c2)) {
                gofishPlayers[i].bookCards(c1, c2);
            }
        }


        if ((gofishPlayers[i].getHandSize() == 0) && (d.size() > 0)) {// if the player runs out of card
            c1 = d.dealCard();
            gofishPlayers[i].addCard(c1);
            cout << gofishPlayers[i].getName() <<" is out of card so player draws "<< c1.toString()<<endl;
        }


        //Prints information regarding player's hand and book
        gameInfo(gofishPlayers[i]);

        if (i == numPlayers - 1) {
            i = -1;
        }
    }

   //Display game result
   gameResult(gofishPlayers);
}






void gameResult(vector<Player> gofishPlayers){
    int numBook = 0;
    string nameofWinner;
    for (int i = 0; i < gofishPlayers.size(); i++ ) {
        cout <<"Number of books of " << gofishPlayers[i].getName() << " - "<< (gofishPlayers[i].getBookSize()/2)<<endl;
        if (gofishPlayers[i].getBookSize()> numBook){
            numBook = gofishPlayers[i].getBookSize();
            nameofWinner = gofishPlayers[i].getName();
        }

    }

    for (int i = 0; i < gofishPlayers.size(); i++){
        for (int j = 1; j < gofishPlayers.size(); j++){
            if (gofishPlayers[i].getBookSize() != gofishPlayers[j].getBookSize()){
                cout << "The winner is " << nameofWinner<<endl;
                return;
            }

        }

    }
    cout << "The Game is draw " <<endl;
}

void gameInfo (const Player &p ){
    cout << "*****************************" << endl;
    cout << p.getName() << " Book" << endl;
    p.showBooks();
    cout << p.getName()<< " Hand" << endl;
    p.showHand();
    cout << "*****************************" << endl;
}


int calculateCurrentPlayersBookSize (vector <Player> gofishPlayers){
    int currentPlayersBookSize = 0;
    for (int i = 0; i < gofishPlayers.size(); i++) {
        currentPlayersBookSize += gofishPlayers[i].getBookSize();
    }
    return currentPlayersBookSize;
}
   



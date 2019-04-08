//
// Created by prajwal on 4/6/19.
//

#include "deck.h"
// pristine, sorted deck
Deck::Deck(){

    //seed for random number generator
    srand(time(0));
    myIndex = SIZE;

    //Spades suit
    Card s1(1, Card::spades);
    Card s2(2, Card::spades);
    Card s3(3, Card::spades);
    Card s4(4, Card::spades);
    Card s5(5, Card::spades);
    Card s6(6, Card::spades);
    Card s7(7, Card::spades);
    Card s8(8, Card::spades);
    Card s9(9, Card::spades);
    Card s10(10, Card::spades);
    Card s11(11, Card::spades);
    Card s12(12, Card::spades);
    Card s13(13, Card::spades);

    //Clubs suit
    Card c1(1, Card::clubs);
    Card c2(2, Card::clubs);
    Card c3(3, Card::clubs);
    Card c4(4, Card::clubs);
    Card c5(5, Card::clubs);
    Card c6(6, Card::clubs);
    Card c7(7, Card::clubs);
    Card c8(8, Card::clubs);
    Card c9(9, Card::clubs);
    Card c10(10, Card::clubs);
    Card c11(11, Card::clubs);
    Card c12(12, Card::clubs);
    Card c13(13, Card::clubs);

    //diamonds suit
    Card d1(1, Card::diamonds);
    Card d2(2, Card::diamonds);
    Card d3(3, Card::diamonds);
    Card d4(4, Card::diamonds);
    Card d5(5, Card::diamonds);
    Card d6(6, Card::diamonds);
    Card d7(7, Card::diamonds);
    Card d8(8, Card::diamonds);
    Card d9(9, Card::diamonds);
    Card d10(10, Card::diamonds);
    Card d11(11, Card::diamonds);
    Card d12(12, Card::diamonds);
    Card d13(13, Card::diamonds);

    //hearts suit
    Card h1(1, Card::hearts);
    Card h2(2, Card::hearts);
    Card h3(3, Card::hearts);
    Card h4(4, Card::hearts);
    Card h5(5, Card::hearts);
    Card h6(6, Card::hearts);
    Card h7(7, Card::hearts);
    Card h8(8, Card::hearts);
    Card h9(9, Card::hearts);
    Card h10(10, Card::hearts);
    Card h11(11, Card::hearts);
    Card h12(12, Card::hearts);
    Card h13(13, Card::hearts);

    myCards[0] = s1;
    myCards[1] = s2;
    myCards[2] = s3;
    myCards[3] = s4;
    myCards[4] = s5;
    myCards[5] = s6;
    myCards[6] = s7;
    myCards[7] = s8;
    myCards[8] = s9;
    myCards[9] = s10;
    myCards[10] = s11;
    myCards[11] = s12;
    myCards[12] = s13;

    myCards[13] = c1;
    myCards[14] = c2;
    myCards[15] = c3;
    myCards[16] = c4;
    myCards[17] = c5;
    myCards[18] = c6;
    myCards[19] = c7;
    myCards[20] = c8;
    myCards[21] = c9;
    myCards[22] = c10;
    myCards[23] = c11;
    myCards[24] = c12;
    myCards[25] = c13;

    myCards[26] = d1;
    myCards[27] = d2;
    myCards[28] = d3;
    myCards[29] = d4;
    myCards[30] = d5;
    myCards[31] = d6;
    myCards[32] = d7;
    myCards[33] = d8;
    myCards[34] = d9;
    myCards[35] = d10;
    myCards[36] = d11;
    myCards[37] = d12;
    myCards[38] = d13;


    myCards[39] = h1;
    myCards[40] = h2;
    myCards[41] = h3;
    myCards[42] = h4;
    myCards[43] = h5;
    myCards[44] = h6;
    myCards[45] = h7;
    myCards[46] = h8;
    myCards[47] = h9;
    myCards[48] = h10;
    myCards[49] = h11;
    myCards[50] = h12;
    myCards[51] = h13;

    for (int i = 0; i < myIndex; i++){
       cout <<  myCards[i].toString()<<endl;
    }

}

// shuffle the deck, all 52 cards present
void Deck:: shuffle(){

    for (int i = 0; i < SIZE; i++){
        int random = rand()%SIZE;
        swap(myCards[i], myCards[random]);
    }

    for (int i = 0; i < myIndex; i++){
        cout << myCards[i].toString()<<endl;
    }

}
// get a card, after 52 are dealt, fail
Card Deck :: dealCard(){
    myIndex = myIndex - 1;
    return myCards[myIndex];

}

// # cards left in the deck
int Deck :: size() const{
    return SIZE - myIndex;
}
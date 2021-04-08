#include "card.hpp"
#include "enums.hpp"
#include <list>
#include <iostream>
#include <cstdlib>

class CardHand {
public:
//maybe better to have a game type object as the input?
    CardHand(){}

    void addCard(Card newCard) {
        hand.push_back(newCard);
    }

    Card removeCard(){
        Card retCard = hand.back();
        hand.pop_back();
        return retCard;
    }

    int getCurrentHandSize() const {
        return hand.size();
    }

    void showHand() const {
        for(auto card : hand){
            std::cout << card << " ";
        }
        std::cout << "\n";
    }

    bool isEmpty() const {
        return hand.empty();
    }
private:
    std::list<Card> hand;
};
#include "card.hpp"
#include "enums.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>

/**
 * Class that represents a card deck.
 *
 * @param initDeckSize int the number of card in the deck.
 * @param lowestCardVal int the lowest card number allowed.
 * @param highestCardVal int the highest card number allowed.
 */
class CardDeck {
public:
//maybe better to have a card type object as the input?
    CardDeck(int initDeckSize, int lowestCardVal, int highestCardVal) {
        CardDeck::initDeckSize = CardDeck::currentDeckSize = initDeckSize;
        CardDeck::highestCardVal = highestCardVal;
        CardDeck::lowestCardVal = lowestCardVal;
        initializeDeck(DeckType::STD52);
    }

    void shuffleDeck() {
        srand (time(NULL));
        std::vector<bool> shuffled[currentDeckSize];
        Card tempCard;
        for(int i = 0; i < currentDeckSize; i++){
            tempCard = deck[i];
            int randNum = rand() % (currentDeckSize - i) + i;
            deck[i] = deck[randNum];
            // std::cout << randNum << " ";
            deck[randNum] = tempCard;
        }
    }

    void initializeDeck(DeckType deckType) {
        deck[initDeckSize];
        currentDeckSize = initDeckSize;
        deck.clear();
        if(deckType == DeckType::STD52){
            std::vector<Suit> suits {Suit::HEART, Suit::DIAMOND, Suit::SPADE, Suit::CLUB};
            for(auto s : suits) {
                for(int cardVal = lowestCardVal; cardVal <= highestCardVal; cardVal++){
                    deck.push_back(Card(s, cardVal));
                }
            }
        }
    }
    
    void printDeck() const {
        std::cout << "Deck Size: " << currentDeckSize << "\t";
        for(int i = 0; i < currentDeckSize; i++){
            std::cout << deck[i] << " ";
        }
        std::cout << "\n";
    }

    Card dealCard() {
        int retIdx = currentDeckSize - 1;
        currentDeckSize--;
        return deck[retIdx];
    }

    int getCurrentDeckSize() const {
        return currentDeckSize;
    }
private:
    std::vector<Card> deck;
    int initDeckSize;
    int currentDeckSize;
    int highestCardVal;
    int lowestCardVal;
};
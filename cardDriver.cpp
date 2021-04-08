#include <iostream>
#include "card.cpp"
#include "enums.hpp"
#include "card_deck.cpp"
int main(){
    // enum Suit{HEART, DIAMOND, SPADE, CLUB};
    Card club13(Suit::CLUB, 13);
    Card clubQ(Suit::CLUB, 12);
    Card diamondQ(Suit::DIAMOND, 12);
    Card spade09(Suit::SPADE, 9);
    std::cout << club13 << "\n";

    std::cout << club13.getSuit() << "\n";
    std::cout << club13.getVal() << "\n";
    Card diamond01(Suit::DIAMOND, 1);
    std::cout << club13.compareTo(diamond01) << "\n";
    std::cout << diamond01.compareTo(club13) << "\n";
    std::cout << diamond01.getSuit() << "\n";
    CardDeck deck(52, 1, 13);
    deck.initializeDeck(DeckType::STD52);
    std::cout << "\n";
    deck.printDeck();
    deck.shuffleDeck();
    std::cout << "\n";
    deck.printDeck();
    std::cout << "current deck size: " << deck.getCurrentDeckSize() << "\n";
    std::cout << "dealing 5: " << deck.dealCard() << " "
                               << deck.dealCard() << " "
                               << deck.dealCard() << " "
                               << deck.dealCard() << " "
                               << deck.dealCard() << "\n";
    std::cout << "current deck size: " << deck.getCurrentDeckSize() << "\n";
    deck.printDeck();
    std::cout << "\nDone\n";

    std::cout << "cK > cQ: " << (club13 > clubQ) << "\n";
    std::cout << "cQ == dQ: " << (clubQ == diamondQ) << "\n";
    std::cout << "s9 < cQ: " << (spade09 < clubQ) << "\n";

    std::cout << "s9 > cQ: " << (spade09 > clubQ) << "\n";
    std::cout << "cQ == s9: " << (clubQ == spade09) << "\n";
    std::cout << "cK < cQ: " << (club13 < clubQ) << "\n";

    return 0;
}
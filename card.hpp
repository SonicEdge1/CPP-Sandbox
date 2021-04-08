#pragma once

#include <string>
#include "enums.hpp"
class Card
{
public:
    //enum Suit{HEART, DIAMOND, SPADE, CLUB};
    Card();
    Card(Suit initSuit, int initVal);
    Suit getSuit() const;
    int getVal() const; 
    int compareTo(Card otherCard) const;
    // std::ostream& operator<<(std::ostream &strm, Card &card);
    // std::string printCard();
    // friend bool operator == (const Card& lhs, const Card& rhs);
    bool operator<(const Card& otherCard) const;
    bool operator>(const Card& otherCard) const;
    bool operator<=(const Card& otherCard) const;
    bool operator>=(const Card& otherCard) const;
    bool operator==(const Card& otherCard) const;
private:
    // bool operator<(Card& b);
    friend std::ostream& operator<<(std::ostream &, const Card&); 
    Suit suit;
    int val;
};
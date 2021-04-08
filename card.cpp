#include <iostream>
#include "card.hpp"
Card::Card(){};

Card::Card(Suit initSuit, int initVal){
    val = initVal;
    suit = initSuit;
}

Suit Card::getSuit() const {
    return suit;
}

int Card::getVal() const {
    return val;
}

int Card::compareTo(Card otherCard) const {
    if(val > otherCard.val){
        return 1;
    } else if(val < otherCard.val){
        return -1;
    }
    return 0;
}

// overriding comparison operators... almost like java comparator
bool Card::operator<(const Card& otherCard) const {
    return(val < otherCard.getVal());
}
bool Card::operator>(const Card& otherCard) const {
    return(val > otherCard.getVal());
}
bool Card::operator<=(const Card& otherCard) const {
    return(val <= otherCard.getVal());
}
bool Card::operator>=(const Card& otherCard) const {
    return(val >= otherCard.getVal());
}
bool Card::operator==(const Card& otherCard) const {
    return(val == otherCard.getVal());
}

//kind of like overriding Java's toString()  the << is the stream operator
std::ostream& operator<<(std::ostream &strm, const Card &card) {
    std::string retStr = "";
    int localVal = card.val;
    if(localVal < 2 || localVal > 10){
        switch(localVal) {
            case 1 : 
                retStr += "A";
                break;
            case 11 : 
                retStr += "J";
                break;
            case 12 : 
                retStr += "Q";
                break;
            case 13 : 
                retStr += "K";
                break;                                
        }        
    } else {
        retStr += std::to_string(localVal);
    }
    switch(card.suit) {
        case Suit::HEART : 
            retStr += "\u2665";
            break;
        case Suit::DIAMOND : 
            retStr += "\u2666";
            break;
        case Suit::CLUB : 
            retStr += "\u2663";
            break;
        case Suit::SPADE : 
            retStr += "\u2660";
            break;                                
    }
    return strm << retStr;
}

#include "card_hand.cpp"

class CardPlayer {
public:
    CardPlayer(int initMoney, std::string name) {
        purse = initMoney;
        CardPlayer::playerHand = CardHand();
        CardPlayer::name = name;
        CardPlayer::numWins = 0;
    }

    int checkPurseVal() const {
        return purse;
    }
    std::string getName() const {
        return name;
    }
    int placeBet(int wager) {
        if(wager >= purse) {
            purse -= wager;
        } else { return -1; }
        return wager;
    }
    void addToPurse(int winnings) {
        purse += winnings;
    }
    void drawCard(Card newCard) {
        playerHand.addCard(newCard);
    }
    Card playCard() {
        return playerHand.removeCard();
    }
    void addNumWin(int num) {
        numWins+=num;
    }
    int getNumWins() const{
        return numWins;
    }
    void showHand() const {
        std::cout << "Hand Size: " << playerHand.getCurrentHandSize() << "\t";
        playerHand.showHand();
    }
    // void showCard(int index) {
    //     playerHand.showCard(index);
    // }
    bool haveCards() const {
        return !playerHand.isEmpty();
    }
    bool operator<(const CardPlayer& otherPlayer) const
    {
    return purse < otherPlayer.purse;
    }
    bool operator>(const CardPlayer& otherPlayer) const
    {
    return purse > otherPlayer.purse;
    }
    bool operator==(const CardPlayer& otherPlayer) const
    {
    return purse == otherPlayer.purse;
    }
    bool operator<=(const CardPlayer& otherPlayer) const
    {
    return purse <= otherPlayer.purse;
    }
    bool operator>=(const CardPlayer& otherPlayer) const
    {
    return purse >= otherPlayer.purse;
    }    

private:
    CardHand playerHand;
    int purse;
    int numWins;
    std::string name;
    friend std::ostream& operator<<(std::ostream &strm, const CardPlayer &player) {
    std::string retStr = "";
    retStr += "Player: " + player.getName() + "\n";
    retStr += "Wins: " + player.getNumWins();
    retStr += "  Purse: " + player.checkPurseVal();
    retStr += "\nCurrent Hand: ";
    return strm << retStr;
    // for(Card c : player.)
    }
};

// Comparator Class to compare 2 objects 
// class playerCompare { 
// public: 
//     // Comparator function 
//     bool operator()(student a, 
//                     student b) 
//     { 
//         // If values are the same then 
//         // return true 
//         if (a.name == b.name) { 
//             return true; 
//         } 
//         return false; 
//     } 
// };
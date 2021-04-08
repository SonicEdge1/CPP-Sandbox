#include "card_deck.cpp"
#include "card_player.cpp"
// #include "card.cpp" //does not compile without this unless makefile is used.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <limits>
#include <utility>

void play(std::vector<CardPlayer>&);
int getNumPlayers(int, int);
void initializePlayers(int, int, std::vector<CardPlayer>&);
void dealCards(int, CardDeck&, std::vector<CardPlayer>&);
void declareWinner(std::vector<CardPlayer>&);


int main(int argc, char* argv[]) {
    const int minPlayers = 2;
    const int maxPlayers = 5;
    int numPlayers = getNumPlayers(minPlayers, maxPlayers);
    int initialPurses = 0;
    int minCardsAllowed = 0;
    int maxCardsAllowed = 52 / numPlayers;
    std::vector<CardPlayer> allPlayers;

    CardDeck warDeck(52, 1, 13);
    initializePlayers(numPlayers, initialPurses, allPlayers);
    std::cout << "starting play\n";
    char playAgain = 'y';
    while(playAgain == 'y' || playAgain == 'Y') {
        warDeck.initializeDeck(DeckType::STD52);
        warDeck.shuffleDeck();
        dealCards(maxCardsAllowed, warDeck, allPlayers);
        while(allPlayers.front().haveCards()) {
            play(allPlayers);
        }
        declareWinner(allPlayers);
        std::cout << "would you like to play again?  ";
        std::cin.get(playAgain);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << '\n';
    }
    return 0;
} //end of main



int getNumPlayers(int minPlayers, int maxPlayers) {
    int retval = 0;
    while(retval < minPlayers || retval > maxPlayers) {
        std::cout << "Enter the number of players from " << minPlayers << " - " << maxPlayers << " :  ";
        std::cin >> retval;
        std::cin.ignore();
        if(retval < minPlayers || retval > maxPlayers) {
            std::cout << "invalid entry - Try Again!\n";
        } else {
            std::cout << "The game will proceed with " << retval << " players.\n";
        }
    }
    return retval;
}

void initializePlayers(int numPlayers, int initialPurses, std::vector<CardPlayer>& players){
    for(int i = 0; i < numPlayers; i++){
        std::string playerName;
        // std::cout << "Enter the name for player " << i + 1 << ": ";
        // getline(std::cin, playerName, '\n');
        playerName = std::to_string(i + 1);
        players.push_back(CardPlayer(initialPurses, playerName));
    }
}

void dealCards(int maxCardsAllowed, CardDeck& warDeck, std::vector<CardPlayer>& allPlayers) {
    int numPlayers = allPlayers.size();
    for(int i = 0; i < maxCardsAllowed; i++){
        for(int p = 0; p < numPlayers; p++){
            Card card = warDeck.dealCard();
            allPlayers.at(p).drawCard(card);
        }
    }
}

void play(std::vector<CardPlayer>& players) {
    bool winner = false;
    int cardsDown = 0;
    std::map<int, int> playedCards;
    while(!winner && players.front().haveCards()) {
        for(int i= 0; i < players.size(); i++) {
            Card card = players.at(i).playCard();
            if(card.getVal() == 0) {
                std::cout << "*********************ERROR*******************\n";
            }
            std::cout << "\tP" << i + 1 << ": " << card;
            playedCards.insert(std::pair<int, int>(card.getVal(), i));
            cardsDown++;
        }
        //eval highest two cards in play
        std::map<int, int>::reverse_iterator rit = playedCards.rbegin();
        rit++;
        winner = !(rit->first == playedCards.rbegin()->first);
        if(!winner) {
            std::cout << "\tTIE!\n";
        } else {
            std::cout << "\t\tPlayer " << playedCards.rbegin()->second + 1 << " wins " << cardsDown << "pts\n";
            players.at(playedCards.rbegin()->second).addNumWin(1);
        }
    }
    //somehow have to add money to purse
    players.at(playedCards.rbegin()->second).addToPurse(cardsDown);
}

void declareWinner(std::vector<CardPlayer>& allPlayers) {
    int totals = 0;
    std::sort(allPlayers.begin(), allPlayers.end());
    std::cout << "\nHere are the rankings:\n";
    for(int i = allPlayers.size() -1; i >= 0; i--) {
        std::cout << "player " << allPlayers.at(i).getName() << " purse: " << allPlayers.at(i).checkPurseVal() << "\tgames won: " << allPlayers.at(i).getNumWins() << "\n";
        totals += allPlayers.at(i).checkPurseVal();
    }
    // just another way to loop through the vector using a reverse iterator
    // for(std::vector<CardPlayer>::reverse_iterator ri=allPlayers.rbegin(); ri != allPlayers.rend(); ri++){
    //     std::cout << "player " << ri->getName() << " purse: " << ri->checkPurseVal() << "\tgames won: " << ri->getNumWins() << "\n";

    // }
    std::cout << "Totals: " << totals << "\n";
}


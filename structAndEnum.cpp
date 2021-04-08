#include <iostream>
#include <string>

enum CoinType{QUARTER, DIME, NICKEL, PENNY};

struct MailAddress {
    std::string street;
    std::string city;
    std::string state;
    int zip;
};

void printAddress(MailAddress address);

int main(){

CoinType coin = QUARTER;
MailAddress parentAddress;
MailAddress myAddress;
MailAddress toPrint;

switch(coin) {
    case QUARTER :
        parentAddress.street = "Mohawk";
        parentAddress.city = "Boise";
        parentAddress.state = "Confusion";
        parentAddress.zip = 12345;
        std::cout << "parent Address set\n";
        toPrint = parentAddress;
        break;
    case DIME :
        myAddress.street = "Glen Dr.";
        myAddress.city = "Fruit Heights";
        myAddress.state = "Deseret";
        myAddress.zip = 66666;
        std::cout << "my address was set";
        toPrint = myAddress;
        break;
    default :
        std::cout << "No addresses were set\n";
}
printAddress(toPrint);
return 0;
}

void printAddress(MailAddress address) {
    std::cout << 
    "street: " << address.street << "\n"
    "city: " << address.city << "\n"
    "state: " << address.state << "\n"
    "zip: " << address.zip << "\n";
}

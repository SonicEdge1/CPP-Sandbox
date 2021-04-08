template<class ItemType>
class OrdPair
{
public:
    OrdPair(ItemType m, ItemType n);
    ItemType First() const;
    ItemType Second() const;
    void Print() const;
private:
    ItemType first;
    ItemType second;
};

#include <iostream>
template<class ItemType>
OrdPair<ItemType>::OrdPair(ItemType m, ItemType n) {
    if(m > n) {
        first = m; second = n;
    } else {
        first = n; second = m;
    }
}

template<class ItemType>
ItemType OrdPair<ItemType>::First() const {
    return first;
}

template<class ItemType>
ItemType OrdPair<ItemType>::Second() const {
    return second;
}

template<class ItemType>
void OrdPair<ItemType>::Print() const {
    std::cout << "[ " << first << ", " << second << " ]\n";
}



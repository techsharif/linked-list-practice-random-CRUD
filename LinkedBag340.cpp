//	LinkedBag340.cpp
//	Created by: CSC340 Student

/*
	===>					<===
	===>  PLEASE ADD CODE	<===
	===>					<===
*/

// getCurrentSize340Recursive() 
// Friendly reminder:
// - This function must be a recursive function of immediate recursion type.
// - Or (if needed) it can call one recursive function of immediate recursion type.
// - In either case, recursive call(s) must be used to accomplish the main task of the function. 

// getFrequencyOf340Recursive()
// Friendly reminder:
// - This function must be a recursive function of immediate recursion type.
// - Or (if needed) it can call one recursive function of immediate recursion type.
// - In either case, recursive call(s) must be used to accomplish the main task of the function. 

// A recursive function of immediate recursion type is a function which calls itself.

#include <ctime>
int random_number(int size){

    time_t timer;
    struct tm y2k = {0};
    double seconds;
    y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
    y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;
    time(&timer);
    seconds = difftime(timer,mktime(&y2k));
    return int(seconds) % size;
}

template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {
    std::vector<ItemType> items =  toVector();

    if (itemCount >= 2){
        remove(items[1]);
        return true;
    }
    return false;
}


template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& item) {
    std::vector<ItemType> items =  toVector();
    for (int i=0; i<items.size(); i++){
        remove(items[i]);
    }
    bool result = add(item);

    for (int i=items.size()-1; i>=0 ;i--){
        add(items[i]);
    }
    return result;
}



template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
    int count = 0;
    Node<ItemType>* curPtr = headPtr;
    int counter = 0;

    while ((curPtr != nullptr) && (counter < itemCount)) {
        count ++;
        curPtr = curPtr->getNext();
        counter++;
    }

    return count;
}



template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
    return getCurrentSize340RecursiveHelper(headPtr);
}



template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& anEntry) const {
    return getFrequencyOf340RecursiveHelper(headPtr, anEntry);
}

template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
    std::vector<ItemType> items =  toVector();

    if (itemCount){
        int index = random_number(itemCount);
        remove(items[index]);
        return items[index];
    }

    return nullptr;
}


template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* item) const {
    if (item == nullptr) return 0;
    return getCurrentSize340RecursiveHelper(item->getNext()) + 1;

}


template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* item, const ItemType& anEntry) const {
    if (item == nullptr) return 0;
    if (anEntry == item->getItem())
        return 1 + getFrequencyOf340RecursiveHelper(item->getNext(), anEntry);
    else
        return getFrequencyOf340RecursiveHelper(item->getNext(), anEntry);
}
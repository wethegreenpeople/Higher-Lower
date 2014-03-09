#include <iostream>
#include <string>
#include <vector>

int main()
{
    int card = 0;
    
    std::vector<int> deck{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    
    std::cout << "Enter a card: ";
    
    while(std::cin >> card){
        double cnt = -1;
        
        auto deckEnd = deck.end();
        
        // Until the card hits the end of the deck, add one to count. So we can tell how many cards are higher than the currently drawn card
        while (card < *deckEnd){
            --deckEnd;
            ++cnt;
        }
        
        if (card == 13){
            deck.erase(deck.end() - 1);
        }
        
        else {
            deck.erase(deck.end() - ((cnt + 1)));
        }
    
        // Number of cards that are higher
        std::cout << cnt << std::endl;
        
        
        
        /*
        USED FOR DEBUGGING. WILL DISPLAY THE CONTENTS OF THE DECK.
        for (auto contents = deck.begin(); contents != deck.end(); ++contents)
            std::cout<< *contents << std::endl;
        */
        
        // Number of cards left
        std::cout << (deck.size()) - 1 << std::endl;
        
        // Chance of drawing a card that's higher
        std::cout << (cnt / ((deck.size()) - 1)) * 100 << "%" << std::endl;
        
    }
    
    return 0;
}

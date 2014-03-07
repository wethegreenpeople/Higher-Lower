#include <iostream>
#include <string>
#include <vector>

int main()
{
    int card, draw = 0;
    int lastPlayed;
    int simpleDraw = 0;
    
    std::vector<int> deck{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    
    std::cout << "Enter a card: ";
    
    while(std::cin >> card){
        double cnt = -1;
        
        auto deckEnd = deck.end();
        auto deckStart = deck.begin();
        
        while (card < *deckEnd){
            --deckEnd;
            ++cnt;
        }
        
        if (draw > 0 && card > lastPlayed){
            deck.erase(deck.begin() + (card - draw));
        }
        
        else if (draw > 0 && card < lastPlayed){
            deck.erase(deck.begin() + card - 1);
            
        }
        
        else{
        deck.erase((deck.begin() + card) - simpleDraw);
        ++simpleDraw;
        //deck.erase((deck.end() - deck.size()) + card);
        }
    
        // Number of cards that are higher
        std::cout << cnt << std::endl;
        
        
        
        // Used for debugging. Will output all the contents of the deck after chosen card has been removed.
        for (auto contents = deck.begin(); contents != deck.end(); ++contents)
            std::cout<< *contents << std::endl;
        
        
        // Number of cards left
        std::cout << deck.size() - 1 << std::endl;
        
        // Chance of drawing a card that's higher
        std::cout << (cnt / (deck.size() - 1)) * 100 << "%" << std::endl;
        
        ++draw;
        lastPlayed = card;
    }
    
    return 0;
}
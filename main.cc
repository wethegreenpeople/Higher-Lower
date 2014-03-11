#include <iostream>
#include <string>
#include <vector>

int main()
{
    int card = 0;
    
    std::vector<int> hearts{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    std::vector<int> spades{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    std::vector<int> deck{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    std::string suit;
    
    std::cout << "Enter a card, and a suit: ";
    
    while(std::cin >> card >> suit){
        double cnt = -1;
        
        auto heartsEnd = hearts.end();
        auto spadesEnd = spades.end();
        auto deckEnd = deck.end();
        
        // If the card is a heart, remove it from the appropriate deck.
        if (suit[0] == 'h'){
        
            // Until the card hits the end of the hearts, add one to count. So we can tell how many cards are higher than the currently drawn card
            while (card != *heartsEnd){
                --heartsEnd;
                ++cnt;
            }
            
            if (card == 13){
                hearts.erase(hearts.end() - 1);
            }
            
            else {
                hearts.erase(hearts.end() - ((cnt + 1)));
            }
            
            while (card != *spadesEnd){
                --spadesEnd;
                ++cnt;
            }
        
            // Number of cards that are higher
            cnt -= 1;
            std::cout << cnt << std::endl;
            
            
            
            /*
            USED FOR DEBUGGING. WILL DISPLAY THE CONTENTS OF THE hearts.
            for (auto contents = hearts.begin(); contents != hearts.end(); ++contents)
                std::cout<< *contents << std::endl;
            */
            
            // Number of cards left
            int totalCards = ((hearts.size() + spades.size()) - 2);
            std::cout << totalCards << std::endl;
            
            // Chance of drawing a card that's higher
            std::cout << (cnt / totalCards) * 100  << "%" << std::endl;
            }
        
        else if (suit[0] == 's'){
            while (card != *spadesEnd){
                --spadesEnd;
                ++cnt;
            }
            
            if (card == 13){
                spades.erase(spades.end() - 1);
            }
            
            else {
                spades.erase(spades.end() - ((cnt + 1)));
            }
            
            while (card != *heartsEnd){
                --heartsEnd;
                ++cnt;
            }
            
            cnt -= 1;
            std::cout << cnt << std::endl;
            
            // Number of cards left
            int totalCards = ((hearts.size() + spades.size()) - 2);
            std::cout << totalCards << std::endl;
            
            // Chance of drawing a card that's higher
            std::cout << (cnt / totalCards) * 100  << "%" << std::endl;
            
            }
        
        else{
            return 0;
        }
        
    }
    
    return 0;
}

#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Visualizer
{
public:
    // this is the constructor
    Visualizer(std::vector<int>& arr, std::string algoName);

    // this draws the bars
    void drawBars();

    // this sets the highlight for bars
    void setHighlight(int idx1, int idx2, sf::Color color);

    // this marks a bar as sorted
    void markSorted(int idx);

    // this updates the screen
    void updateDisplay();

    // this adds a delay
    void delay(int ms);

    // this checks if window is open
    bool isOpen();

    // this handles window events
    bool handleEvents();

    sf::RenderWindow window;

private:
    std::vector<int>& data;
    std::string algorithmName;
    unsigned int screenWidth;
    unsigned int screenHeight;
    sf::Font font;
    bool fontLoaded;
    std::vector<sf::Color> highlightColors;
    std::vector<bool> sortedIndices;
};

#endif // VISUALIZER_H

#ifndef VISUALIZER_H
#define VISUALIZER_H
//All the declarations are in this header file
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
using namespace std;

class Visualizer
{
public:
    //constructor
    Visualizer(vector<int>& arr, string algoName);

    //draws the bars
    void drawBars();

    //sets the highlight for bars
    void setHighlight(int idx1, int idx2, sf::Color color);

    // this marks a bar as sorted (green)
    void markSorted(int idx);

    void updateDisplay();

    // this adds a delay between the sorts so that we could see htem
    void delay(int ms);

    // this checks if window is open
    bool isOpen();

    // this handles window events
    bool handleEvents();

    sf::RenderWindow window;

private:
    vector<int>& data;
    string algorithmName;
    unsigned int screenWidth;
    unsigned int screenHeight;
    sf::Font font;
    bool fontLoaded;
    vector<sf::Color> highlightColors;
    vector<bool> sortedIndices;
};

#endif

#include "Visualizer.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
using namespace std;

// defination of constructor
Visualizer::Visualizer(vector<int>& arr, string algoName)
    : data(arr), algorithmName(algoName), fontLoaded(false)
{
    // this gets the screen resolution
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    screenWidth = desktopMode.width;
    screenHeight = desktopMode.height;

    // this creates the window
    window.create(desktopMode, "Sorting Visualizer - " + algorithmName, sf::Style::Fullscreen);

    // this tries to load the font
    if (font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
    {
        fontLoaded = true;
    }
    else if (font.loadFromFile("C:/Windows/Fonts/consola.ttf"))
    {
        fontLoaded = true;
    }
    else
    {
        cout << "Warning: Could not load any font. Text will not be displayed."<<endl;
        fontLoaded = false;
    }

    // this initializes the colors for bars
    highlightColors.resize(data.size(), sf::Color::Transparent);
    sortedIndices.resize(data.size(), false);
}

// this function draws all the bars
void Visualizer::drawBars()
{
    int maxValue = *max_element(data.begin(), data.end());
    int totalBars = data.size();
    float barWidth = (float)screenWidth / totalBars;
    float topMargin = 60.0f;
    float availableHeight = screenHeight - topMargin;

    // this loop draws every bar
    for (int i = 0; i < totalBars; i++)
    {
        float barHeight = ((float)data[i] / maxValue) * availableHeight;
        sf::RectangleShape bar;
        bar.setSize(sf::Vector2f(barWidth - 1.0f, barHeight));
        bar.setPosition(i * barWidth, screenHeight - barHeight);

        // this sets the bar color
        if (highlightColors[i] != sf::Color::Transparent)
        {
            bar.setFillColor(highlightColors[i]);
        }
        else if (sortedIndices[i])
        {
            bar.setFillColor(sf::Color::Green);
        }
        else
        {
            bar.setFillColor(sf::Color::White);
        }

        window.draw(bar);
    }
}

// this function highlights bars being compared
void Visualizer::setHighlight(int idx1, int idx2, sf::Color color)
{
    for (int i = 0; i < (int)highlightColors.size(); i++)
    {
        highlightColors[i] = sf::Color::Transparent;
    }

    if (idx1 >= 0 && idx1 < (int)highlightColors.size())
    {
        highlightColors[idx1] = color;
    }
    if (idx2 >= 0 && idx2 < (int)highlightColors.size())
    {
        highlightColors[idx2] = color;
    }
}

// this function marks a bar as sorted
void Visualizer::markSorted(int idx)
{
    if (idx >= 0 && idx < (int)sortedIndices.size())
    {
        sortedIndices[idx] = true;
        highlightColors[idx] = sf::Color::Transparent;
    }
}

// this function updates the screen
void Visualizer::updateDisplay()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            window.close();
        }
    }

    window.clear(sf::Color::Black);
    drawBars();

    // this draws the text at the top
    if (fontLoaded)
    {
        sf::Text titleText;
        titleText.setFont(font);
        titleText.setString(algorithmName);
        titleText.setCharacterSize(30);
        titleText.setFillColor(sf::Color::White);
        titleText.setStyle(sf::Text::Bold);

        sf::FloatRect textBounds = titleText.getLocalBounds();
        titleText.setPosition(
            (screenWidth - textBounds.width) / 2.0f,
            10.0f
        );

        window.draw(titleText);
    }

    window.display();
}

// this function adds a delay
void Visualizer::delay(int ms)
{
    sf::sleep(sf::milliseconds(ms));
}

// this checks if window is still open
bool Visualizer::isOpen()
{
    return window.isOpen();
}

// this handles window events and pressing the esc key
bool Visualizer::handleEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
            return false;
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            window.close();
            return false;
        }
    }
    return true;
}

#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Visualizer.h"

using namespace std;

// these are the sorting functions
void bubbleSort(Visualizer& viz, std::vector<int>& arr);
void selectionSort(Visualizer& viz, std::vector<int>& arr);
void mergeSort(Visualizer& viz, std::vector<int>& arr);

int main()
{
    int arraySize = 50;
    
    // this loop runs the menu
    while (true)
    {
        // this prints the menu
        cout << "\n========================================" << endl;
        cout << "   Sorting Algorithm Visualizer (SFML)" << endl;
        cout << "========================================" << endl;
        cout << "\n Array Size: " << arraySize << " elements" << endl;
        cout << "\n Select Sorting Algorithm:" << endl;
        cout << "  1. Bubble Sort" << endl;
        cout << "  2. Selection Sort" << endl;
        cout << "  3. Merge Sort" << endl;
        cout << "  0. Exit" << endl;
        cout << "\n Enter choice: ";

        // this gets user choice
        int choice;
        cin >> choice;

        // this exits the program
        if (choice == 0)
        {
            cout << "\n Goodbye!" << endl;
            break;
        }

        // this checks if choice is okay
        if (choice < 0 || choice > 3)
        {
            cout << "\n Invalid choice. Please try again." << endl;
            continue;
        }

        // this sets the algorithm name
        string algoName;
        if (choice == 1)
        {
            algoName = "Bubble Sort";
        }
        else if (choice == 2)
        {
            algoName = "Selection Sort";
        }
        else if (choice == 3)
        {
            algoName = "Merge Sort";
        }

        // this fills the array with shuffled numbers 1 to 50
        vector<int> arr = {45, 2, 31, 10, 49, 15, 27, 4, 38, 12, 
                           50, 1, 33, 8, 42, 19, 26, 7, 44, 21, 
                           35, 6, 29, 14, 47, 11, 23, 17, 39, 3, 
                           48, 20, 32, 9, 41, 13, 25, 5, 46, 22, 
                           34, 18, 30, 16, 43, 24, 36, 28, 40, 37};

        cout << "\n Starting " << algoName << " visualization..." << endl;
        cout << " Press ESC or close the window to return to menu.\n" << endl;

        // this opens the visualization screen
        Visualizer viz(arr, algoName);

        // this shows the first frame
        viz.updateDisplay();
        viz.delay(500);

        // this starts the sorting
        if (choice == 1)
        {
            bubbleSort(viz, arr);
        }
        else if (choice == 2)
        {
            selectionSort(viz, arr);
        }
        else if (choice == 3)
        {
            mergeSort(viz, arr);
        }

        // this keeps the window open
        while (viz.isOpen())
        {
            if (!viz.handleEvents())
            {
                break;
            }
            viz.delay(16);
        }

        cout << " Visualization complete. Returning to menu..." << endl;
    }

    return 0;
}
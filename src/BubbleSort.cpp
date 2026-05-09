#include "Visualizer.h"
#include <vector>

// this function does the bubble sort
void bubbleSort(Visualizer& viz, std::vector<int>& arr)
{
    // this gets the array size
    int n = arr.size();

    // this is the main loop for sorting
    for (int i = 0; i < n - 1; i++)
    {
        // this checks if user closed the window
        if (!viz.isOpen())
        {
            return;
        }

        // this loop compares elements
        for (int j = 0; j < n - 1 - i; j++)
        {
            // this checks if user closed the window
            if (!viz.isOpen())
            {
                return;
            }

            // this highlights the bars being compared
            viz.setHighlight(j, j + 1, sf::Color::Red);
            viz.updateDisplay();
            viz.delay(10);

            // this swaps the elements if they are in wrong order
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // this shows the swap
                viz.updateDisplay();
                viz.delay(10);
            }
        }

        // this marks the element as sorted
        viz.markSorted(n - 1 - i);
        viz.updateDisplay();
    }

    // this marks the last element as sorted
    viz.markSorted(0);
    viz.updateDisplay();
}

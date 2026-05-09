#include "Visualizer.h"
#include <vector>

// this function does the selection sort
void selectionSort(Visualizer& viz, std::vector<int>& arr)
{
    int n = arr.size();

    // this loop finds the smallest element
    for (int i = 0; i < n - 1; i++)
    {
        if (!viz.isOpen()) return;

        int minIndex = i;

        // this loop looks through the unsorted part
        for (int j = i + 1; j < n; j++)
        {
            if (!viz.isOpen()) return;

            // this highlights what is being compared
            viz.setHighlight(minIndex, j, sf::Color::Red);
            viz.updateDisplay();
            viz.delay(10);

            // this updates the min index if smaller value found
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // this swaps the min element into place
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;

            viz.setHighlight(i, minIndex, sf::Color::Red);
            viz.updateDisplay();
            viz.delay(10);
        }

        // this marks the element as sorted
        viz.markSorted(i);
        viz.updateDisplay();
    }

    // this marks the last element sorted
    viz.markSorted(n - 1);
    viz.updateDisplay();
}

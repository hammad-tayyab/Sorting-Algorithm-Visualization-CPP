#include "Visualizer.h"
#include <vector>

// this function does the insertion sort
void insertionSort(Visualizer& viz, std::vector<int>& arr)
{
    // this gets the array size
    int n = arr.size();

    // this is the main outer loop, starts from second element
    for (int i = 1; i < n; i++)
    {
        // this checks if user closed the window
        if (!viz.isOpen())
        {
            return;
        }

        // this stores the current element that needs to be placed
        int key = arr[i];
        int j = i - 1;

        // this loop shifts larger elements one position to the right
        while (j >= 0 && arr[j] > key)
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

            // this shifts the element one position to the right
            arr[j + 1] = arr[j];
            j--;

            // this shows the shift
            viz.updateDisplay();
            viz.delay(10);
        }

        // this places the key in its correct position
        arr[j + 1] = key;

        // this marks the current position as part of sorted region
        viz.markSorted(i);
        viz.updateDisplay();
        viz.delay(10);
    }

    // this marks the first element as sorted
    viz.markSorted(0);
    viz.updateDisplay();
}

#include "Visualizer.h"
#include <vector>
//main function
void selectionSort(Visualizer& viz, std::vector<int>& arr)
{
    int n = arr.size();

    // finding the smallest element
    for (int i = 0; i < n - 1; i++)
    {
        if (!viz.isOpen()) return;

        int minIndex = i;
        // this loop looks through the unsorted part
        for (int j = i + 1; j < n; j++)
        {
            if (!viz.isOpen()) return;

            viz.setHighlight(minIndex, j, sf::Color::Red);
            viz.updateDisplay();
            viz.delay(10);

            // if smaller value found replace the min
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // swaps into place
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;

            viz.setHighlight(i, minIndex, sf::Color::Red);
            viz.updateDisplay();
            viz.delay(10);
        }

        viz.markSorted(i);
        viz.updateDisplay();
    }
//marking as sorted
    viz.markSorted(n - 1);
    viz.updateDisplay();
}

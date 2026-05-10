#include "Visualizer.h"
#include <vector>

//main fucntion for the insertion sort
void insertionSort(Visualizer& viz, std::vector<int>& arr)
{
    int n = arr.size();

    // main outer loop from the second element
    for (int i = 1; i < n; i++)
    {
        if (!viz.isOpen()){return;}

        // storing the current index that needs to be placed
        int key = arr[i];
        int j = i - 1;

        // shifting the larger elents one position to the right
        while (j >= 0 && arr[j] > key)
        {
            if (!viz.isOpen()){return;}

            // highlighting the bars being compared
            viz.setHighlight(j, j + 1, sf::Color::Red);
            viz.updateDisplay();
            viz.delay(10);

            // shifting the elements
            arr[j + 1] = arr[j];
            j--;

            // showing the changing
            viz.updateDisplay();
            viz.delay(10);
        }

        // one uping the key
        arr[j + 1] = key;

        //marking the sorted elements
        viz.markSorted(i);
        viz.updateDisplay();
        viz.delay(10);
    }

    // marks the element as sorted
    viz.markSorted(0);
    viz.updateDisplay();
}

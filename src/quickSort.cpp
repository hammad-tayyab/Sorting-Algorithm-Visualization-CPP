#include "Visualizer.h"
#include <vector>

// this helper function partitions the array around a pivot
static int partition(Visualizer& viz, std::vector<int>& arr, int low, int high)
{
    // this picks the last element as the pivot
    int pivot = arr[high];
    int i = low - 1;

    // this loop moves elements smaller than pivot to the left side
    for (int j = low; j < high; j++)
    {
        // this checks if user closed the window
        if (!viz.isOpen())
        {
            return i + 1;
        }

        // this highlights the element being compared with pivot
        viz.setHighlight(j, high, sf::Color::Red);
        viz.updateDisplay();
        viz.delay(10);

        // this checks if the current element belongs on the left side
        if (arr[j] <= pivot)
        {
            i++;

            // this swaps the element into the smaller-elements zone
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            // this shows the swap
            viz.updateDisplay();
            viz.delay(10);
        }
    }

    // this places the pivot in its correct final position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    // this marks the pivot as permanently sorted
    viz.markSorted(i + 1);
    viz.updateDisplay();
    viz.delay(10);

    return i + 1;
}

// this helper function recursively sorts the left and right halves
static void quickSortHelper(Visualizer& viz, std::vector<int>& arr, int low, int high)
{
    // this checks if user closed the window
    if (!viz.isOpen())
    {
        return;
    }

    // this is the base case: a single element is already sorted
    if (low < high)
    {
        // this partitions the array and gets the pivot's final index
        int pivotIndex = partition(viz, arr, low, high);

        // this sorts the left side of the pivot
        quickSortHelper(viz, arr, low, pivotIndex - 1);

        // this sorts the right side of the pivot
        quickSortHelper(viz, arr, pivotIndex + 1, high);
    }
}

// this function does the quick sort
void quickSort(Visualizer& viz, std::vector<int>& arr)
{
    // this calls the helper with the full array range
    quickSortHelper(viz, arr, 0, (int)arr.size() - 1);
}

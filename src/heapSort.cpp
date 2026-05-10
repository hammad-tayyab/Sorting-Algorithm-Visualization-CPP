#include "Visualizer.h"
#include <vector>

// this helper function fixes the heap property at a given node
static void heapify(Visualizer& viz, std::vector<int>& arr, int heapSize, int i)
{
    // this checks if user closed the window
    if (!viz.isOpen())
    {
        return;
    }

    // this assumes the current node is the largest
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    // this checks if the left child exists and is larger than current largest
    if (leftChild < heapSize)
    {
        // this highlights the comparison between parent and left child
        viz.setHighlight(largest, leftChild, sf::Color::Red);
        viz.updateDisplay();
        viz.delay(10);

        if (arr[leftChild] > arr[largest])
        {
            largest = leftChild;
        }
    }

    // this checks if the right child exists and is larger than current largest
    if (rightChild < heapSize)
    {
        // this highlights the comparison between current largest and right child
        viz.setHighlight(largest, rightChild, sf::Color::Red);
        viz.updateDisplay();
        viz.delay(10);

        if (arr[rightChild] > arr[largest])
        {
            largest = rightChild;
        }
    }

    // this swaps and continues heapifying if a child was larger than the parent
    if (largest != i)
    {
        // this swaps the parent with its largest child
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // this shows the swap
        viz.updateDisplay();
        viz.delay(10);

        // this fixes the affected subtree after the swap
        heapify(viz, arr, heapSize, largest);
    }
}

// this function does the heap sort
void heapSort(Visualizer& viz, std::vector<int>& arr)
{
    // this gets the array size
    int n = arr.size();

    // this builds the max heap by heapifying from the last non-leaf node upward
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        // this checks if user closed the window
        if (!viz.isOpen())
        {
            return;
        }

        // this heapifies the subtree rooted at index i
        heapify(viz, arr, n, i);
    }

    // this extracts the largest element one by one from the heap
    for (int i = n - 1; i > 0; i--)
    {
        // this checks if user closed the window
        if (!viz.isOpen())
        {
            return;
        }

        // this moves the current largest element to its final position at the end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // this marks the extracted element as sorted
        viz.markSorted(i);
        viz.updateDisplay();
        viz.delay(10);

        // this restores the heap property for the remaining heap
        heapify(viz, arr, i, 0);
    }

    // this marks the last remaining element as sorted
    viz.markSorted(0);
    viz.updateDisplay();
}

#include "Visualizer.h"
#include <vector>

// this helper function makes the heap
static void heapify(Visualizer& viz, std::vector<int>& arr, int heapSize, int i)
{
    if (!viz.isOpen())
    {
        return;
    }

    //assuming that the curent node is the largest
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    // checking if the left child exists and is larger than the largest
    if (leftChild < heapSize)
    {
        // highlighting the ccomparision
        viz.setHighlight(largest, leftChild, sf::Color::Red);
        viz.updateDisplay();
        viz.delay(10);

        if (arr[leftChild] > arr[largest]) //main logic fo rthe if
        {
            largest = leftChild;
        }
    }

    // this checks the right child similarly
    if (rightChild < heapSize)
    {
        viz.setHighlight(largest, rightChild, sf::Color::Red);
        viz.updateDisplay();
        viz.delay(10);

        if (arr[rightChild] > arr[largest])
        {
            largest = rightChild;
        }
    }

    // this swaps and continue to heapify if the child is larger
    if (largest != i)
    {
        // swapping with the largest child
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        viz.updateDisplay();
        viz.delay(10);

        // heapifiying after the swap
        heapify(viz, arr, heapSize, largest);
    }
}

// main heapsorting function
void heapSort(Visualizer& viz, std::vector<int>& arr)
{
    //array size
    int n = arr.size();
    // this builds the max heap by heapifying from the last non heap member
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        if (!viz.isOpen())
        {
            return;
        }

        //this heapifies the subroot and index i
        heapify(viz, arr, n, i);
    }

    // extracting the largest element one by one
    for (int i = n - 1; i > 0; i--)
    {
        if (!viz.isOpen()) {return;}

        // this moces the largest element in the heap to its end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // maeking the extrackted element as sorted
        viz.markSorted(i);
        viz.updateDisplay();
        viz.delay(10);

        // this fixes the heap
        heapify(viz, arr, i, 0);
    }
    //marking the element as sorted
    viz.markSorted(0);
    viz.updateDisplay();
}

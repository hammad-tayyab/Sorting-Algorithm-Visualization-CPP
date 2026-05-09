#include "Visualizer.h"
#include <vector>

// this function merges two sorted halves
void merge(Visualizer& viz, std::vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // this makes temporary arrays
    std::vector<int> L(n1), R(n2);

    // this copies data to the temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0; 
    int j = 0; 
    int k = left; 

    // this merges them back together
    while (i < n1 && j < n2)
    {
        if (!viz.isOpen()) return;

        // this highlights what is being compared
        viz.setHighlight(left + i, mid + 1 + j, sf::Color::Red);
        viz.updateDisplay();
        viz.delay(10);

        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
        
        viz.updateDisplay();
    }

    // this copies any left over elements
    while (i < n1)
    {
        if (!viz.isOpen()) return;
        arr[k] = L[i];
        i++;
        k++;
        viz.updateDisplay();
        viz.delay(10);
    }

    // this copies any remaining right elements
    while (j < n2)
    {
        if (!viz.isOpen()) return;
        arr[k] = R[j];
        j++;
        k++;
        viz.updateDisplay();
        viz.delay(10);
    }
}

// this function sorts the array recursively
void mergeSortRecursive(Visualizer& viz, std::vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // this sorts both halves
        mergeSortRecursive(viz, arr, left, mid);
        mergeSortRecursive(viz, arr, mid + 1, right);

        // this merges them
        merge(viz, arr, left, mid, right);
    }
}

// this is the main entry point for merge sort
void mergeSort(Visualizer& viz, std::vector<int>& arr)
{
    if (arr.empty()) return;

    mergeSortRecursive(viz, arr, 0, arr.size() - 1);

    // this marks all bars as sorted
    for (int i = 0; i < (int)arr.size(); i++)
    {
        viz.markSorted(i);
    }
    viz.updateDisplay();
}

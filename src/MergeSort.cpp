#include "Visualizer.h"
#include <vector>

// merge function
void merge(Visualizer& viz, std::vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // making the two half arrays
    std::vector<int> L(n1), R(n2);

    // copying the data in those arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0; 
    int j = 0; 
    int k = left; 

    // this merging them back
    while (i < n1 && j < n2)
    {
        if (!viz.isOpen()) return;

        // highlighting the compared elements
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

    // copying any left over elements
    while (i < n1)
    {
        if (!viz.isOpen()) return;
        arr[k] = L[i];
        i++;
        k++;
        viz.updateDisplay();
        viz.delay(10);
    }

    // copying any remaining right elements
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

// sorting function
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

// BEHOLD THE MAIN FUCNTION .....
void mergeSort(Visualizer& viz, std::vector<int>& arr)
{
    if (arr.empty()) return;

    mergeSortRecursive(viz, arr, 0, arr.size() - 1); //fucniton call

    // markgin the sorted bar
    for (int i = 0; i < (int)arr.size(); i++)
    {
        viz.markSorted(i);
    }
    viz.updateDisplay();
}

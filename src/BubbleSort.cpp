#include "Visualizer.h"
#include <vector>
using namespace std;
// main fucntion for the bubble sort
void bubbleSort(Visualizer& viz, vector<int>& arr)
{
    int n = arr.size(); //size of array

    // main loop
    for (int i = 0; i < n - 1; i++)
    {
        // checking if user closed the window manually
        if (!viz.isOpen())
        {//returning if true
            return;
        }

        // comparing loop
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (!viz.isOpen()){return;}//again

            // highliting the comparing bars with red
            viz.setHighlight(j, j + 1, sf::Color::Red);
            viz.updateDisplay();
            viz.delay(10);//delay to show results

            // this swaps the elements if they are in wrong order
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                //showing  the swap
                viz.updateDisplay();
                viz.delay(10);
            }
        }

        //markign the element as sorted
        viz.markSorted(n - 1 - i);
        viz.updateDisplay();
    }

    // this marks the last element as sorted
    viz.markSorted(0);
    viz.updateDisplay(); //updatign afterwards
}

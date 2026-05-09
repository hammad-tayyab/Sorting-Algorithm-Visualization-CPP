# Sorting Algorithm Visualizer (C++ & SFML)

A simple, interactive tool to visualize how different sorting algorithms work in real-time.

## Project Overview
This project uses the **SFML 2.5** library to render an array of integers as a series of bars. As the algorithm sorts the array, the bars move and change colors to show comparisons and swaps.

### Algorithms Included
- **Bubble Sort**: Compares adjacent elements and "bubbles" the largest to the end.
- **Selection Sort**: Finds the minimum element and places it at the start.
- **Merge Sort**: A divide-and-conquer algorithm that recursively splits and merges the array.

## How it Works
1. **Visualizer Class**: Handles the window creation, bar rendering, and coloring (Red for comparisons, Green for sorted elements).
2. **Main Functions**:
   - `bubbleSort()`: Implements bubble sort with visualization calls.
   - `selectionSort()`: Implements selection sort with visualization calls.
   - `mergeSort()`: Implements merge sort with visualization calls.
   - `main()`: Handles the console menu and initializes the shuffled array.

## How to Run

### 1. Build the Project
Press **`Ctrl + Shift + B`** in VS Code. This will trigger the build task to compile the source files.

### 2. Run the Program
Go to the `bin/` folder and run the `main.exe` file:
```bash
cd bin
./main.exe
```

## Controls
- Use the **Console** to select an algorithm (1-3) or exit (0).
- Press **ESC** while a visualization is running to return to the menu.

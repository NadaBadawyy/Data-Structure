#include <iostream>  // Include input-output stream library
#include <vector>    // Include vector library (not used in the current code, but good to have if needed)
using namespace std;

// Template function for selection sort
template<class t>
void selectionsort(t arr[], int n) {
    int min; // Variable to store the index of the minimum element
    for (int i = 0; i < n; ++i) {
        min = i; // Assume the current element is the minimum
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min]) // Find the actual minimum element in the unsorted part
                min = j;
        }
        if (min != i) {
            swap(arr[i], arr[min]); // Swap the found minimum element with the current element
        }
    }
}

// Template function for bubble sort
template<class t>
void bubblesort(t arr[], int n) {
    bool f = 1; // Flag to detect any swap
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // Swap if elements are in the wrong order
                f = 0; // Set flag to indicate a swap occurred
            }
        }
        if (f == 1)
            break;  // No swap means the array is sorted
    }
}

// Template function for insertion sort
template<class t>
void insertionsort(t arr, int n) {
    t key; // Element to be positioned
    int j;
    for (int i = 1; i < n; ++i) {
        key = arr[i]; // Select the element to be inserted
        j = i - 1;
        while (j >= 0 && key < arr[j]) { // Shift elements to the right to make space for the key
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Insert the key at the correct position
    }
}

// Template function to merge two halves of an array
template<class t>
void merge(t arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1; // Length of the first half
    int n2 = r - m; // Length of the second half
    t* left = new t[n1]; // Temporary array for the first half
    t* right = new t[n2]; // Temporary array for the second half

    for (int n = 0; n < n1; ++n) {
        left[n] = arr[n + l]; // Copy elements to the left array
    }
    for (int n = 0; n < n2; ++n) {
        right[n] = arr[m + 1 + n]; // Copy elements to the right array
    }
    i = j = 0; // Initial indexes for left and right arrays
    k = l; // Initial index for merged array
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1) { // Copy remaining elements of left array
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) { // Copy remaining elements of right array
        arr[k] = right[j];
        j++;
        k++;
    }
    delete[] left; // Free the memory allocated for left array
    delete[] right; // Free the memory allocated for right array
}

// Template function for merge sort
template<class t>
void mergesort(t arr[], int l, int r) {
    if (l < r) {
        int m = (r + l) / 2; // Find the middle point
        mergesort(arr, l, m); // Recursively sort the first half
        mergesort(arr, m + 1, r); // Recursively sort the second half
        merge(arr, l, m, r); // Merge the two halves
    }
}

// Template function for quick sort
template<class t>
void quicksort(t arr[], int l, int r) {
    int i = l, j = r; // Initial indices for the left and right elements
    t pivot = arr[(l + r) / 2]; // Choose the pivot element
    // Partitioning process
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap(arr[i], arr[j]); // Swap elements to the correct side of the pivot
            i++;
            j--;
        }
    }
    // Recursively sort the sub-arrays
    if (l < j)
        quicksort(arr, l, j);
    if (r > i)
        quicksort(arr, i, r);
}

// Template function to heapify a subtree rooted at index root
template<class t>
void heapify(t arr[], int n, int root) {
    int l = root * 2 + 1; // Left child index
    int r = root * 2 + 2; // Right child index
    int max = root; // Initialize max as root
    if (l < n && arr[l] > arr[max])
        max = l;
    if (r < n && arr[r] > arr[max])
        max = r;
    if (root != max) {
        swap(arr[root], arr[max]); // Swap root and max
        heapify(arr, n, max); // Recursively heapify the affected sub-tree
    }
}

// Template function to build a heap from an array
template<class t>
void buildheap(t arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i); // Build heap from bottom up
    }
}

// Template function for heap sort
template<class t>
void heapsort(t arr[], int n) {
    buildheap(arr, n); // Build the heap
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // Move the root (maximum) to the end of the array
        heapify(arr, i, 0); // Call heapify on the reduced heap
    }
}

// Function for counting sort (only works for integer arrays)
void countsort(int arr[], int n) {
    int maxx = INT_MIN; // Initialize maximum element as the minimum integer value
    for (int i = 0; i < n; ++i) {
        if (arr[i] > maxx)
            maxx = arr[i];
    }
    maxx++; // Increment maxx to handle the largest value
    int freq[maxx]; // Frequency array
    for (int i = 0; i < maxx; ++i) {
        freq[i] = 0; // Initialize frequency array with zeros
    }
    for (int i = 0; i < n; ++i) {
        freq[arr[i]]++; // Count frequency of each element
    }
    int prefix[maxx]; // Prefix sum array
    for (int i = 0; i < maxx; ++i) {
        prefix[i] = freq[i];
        if (i > 0) {
            prefix[i] += prefix[i - 1]; // Calculate prefix sums
        }
    }
    int sortedarr[n]; // Sorted array
    for (int i = n - 1; i >= 0; --i) {
        int x = --prefix[arr[i]];
        sortedarr[x] = arr[i]; // Place elements in sorted order
    }
    for (int i = 0; i < n; ++i) {
        arr[i] = sortedarr[i]; // Copy sorted array back to original array
    }
}

// Template function to print an array
template<class t>
void print(t arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " "; // Print each element
    }
    cout << endl; // Print newline after the array
}

int main() {
    int arr[] = {1, 3, 2, 7, 0, 9, 7, 1}; // Sample array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
    quicksort(arr, 0, n - 1); // Sort the array using quick sort
    print(arr, n); // Print the sorted array
}

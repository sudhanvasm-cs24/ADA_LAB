#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace chrono;

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap (arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSortBottomUp(vector<int> &arr) {
    int n = arr.size();
    for (int i = n/2 - 1; i >= 0; i--) 
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap (arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void siftUp(vector<int> &heap, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] < heap[i]) {
            swap(heap[parent], heap[i]);
            i = parent;
        }
        else break;
    }
}

void buildTopDownHeap(vector<int> &arr, int n) {
    vector<int> heap;
    for (int i : arr) {
       heap.push_back(i);
       siftUp(heap, heap.size() - 1);
    }
    arr = heap;
}

void heapSortTopDown(vector<int> &arr) {
    int n = arr.size();
    buildTopDownHeap(arr, n);
    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(vector<int> &arr) {
    for (int i : arr) cout << i << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> data(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) cin >> data[i];

    vector<int> arr = data;
    auto start1 = high_resolution_clock::now();
    heapSortBottomUp(arr);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end1 - start1);
    cout << "Sorted (Bottom-Up): ";
    printArray(arr);
    cout << "Time taken (Bottom-Up): " << duration1.count() << " microseconds\n";

    arr = data;
    auto start2 = high_resolution_clock::now();
    heapSortTopDown(arr);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end2 - start2);
    cout << "Sorted (Top-Down): ";
    printArray(arr);
    cout << "Time taken (Top-Down): " << duration2.count() << " microseconds\n";

    cout << "Difference in Bottom-Up and Top-Down: " << abs(duration1.count() - duration2.count()) << " microseconds\n";
}
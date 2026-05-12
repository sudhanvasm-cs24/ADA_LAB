#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace chrono;

void heapify(vector<int> &arr, int n, int i) {
    int smallest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < n && arr[left] < arr[smallest]) smallest = left;
    if (right < n && arr[right] < arr[smallest]) smallest = right;

    if (smallest != i) {
        swap (arr[i], arr[smallest]);
        heapify(arr, n, smallest);
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
    cout << "Sorted in non-ascending order: ";
    printArray(arr);
    cout << "Time taken: " << duration1.count() << " microseconds\n";
}
#include <bits/stdc++.h>

const bool LEFT_TO_RIGHT  = true;
const bool RIGHT_TO_LEFT = false;

using namespace std;

int searchArr (vector<int> arr, int n, int mobile) {
    auto it = find(arr.begin(), arr.end(), mobile);
    return (it != arr.end()) ? (it - arr.begin() + 1) : 0;
}

int getMobile (vector<int> &arr, vector<bool> &dir, int n) {
    int mobile_prev = 0, mobile = 0;
    for (int i = 0; i < n; i++) {
        if (dir[arr[i] - 1] == RIGHT_TO_LEFT && i != 0) {
            if (arr[i] > arr[i - 1] && arr[i] > mobile_prev) {
                mobile = arr[i];
                mobile_prev = mobile;
            }
        }

        if (dir[arr[i] - 1] == LEFT_TO_RIGHT && i != n - 1) {
            if (arr[i] > arr[i + 1] && arr[i] > mobile_prev) {
                mobile = arr[i];
                mobile_prev = mobile;
            }
        }
    }
    
    if (!mobile && !mobile_prev) return 0;
    else return mobile;
}

void printOnePermutation(vector<int> &arr, vector<bool> &dir, int n, int mobile) {
    int pos = searchArr(arr, n, mobile);
    if (dir[arr[pos - 1] - 1] == RIGHT_TO_LEFT) swap(arr[pos - 1], arr[pos - 2]);
    else swap(arr[pos], arr[pos - 1]);

    for (int i = 0; i < n; i++) {
        if (arr[i]  > mobile) dir[arr[i] - 1] = !dir[arr[i] - 1];
    }

    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

void printPermutation (int n) {
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);
    vector<bool> dir (n, RIGHT_TO_LEFT);

    cout << "1. ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    int count = 1;
    while (true) {
        int mobile = getMobile(arr, dir, n);
        if (mobile == 0) break;
        cout << ++count << ". ";
        printOnePermutation(arr, dir, n, mobile);
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Permutations of numbers from 1 to n is \n";
    printPermutation(n);
}
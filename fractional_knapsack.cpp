#include <bits/stdc++.h>

using namespace std;

struct Item {
    int id, weight, profit;
    float ratio;
};

bool cmp (Item a, Item b) {
    return a.ratio > b.ratio;
}

void kanpsack(Item items[], int n, int capacity) {
    double totalProfit = 0.0;
    for (int i = 0; i < n; i++) {
        items[i].ratio = items[i].profit / items[i].weight;
    }
    sort(items, items + n, cmp);
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
            cout << "Took full from " << items[i].id << endl;
        }
        else {
            totalProfit += items[i].ratio * capacity;
            cout << "Took " << capacity << " from " << items[i].id << endl;
            break;
        }
    }
    cout << "\nTotal Profit: " << totalProfit;
}

int main () {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    struct Item items[n];
    cout << "Enter the item details\n";
    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        cout << "Enter weight of item " << items[i].id << ": ";
        cin >> items[i].weight;
        cout << "Enter profit of item " << items[i].id << ": ";
        cin >> items[i].profit;
        cout << endl;
    }
    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    kanpsack(items, n, capacity);
    return 0;
}
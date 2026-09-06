#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, capacity;
    cin >> n >> capacity;

    vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    sort(items.begin(), items.end(), compare);

    double maxProfit = 0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            maxProfit += items[i].value;
        } else {
            maxProfit += items[i].ratio * capacity;
            break;
        }
    }

    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    return (double)a.value / a.weight >
           (double)b.value / b.weight;
}

int main() {

    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter value and weight of each item:\n";

    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

   
    sort(items.begin(), items.end(), compare);

    double totalValue = 0;

    for (int i = 0; i < n; i++) {

        if (capacity >= items[i].weight) {

        
            capacity -= items[i].weight;
            totalValue += items[i].value;
        }
        else {

            
            totalValue += (double)items[i].value
                          / items[i].weight * capacity;

            capacity = 0;
            break;
        }
    }

    cout << "Maximum value = " << totalValue;

    return 0;
}


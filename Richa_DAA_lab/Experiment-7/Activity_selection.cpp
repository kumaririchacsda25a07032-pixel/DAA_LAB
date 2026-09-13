#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;

    cout << "Enter number of activities: ";
    cin >> n;

    Activity a[n];

    cout << "Enter start and finish time of each activity:\n";

    for (int i = 0; i < n; i++) {
        cin >> a[i].start >> a[i].finish;
    }

    // Sort activities according to finish time
    sort(a, a + n, compare);

    cout << "\nSelected activities:\n";

    // Select the first activity
    int lastFinish = a[0].finish;

    cout << "(" << a[0].start << ", " << a[0].finish << ") ";

    // Select remaining activities
    for (int i = 1; i < n; i++) {
        if (a[i].start >= lastFinish) {
            cout << "(" << a[i].start << ", " << a[i].finish << ") ";
            lastFinish = a[i].finish;
        }
    }

    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int matrixChain(vector<int>& p, int n) {
    int m = n - 1;  // Number of matrices

    vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

    for (int len = 2; len <= m; len++) {
        for (int i = 1; i <= m - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][m];
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << matrixChain(p, n) << endl;

    return 0;
}


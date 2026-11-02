#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n), profit(n);

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter profits of items:\n";
    for (int i = 0; i < n; i++)
        cin >> profit[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;
    // DP table: items x capacities
    vector<vector<int> > dp(n + 1, vector<int>(W + 1, 0));
    // Consider each item from the table(2d-mat)
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
        	// Include item if it fits
            if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    cout << "Maximum profit = " << dp[n][W] << endl;

    cout << "Selected items (1-based indexing): ";
    int w = W;

    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << i << " ";
            w -= weight[i - 1];
        }
    }
    //TC=O(nW) and SC=O(nw)
    cout << endl;
    return 0;
}
 
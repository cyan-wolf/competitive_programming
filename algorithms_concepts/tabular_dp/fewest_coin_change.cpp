/**
 * Given an array of coin denominations and a target amount, 
 * find the minimum number of coins needed to make up that amount. 
 * You can use each coin as many times as you want.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// NOTE: `INT_MAX` represents an empty value (since any min operation on it on a regular number will make the `INT_MAX` disappear).
// NOTE: -1 represents an error sentinel value, it is returned when a result cannot be computed using the given denominations 
//        and target amout (i.e. trying to find the coin amount for {3, 5} when the target amount is 2).

int count_fewest_coin_change_memo(const vector<int> &denominations, int target_amt, unordered_map<int, int> &cache) {
    if (cache.count(target_amt)) {
        return cache[target_amt];
    }
    else if (target_amt == 0) {
        return 0;
    }
    else {
        int min_coin_amt = INT_MAX;

        for (int d : denominations) {
            if (target_amt < d) {
                continue;
            }
            int new_target_amt = target_amt - d;
            int min_amt_for_d = count_fewest_coin_change_memo(denominations, new_target_amt, cache);

            // Skip failed subproblems.
            if (min_amt_for_d == -1) {
                continue;
            }
            min_coin_amt = min(min_coin_amt, 1 + min_amt_for_d);
        }

        // The minimum being INT_MAX means the subproblem failed.
        if (min_coin_amt == INT_MAX) {
            // Signal this subproblem was impossible to solve.
            return -1;
        }
        cache[target_amt] = min_coin_amt;
        return min_coin_amt;
    }
}

int count_fewest_coin_change_tabular(const vector<int> &denominations, int target_amt) {
    vector<int> dp(target_amt + 1, INT_MAX);
    dp[0] = 0;

    for (int t = 1; t < target_amt + 1; ++t) {
        for (int d : denominations) {
            if (t < d) {
                continue;
            }
            int new_target = t - d;
            int min_for_d = dp[new_target];

            if (min_for_d == -1) {
                continue;
            }
            dp[t] = min(dp[t], 1 + min_for_d);
        }
        if (dp[t] == INT_MAX) {
            dp[t] = -1;
        }
    }
    return dp[target_amt];
}

int main() {
    vector<int> denominations = {3, 5, 7};
    // unordered_map<int, int> cache;
    // int amt = count_fewest_coin_change_memo(denominations, 8, cache);

    int amt = count_fewest_coin_change_tabular(denominations, 8);
    cout << amt << endl;
}

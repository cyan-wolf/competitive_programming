#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

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

int main() {
    unordered_map<int, int> cache;
    vector<int> denominations = {3, 5, 7};
    int amt = count_fewest_coin_change_memo(denominations, 8, cache);
    cout << amt << endl;
}

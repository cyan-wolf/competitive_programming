/**
 * Fractional Knapsack Problem
 * 
 * Instead of only being able to either pick or not pick an item in the 
 * 0/1 Knapsack problem, here we can either:
 * - not pick an item
 * - pick the item
 * - pick a fraction of the item (i.e. half of it)
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

// First element is the ratio, second is the value, third is the weight of the item.
using Item = tuple<double, int, int>;

// O(n log(n))
double knapsack(const vector<int>& values, const vector<int>& weights, double capacity) {
    vector<Item> items(values.size());

    // O(n)
    for (int i = 0; i < values.size(); ++i) {
        double ratio = (double)values[i] / (double)weights[i];
        items[i] = {ratio, values[i], weights[i]};
    }
    // Sort in descending order by the ratio (tuples are ordered lexicographically).
    // O(n log(n))
    sort(items.begin(), items.end(), [](Item item1, Item item2) {return item1 > item2;});

    double acc_value = 0;
    double acc_weight = 0;

    // O(n)
    for (auto item : items) {
        auto [_, value, weight] = item;

        double new_weight = acc_weight + weight;

        // If the incoming item doesn't fit, we add whatever we can from this such that the knapsack 
        // is filled up to the capacity. Since we intend to fill up to the capacity, this is the last
        // item we process.
        if (new_weight > capacity) {
            double needed_weight = capacity - acc_weight;

            // The fraction of the incoming item necessary to fully fill up the knapsack.
            double needed_item_fraction = needed_weight / weight;

            // Add the value and weight corresponding to the fractional part we picked.
            acc_value += value * needed_item_fraction;
            acc_weight += weight * needed_item_fraction;

            // Exit the loop since we know that the knapsack is filled up to the capacity.
            break;
        }

        // Add the whole item to the knapsack if the item could it.
        acc_value += value;
        acc_weight += weight;
    }

    return acc_value;
}

int main() {
    int item_amt, capacity;
    cin >> item_amt >> capacity;

    vector<int> values(item_amt);
    vector<int> weights(item_amt);

    for (int i = 0; i < item_amt; ++i) {
        cin >> values[i];
    }
    for (int i = 0; i < item_amt; ++i) {
        cin >> weights[i];
    }

    double max_value = knapsack(values, weights, capacity);

    cout << max_value << endl;
}

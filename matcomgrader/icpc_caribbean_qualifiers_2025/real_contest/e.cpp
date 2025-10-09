#include <iostream>
#include <set>

using namespace std;

void binary_search(int low, int high, int remaining_steps, set<int>& found) {
    if (low > high) {
        return;
    }

    int mid = (low + high) / 2;

    if (remaining_steps == 1) {
        found.insert(mid);
    }
    
    binary_search(low, mid - 1, remaining_steps - 1, found);
    binary_search(mid + 1, high, remaining_steps - 1, found);
}

int main() {
    int test_cases;
    cin >> test_cases;

    for (int _t = 0; _t < test_cases; ++_t) {
        int list_size, steps;
        cin >> list_size >> steps;

        set<int> found;
        binary_search(0, list_size - 1, steps, found);

        for (auto& idx : found) {
            cout << idx << " ";
        }
        cout << endl;
    }
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <string>

using namespace std;

// Run with `g++ l.cpp -o l && l.exe`.
// or with `g++ l.cpp -o l && (l.exe < l.txt)`.

int main() {
    int test_cases;
    cin >> test_cases;

    for (int _t = 0; _t < test_cases; ++_t) {
        int s1, s2;
        cin >> s1;
        cin >> s2;

        array<int, 3> weights = {2, 2, 2};
        array<int, 3> nums = {4, 2, 1};

        array<int, 2> scores = {s1, s2};

        for (auto& s : scores) {
            for (int i = 0; i < weights.size(); ++i) {
                if (s >= nums[i]) {
                    s -= nums[i];
                    weights[i] -= 1;
                }
            }
        }

        int last_score = 0;
        for (int i = 0; i < weights.size(); ++i) {
            last_score += weights[i] * nums[i];
        }

        cout << last_score << endl;
    }
}
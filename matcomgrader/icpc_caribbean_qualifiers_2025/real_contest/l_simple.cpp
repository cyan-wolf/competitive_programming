#include <iostream>

using namespace std;

int main() {
    int TOTAL_SCORE = 14;

    int test_cases;
    cin >> test_cases;

    for (int _t = 0; _t < test_cases; ++_t) {
        int s1, s2;
        cin >> s1 >> s2;

        int s_remaining = TOTAL_SCORE - s1 - s2;
        cout << s_remaining << endl;
    }
}
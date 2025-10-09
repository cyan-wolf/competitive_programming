#include <iostream>
#include <string>

using namespace std;

// Accepted

int main() {
    int test_cases;
    cin >> test_cases;

    for (int _t = 0; _t < test_cases; ++_t) {
        string s1, s2;
        cin >> s1 >> s2;

        int wrong = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                wrong++;
            }
        }
        cout << wrong << endl;
    }
}
#include <iostream>

using namespace std;

// Rejected: TIME LIMIT EXCEEDED

int main() {
    int test_cases;
    cin >> test_cases;

    for (int _t = 0; _t < test_cases; ++_t) {
        // Use `long long` since dimensions can be > 10^8.
        long long rows, cols;
        cin >> rows >> cols;

        char dir = 'R';

        while (rows > 0 && cols > 0) {
            if (dir == 'R') {
                rows--;
                dir = 'D';
            }
            else if (dir == 'D') {
                cols--;
                dir = 'L';
            } 
            else if (dir == 'L') {
                rows--;
                dir = 'U';
            } 
            else { // dir == 'U'
                cols--;
                dir = 'R';
            }
        }

        // Go back one turn.
        if (dir == 'R') {
            dir = 'U';
        }
        else if (dir == 'D') {
            dir = 'R';
        } 
        else if (dir == 'L') {
            dir = 'D';
        } 
        else { // dir == 'U'
            dir = 'L';
        }

        cout << dir << endl;
    }
}
#include <iostream>

using namespace std;

// Accepted: After contest.

int main() {
    int test_cases;
    cin >> test_cases;

    for (int _t = 0; _t < test_cases; ++_t) {
        double dist, v1, v2, v_fly;
        cin >> dist >> v1 >> v2 >> v_fly;

        double col_time = dist / (v1 + v2);
        double fly_dist = col_time * v_fly;

        printf("%.2f\n", fly_dist);
    }
}
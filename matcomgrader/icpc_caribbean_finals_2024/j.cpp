/*
    Problem J - Jigsaw of Shadows
    https://scorelatam.naquadah.com.br/latam-2024/contest.pdf
    https://scorelatam.naquadah.com.br/latam-2024/Score.html
    https://codeforces.com/gym/105505/problem/J
*/

// Time Limit Exceeded (how?)

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int angle_deg, n;
    cin >> angle_deg >> n;

    // acos(-1) = PI
    // <cmath> trig functions use radians
    double angle = angle_deg / 180.0 * acos(-1);

    vector<pair<double, double>> shads(n);

    for (int i = 0; i < n; ++i) {
        double pos, height;
        cin >> pos >> height;

        double s = height / tan(angle);

        shads[i] = {pos, pos + s};
    }

    // Sorts the shadows by their starting position.
    sort(shads.begin(), shads.end());

    double total_length = 0;

    double curr_min = shads[0].first;
    double curr_max = shads[0].second;

    // Greedy algorithm for merging the shadows.
    // The max/min for the first shadow was already computed, so we start 
    // at the second element.
    for (int i = 1; i < n; ++i) {
        auto new_shad = shads[i];

        // If the current max is less than the start of the new shadow, 
        // then there is a gap and we should save our length so far and 
        // reset the max/min.
        if (curr_max < new_shad.first) {
            total_length += curr_max - curr_min;

            curr_min = new_shad.first;
            curr_max = new_shad.second;
        }
        // The next shadow increases the size of the current 
        // patch, so we update the max.
        else if (curr_max < new_shad.second) {
            curr_max = new_shad.second;
        }
    }
    // The previous loop doesn't save the last patch, so we add it here.
    total_length += curr_max - curr_min;

    cout << fixed << setprecision(5) << total_length << endl;
}
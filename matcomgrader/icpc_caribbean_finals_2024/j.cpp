/*
    Problem J - Jigsaw of Shadows
    https://scorelatam.naquadah.com.br/latam-2024/contest.pdf
    https://scorelatam.naquadah.com.br/latam-2024/Score.html
    https://codeforces.com/gym/105505/problem/J
*/

// Accepted

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <tuple>
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

    vector<tuple<int, double>> shads(n);

    for (int i = 0; i < n; ++i) {
        int pos, height;
        cin >> pos >> height;

        double s = (double)height / tan(angle);

        shads[i] = {pos, pos + s};
    }

    // Sorts the shadows by their starting position.
    sort(shads.begin(), shads.end());

    double epsilon = 1e-4;

    double total_length = 0;

    double curr_min = get<0>(shads[0]);
    double curr_max = get<1>(shads[0]);

    // Greedy algorithm for merging the shadows.
    // The max/min for the first shadow was already computed, so we start 
    // at the second element.
    for (int i = 1; i < n; ++i) {
        auto new_shad_min = get<0>(shads[i]);
        auto new_shad_max = get<1>(shads[i]);

        // If the current max is less than the start of the new shadow, 
        // then there is a gap and we should save our length so far and 
        // reset the max/min.
        if (curr_max + epsilon < new_shad_min) {
            total_length += curr_max - curr_min;

            curr_min = new_shad_min;
            curr_max = new_shad_max;
        }
        // The next shadow increases the size of the current 
        // patch, so we update the max.
        else if (curr_max + epsilon < new_shad_max) {
            curr_max = new_shad_max;
        }
    }
    // The previous loop doesn't save the last patch, so we add it here.
    total_length += curr_max - curr_min;

    cout << fixed << setprecision(5) << total_length << endl;
}
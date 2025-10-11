/*
    Problem J - Jigsaw of Shadows
    https://scorelatam.naquadah.com.br/latam-2024/contest.pdf
    https://scorelatam.naquadah.com.br/latam-2024/Score.html
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int angle_deg, n;
    cin >> angle_deg >> n;

    // acos(-1) = PI
    // <cmath> trig functions use radians
    double angle = angle_deg / 180.0 * acos(-1);

    for (int _i = 0; _i < n; ++_i) {
        double pos, height;
        cin >> pos >> height;

        double s = height / tan(angle);

        // TODO
        // ...

        cout << "Bounds: " << (pos + s) << " ... " << pos << endl;
    }
}
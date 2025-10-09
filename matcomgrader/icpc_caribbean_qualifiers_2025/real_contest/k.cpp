#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <tuple>
#include <iterator>

using namespace std;

// Accepted: After the contest.

int main() {
    int test_cases;
    cin >> test_cases;

    for (int _t  = 0; _t < test_cases; ++_t) {
        int operation_amt;
        cin >> operation_amt;

        // Used for generating new IDs.
        int seen_entities = 0;

        // entity ID -> coordinates
        unordered_map<int, tuple<int, int, int>> entities;

        // individual coordinates -> counts
        map<int, int> x_vals;
        map<int, int> y_vals;
        map<int, int> z_vals;

        for (int _o = 0; _o < operation_amt; ++_o) {
            string op;
            cin >> op;

            if (op == "ADD") {
                int x, y, z;
                cin >> x >> y >> z;

                // cout << "adding..." << endl;

                seen_entities++;
                entities[seen_entities] = {x, y, z};
                
                // Merely accessing the key autofills it with the default value for non-existent keys, 
                // so no checks  are needed.
                x_vals[x]++;
                y_vals[y]++;
                z_vals[z]++;
            }
            else {
                int id;
                cin >> id;

                // cout << "removing... " << id << endl;

                auto entity = entities.at(id);

                x_vals[get<0>(entity)]--;
                y_vals[get<1>(entity)]--;
                z_vals[get<2>(entity)]--;

                // Clean up the ordered map.
                if (x_vals[get<0>(entity)] == 0) {
                    x_vals.erase(get<0>(entity));
                }
                if (y_vals[get<1>(entity)] == 0) {
                    y_vals.erase(get<1>(entity));
                }
                if (z_vals[get<2>(entity)] == 0) {
                    z_vals.erase(get<2>(entity));
                }

                entities.erase(id);
            }

            // Max/mins in each axis (uses `long long` just in case).
            long long x_max, y_max, z_max, x_min, y_min, z_min;

            // Collect the values for the max/mins of each axis.
            if (x_vals.size() == 0) {
                x_max = 0;
                x_min = 0;
            }
            else {
                x_max = prev(x_vals.end())->first;
                x_min = x_vals.begin()->first;
            }
            if (y_vals.size() == 0) {
                y_max = 0;
                y_min = 0;
            }
            else {
                y_max = prev(y_vals.end())->first;
                y_min = y_vals.begin()->first;
            }
            if (z_vals.size() == 0) {
                z_max = 0;
                z_min = 0;
            }
            else {
                z_max = prev(z_vals.end())->first;
                z_min = z_vals.begin()->first;
            }

            // Compute the surface area after each operation.
            // Use `long long` to avoid integer overflow in any calculation.
            long long dx = x_max - x_min;
            long long dy = y_max - y_min;
            long long dz = z_max - z_min;

            long long area = (dx * dy + dx * dz + dy * dz) * 2;
            cout << area << endl;
        }
    }
}
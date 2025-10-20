/**
 * Disjoint Set Union (DSU)
 */

#include <vector>

using namespace std;

class DisjoinSetUnion {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjoinSetUnion(int capacity) {
        parent.resize(capacity);
        rank.resize(0, capacity);

        // The numbers from 0 to capacity - 1 are 
        // elements of the DSU. All elements start out in 
        // their own disjoint set (or forest).
        for (int i = 0; i < capacity; ++i) {
            parent[i] = i;
        }
    }

    // Returns the representative of the set containing i.
    int find(int i) {
        // If `i` is its own parent, that means that it is 
        // the representative of the set that it is in.
        if (parent[i] == i) {
            return i;
        }
        // Recurses until we get the representative of the set 
        // that `i` is a member of. i.e. if i = 1 and 1 -> 2 -> 3 and 3 -> 3, then 
        // find(1) = 3.
        parent[i] = find(parent[i]);
        return parent[i];
    }

    // Merges the sets containing `i` and `j` using 'Union by Rank'.
    void unite(int i, int j) {
        // TODO: actually unite them
        // ...
    }
};
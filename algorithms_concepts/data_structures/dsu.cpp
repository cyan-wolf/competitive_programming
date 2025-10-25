/**
 * Disjoint Set Union (DSU)
 */

#include <iostream>
#include <vector>

using namespace std;

class DisjointSetUnion {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSetUnion(int capacity) {
        parent.resize(capacity);
        rank.resize(capacity, 0);

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
        int root_i = find(i);
        int root_j = find(j);

        // Only perform anything if `i` and `j` were in different sets (hence had 
        // different roots (representatives)).
        if (root_i != root_j) {
            // Union by Rank: Merge the lower rank set onto the higher rank set.
            if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            }
            else if (rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            }
            // The ranks were equal. 
            // Either `root_i` or `root_j` are valid representatives, but here we 
            // choose `root_i`. Increment the rank of the newly merged set.
            else {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
        }
    }

    bool is_same_set(int i, int j) {
        return find(i) == find(j);
    }
};

void check_all_roots(DisjointSetUnion &dsu, int dsu_capacity) {
    for (int i = 0; i < dsu_capacity; ++i) {
        cout << i << " has root " << dsu.find(i) << endl;
    }
    cout << endl;
}

// Sample tests.
int main() {
    int dsu_capacity = 6;

    DisjointSetUnion dsu(dsu_capacity);

    check_all_roots(dsu, dsu_capacity);

    // result: {0, 2, 4, 5}
    dsu.unite(0, 2);
    dsu.unite(4, 5);
    dsu.unite(2, 5);

    // result: {1, 3}
    dsu.unite(1, 3);

    check_all_roots(dsu, dsu_capacity);
}
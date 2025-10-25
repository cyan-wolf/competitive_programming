/**
 * Disjoint Set Union (DSU)
 */

#include <iostream>
#include <unordered_map>
#include <stdexcept>

#include <vector>

using namespace std;

template<class T>
class DisjoinSetUnion {
private:
    unordered_map<T, T> parent;
    unordered_map<T, int> rank;

public:
    void add(T element) {
        if (parent.count(element) == 0) {
            parent[element] = element;
            rank[element] = 0;
        }
    }

    // Returns the representative of the set containing i.
    T find(T i) {
        if (parent.count(i) == 0) {
            throw out_of_range("could not find given element");
        }

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
    void unite(T i, T j) {
        T root_i = find(i);
        T root_j = find(j);

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

    // Helper function.
    bool is_same_set(T i, T j) {
        return find(i) == find(j);
    }
};

template<class T>
void check_all_roots(DisjoinSetUnion<T> &dsu, const vector<T> &elems) {
    for (auto& elem : elems) {
        cout << elem << " has root " << dsu.find(elem) << endl;
    }
    cout << endl;
}

// Sample tests.
int main() {
    vector<char> elems = {'a', 'b', 'c', 'd', 'e', 'f'};
    DisjoinSetUnion<char> dsu;

    for (char elem : elems) {
        dsu.add(elem);
    }

    check_all_roots(dsu, elems);

    // result: {'a', 'c', 'e', 'f'}
    dsu.unite('a', 'c');
    dsu.unite('e', 'f');
    dsu.unite('c', 'f');

    // result: {'b', 'd'}
    dsu.unite('b', 'd');

    check_all_roots(dsu, elems);

    cout << dsu.is_same_set('d', 'b') << endl; // 1 (true)
    cout << dsu.is_same_set('d', 'a') << endl; // 0 (false)
    cout << dsu.is_same_set('a', 'b') << endl; // 0 (false)
    cout << dsu.is_same_set('a', 'f') << endl; // 1 (true)
}
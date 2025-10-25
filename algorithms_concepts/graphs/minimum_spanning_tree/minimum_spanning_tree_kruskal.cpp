/**
 * Minimum Spanning Tree - Kruskal
 * 
 * Finds the most economical way to connect a set of points (vertices) in a graph, 
 * ensuring that all points are connected with the lowest possible total connection 
 * cost (edge weights) and without forming any cycles.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ========== DSU ==========

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

// ========== Edges ==========

struct Edge {
    int u;
    int v;
    int weight;
};

// Custom comparator for sorting edges by weight.
bool compare_by_weight(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// ========== Kruskal's Algorithm ==========

// O(E log(E)), where E is the size of the edge list.
vector<Edge> mst_kruskal(vector<Edge>& edges, int num_vertices) {
    // Sort the edge list by weight.
    sort(edges.begin(), edges.end(), compare_by_weight);

    // Initialize a DSU pre-filled with the integers 
    // from 0 to `num_vertices - 1`. 
    //
    // Each element is in a disjoint singleton set (i.e. 
    // DSU({0}, {1}, {2}, {3}, ..., {num_vertices - 1})).
    DisjointSetUnion dsu(num_vertices);

    vector<Edge> mst;

    for (const auto& edge : edges) {
        // A MST has `num_vertices - 1` edges. Once we have found that many we 
        // can early-exit.
        if (mst.size() == num_vertices - 1) {
            break;
        }

        // Only add the edge to the MST if the vertices were not already connected (i.e. in the same set
        // in the DSU).
        if (!dsu.is_same_set(edge.u, edge.v)) {
            mst.push_back(edge);

            // Merge the sets that vertices U and V belong to (to signify that they are now connected).
            dsu.unite(edge.u, edge.v);
        }
    }

    return mst;
}

// ========== Testing ==========

int main() {
    int num_vertices = 5; // 0, 1, 2, 3, 4

    vector<Edge> edges = {
        {0, 1, 4}, // edge connecting 0 and 1 with weight 4
        {0, 2, 1}, 
        {1, 4, 4}, 
        {1, 3, 5}, 
        {2, 3, 9}, 
        {2, 4, 6}, 
        {3, 4, 2},
    };

    auto mst = mst_kruskal(edges, num_vertices);

    int total_weight = 0;
    for (const auto& edge : mst) {
        cout << edge.u << " <-> " << edge.v << " (" << edge.weight << ")" << endl;

        total_weight += edge.weight;
    }

    cout << "Total weight: " << total_weight << endl;
}
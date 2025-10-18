/**
 * Word Search
 * https://leetcode.com/problems/word-search/description/
 * 
 * Given an m x n grid of characters board and a string word, return true if word exists in the grid. 
 * The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are 
 * horizontally or vertically neighboring. The same letter cell may not be used more than once.
 */

#include <iostream>
// This is a BST, meaning O(log n) inserts and queries.
// This is being used temporarily since pair is annoying to use in unordered_set.
#include <set>
#include <vector>
#include <tuple>

using namespace std;

// Wrong Answer

bool in_bounds(int rows, int cols, pair<int, int> pos) {
    return pos.first >= 0 && pos.second >= 0 && pos.first < rows && pos.second < cols;
}

bool find_word(const vector<vector<char>>& board, const string& word, pair<int, int> start_pos) {
    set<pair<int, int>> visited;
    vector<tuple<pair<int, int>, int>> stk = {make_tuple(start_pos, 0)};

    while (stk.size() > 0) {
        auto curr = stk.back();
        stk.pop_back();

        auto curr_pos = get<0>(curr);
        int word_idx = get<1>(curr);

        visited.insert(curr_pos);

        // cout << "Iteration STK SIZE: " << stk.size() << endl;

        if (word_idx >= word.size()) {
            return false;
        }

        if (word.at(word_idx) != board[curr_pos.first][curr_pos.second]) {
            continue;
        }

        if (word_idx == word.size() - 1) {
            return true;
        }

        // cout << "(" << curr_pos.first << ", " << curr_pos.second << ")" << endl;

        vector<pair<int, int>> nbrs = {
            {curr_pos.first + 1, curr_pos.second},
            {curr_pos.first - 1, curr_pos.second},
            {curr_pos.first, curr_pos.second + 1},
            {curr_pos.first, curr_pos.second - 1},
        };

        for (auto nbr : nbrs) {
            if (in_bounds(board.size(), board[0].size(), nbr) && visited.count(nbr) == 0) {
                stk.push_back(make_tuple(nbr, word_idx + 1));
            }
        }
    }
    return false;
}

bool solution(const vector<vector<char>>& board, const string& word) {
    char start = word.at(0);

    for (int r = 0; r < board.size(); ++r) {
        for (int c = 0; c < board.at(0).size(); ++c) {
            if (start == board[r][c]) {
                if (find_word(board, word, {r, c})) {
                    return true;
                }
            }
        }
    }
    return false;
}


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        return solution(board, word);
    }
};


int main() {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << solution(board, "ABCCED") << endl; // 1
    cout << solution(board, "SEE") << endl; // 1
    cout << solution(board, "ABCB") << endl; // 0

    vector<vector<char>> board2 = {{'a'}};
    cout << solution(board2, "a") << endl; // 1

    vector<vector<char>> board3 = {{'a','b'},{'c','d'}}; // 1 - (wrongly says 0)
    cout << solution(board3, "abcd") << endl;
}
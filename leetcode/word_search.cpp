/**
 * Word Search
 * https://leetcode.com/problems/word-search/description/
 * 
 * Given an m x n grid of characters board and a string word, return true if word exists in the grid. 
 * The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are 
 * horizontally or vertically neighboring. The same letter cell may not be used more than once.
 */

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// Accepted

bool in_bounds(int rows, int cols, pair<int, int> pos) {
    return pos.first >= 0 && pos.second >= 0 && pos.first < rows && pos.second < cols;
}

bool find_word_rec(
    vector<vector<char>>& board, 
    const string& word, 
    pair<int, int> curr_pos, 
    int word_idx
) {
    char prev_board_value = board[curr_pos.first][curr_pos.second];

    if (word.at(word_idx) != board.at(curr_pos.first).at(curr_pos.second)) {
        board[curr_pos.first][curr_pos.second] = prev_board_value;
        return false;
    }
    else if (word_idx == word.size() - 1) {
        board[curr_pos.first][curr_pos.second] = prev_board_value;
        return true;
    }
    else {
        board[curr_pos.first][curr_pos.second] = '#';

        vector<pair<int, int>> nbrs = {
            {curr_pos.first + 1, curr_pos.second},
            {curr_pos.first - 1, curr_pos.second},
            {curr_pos.first, curr_pos.second + 1},
            {curr_pos.first, curr_pos.second - 1},
        };

        for (auto nbr : nbrs) {
            if (in_bounds(board.size(), board[0].size(), nbr) && board[nbr.first][nbr.second] != '#') {
                bool found = find_word_rec(board, word, nbr, word_idx + 1);
                if (found) {
                    board[curr_pos.first][curr_pos.second] = prev_board_value;
                    return true;
                }
            }
        }
        board[curr_pos.first][curr_pos.second] = prev_board_value;
        return false;
    }
}

bool find_word(vector<vector<char>>& board, const string& word, pair<int, int> start_pos) {
    return find_word_rec(board, word, start_pos, 0);
}

bool solution(vector<vector<char>>& board, const string& word) {
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

    vector<vector<char>> board3 = {{'a','b'},{'c','d'}}; // 1
    cout << solution(board3, "acdb") << endl;
}
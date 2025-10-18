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
    // If the letter at `word_idx` is not the same as the board at `curr_pos` then we 
    // stop exploring this branch.
    if (word.at(word_idx) != board.at(curr_pos.first).at(curr_pos.second)) {
        return false;
    }
    // If we are here, it means that the letter is correct. Therefore, if we are at the end of the 
    // word, then we are done and can return `true`.
    else if (word_idx == word.size() - 1) {
        return true;
    }
    else {
        // Save the board character at `curr_pos`.
        char prev_board_value = board[curr_pos.first][curr_pos.second];
        // Mark it with a special character '#' to signal that this board position 
        // has been visited in this branch.
        board[curr_pos.first][curr_pos.second] = '#';

        // The 4 adjacent neighbor positions. Not all of these will be valid,
        // but the check below handles invalid neighbors.
        vector<pair<int, int>> nbrs = {
            {curr_pos.first + 1, curr_pos.second},
            {curr_pos.first - 1, curr_pos.second},
            {curr_pos.first, curr_pos.second + 1},
            {curr_pos.first, curr_pos.second - 1},
        };

        for (auto nbr : nbrs) {
            // If the neighbor is in bounds and not marked as visited, then continue the search.
            if (in_bounds(board.size(), board[0].size(), nbr) && board[nbr.first][nbr.second] != '#') {
                // If any of the branches return `true`, then this branch returns `true`.
                bool found = find_word_rec(board, word, nbr, word_idx + 1);
                if (found) {
                    // Undo the "visited" mark.
                    board[curr_pos.first][curr_pos.second] = prev_board_value;
                    return true;
                }
            }
        }
        // None of the branches stemming from the neighbors had the word, so we 
        // undo the "visited" mark and return `false`. 
        board[curr_pos.first][curr_pos.second] = prev_board_value;
        return false;
    }
}

// This wrapper function is unnecessary.
bool find_word(vector<vector<char>>& board, const string& word, pair<int, int> start_pos) {
    return find_word_rec(board, word, start_pos, 0);
}

bool solution(vector<vector<char>>& board, const string& word) {
    char start = word.at(0);

    // Look for the word's starting character by doing a full search of the board.
    // We early exit if the board is ever found, if not, we search the entire board 
    // before giving up and returning `false`.
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

// Class needed for LeetCode submission.
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        return solution(board, word);
    }
};

// Sample tests.
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
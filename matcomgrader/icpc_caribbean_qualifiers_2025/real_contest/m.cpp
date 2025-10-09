#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols, queries;
    cin >> rows >> cols >> queries;

    vector<vector<int>> matrix(rows);

    for (int r = 0; r < rows; ++r) {
        vector<int> row(cols);
        for (int c = 0; c < cols; ++c) {
            cin >> row[c];
        }
        matrix[r] = row;
    }

    for (int _q = 0; _q < queries; ++_q) {
        int operation;
        cin >> operation;

        if (operation == 1) {
            int r;
            cin >> r;
            r -= 1;

            for (int i = 0; i < cols / 2; ++i) {
                int temp = matrix[r][i];
                matrix[r][i] = matrix[r][cols - i - 1];
                matrix[r][cols - i - 1] = temp;
            }
        }
        else if (operation == 2) {
            int c;
            cin >> c;
            c -= 1;

            for (int i = 0; i < rows / 2; ++i) {
                int temp = matrix[i][c];
                matrix[i][c] = matrix[rows - i - 1][c];
                matrix[rows - i - 1][c] = temp;
            }
        }
        else {
            int r, c;
            cin >> r >> c;
            r -= 1;
            c -= 1;

            cout << matrix[r][c] << endl;
        }
    }
}
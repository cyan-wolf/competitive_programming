/*
    Problem F - Finding Privacy
    https://scorelatam.naquadah.com.br/latam-2024/contest.pdf
    https://scorelatam.naquadah.com.br/latam-2024/Score.html
    https://codeforces.com/gym/105505/problem/F
*/

// Time Limit Exceeded

#include <iostream>
#include <string>
#include <unordered_set>
#include <cmath>

using namespace std;

void det_seq(int rem_space, int rem_people, bool add_per, string acc, unordered_set<string>& solutions) {
    if (solutions.size() > 0) {
        return;
    }
    else if (rem_space == 0 && rem_people == 0) {
        if (acc.size() >= 2) {
            string end = acc.substr(acc.size() - 2, 2);
            if (end == "--") {
                // Discard solutions that end with "--".
                return;
            }
        }
        solutions.insert(acc);
        return;
    }
    else if (rem_space == 0) {
        return;
    }
    else if (rem_people == 0) {
        return;
    }
    else if (add_per) {
        acc.push_back('X');
        det_seq(max(0, rem_space - 1), max(0, rem_people - 1), false, acc, solutions);
    }
    else {
        acc.push_back('-');
        det_seq(max(0, rem_space - 1), rem_people, true, acc, solutions);

        string acc2 = acc;
        acc2.push_back('-');
        det_seq(max(0, rem_space - 2), rem_people, true, acc2, solutions);
    }
}

int main() {
    int people_amt, toilet_amt;
    cin >> people_amt >> toilet_amt;

    unordered_set<string> solutions;
    det_seq(toilet_amt - 1, people_amt - 1, false, "X", solutions);
    det_seq(toilet_amt - 1, people_amt, true, "-", solutions);

    if (solutions.size() == 0) {
        cout << "*" << endl;
    }
    else {
        string arbitrary_solution = *solutions.begin();
        cout << arbitrary_solution << endl;
    }
}
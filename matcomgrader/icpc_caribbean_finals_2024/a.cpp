/*
    Problem A - Append and Panic!
    https://scorelatam.naquadah.com.br/latam-2024/contest.pdf
    https://scorelatam.naquadah.com.br/latam-2024/Score.html
    https://codeforces.com/gym/105505/problem/A
*/

// Accepted

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_set<char> uniq;
    for (char c : s) {
        uniq.insert(c);
    }
    cout << s.size() - uniq.size() << endl;
}
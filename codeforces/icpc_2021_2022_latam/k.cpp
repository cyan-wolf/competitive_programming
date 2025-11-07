/**
 * K. KIARA is a Recursive Acronym
 * https://codeforces.com/gym/103640/problem/K
 */

// Accepted

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<char> first_letters;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;

        first_letters.insert(word[0]);
        words[i] = word; 
    }

    bool one_is_all_in = false;

    for (const string& word : words) {
        bool all_in = true;

        for (char c : word) {
            if (first_letters.count(c) == 0) {
                all_in = false;
                break;
            }
        }

        if (all_in) {
            one_is_all_in = true;
            break;
        }
    }

    cout << ((one_is_all_in) ?  'Y' : 'N') << endl;
}
/**
 * Remove nth Node from 
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 */

// Accepted

#include <iostream>
#include <vector> 

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* solution(ListNode* head, int n) {
    vector<ListNode*> seen;

    auto curr = head;

    while (curr != nullptr) {
        seen.push_back(curr);
        curr = curr->next;
    }
    int prev = seen.size() - n - 1;
    int post = seen.size() - n + 1;

    // This handles the edge case where the node associated with `post` does not exist, 
    // which happens when we are trying to delete the final node (doesn't have a next node).
    ListNode* node_post = nullptr;
    if (post < seen.size()) {
        node_post = seen[post];
    }

    // `n == seen.size()` would mean that we are trying to delete the head itself. This 
    // is another edge case that we handle in the else below. 
    // 
    // If we aren't trying to delete the head, we just do the normal logic for "skipping past" 
    // the deleted node by doing node_prev.next = node_post. If node_post technically doesn't 
    // exist, then the logic above ensures that nove_post is null, which is correct.
    if (n != seen.size()) {
        seen.at(prev)->next = node_post;
    }
    // If we are trying to delete the head... just return head->next.
    else {
        return head->next;
    }
    return head;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return solution(head, n);
    }
};

int main() {
    // head = [1,2,3,4,5], n = 2
    auto sol = solution(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))), 2);

    // // head = [1, 2], n = 1
    // auto sol = solution(new ListNode(1, new ListNode(2)), 1);

    // // head = [1], n = 1
    // auto sol = solution(new ListNode(1), 1);

    auto curr = sol;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        vector<int> oList;

        while (curr != nullptr) {
            oList.push_back(curr->val);
            curr = curr->next;
        }

        curr = head;
        int l = 0, r = oList.size()-1;
        while (l < r) {
            curr->val = oList[l];
            curr = curr->next;
            curr->val = oList[r];
            curr = curr->next;
            ++l;--r;
        }

        if (curr != nullptr) curr->val = oList[l];
    }
};

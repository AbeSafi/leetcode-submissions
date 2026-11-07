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
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* currNode = head->next;
        ListNode* lastNode = head;
        head->next = nullptr;

        while (currNode) {
            ListNode* temp = currNode->next;
            currNode->next = lastNode;
            lastNode = currNode;
            currNode = temp;
        }

        return lastNode;
    }
};

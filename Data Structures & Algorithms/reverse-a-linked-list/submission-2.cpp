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
        if (head == nullptr) return head;

        ListNode* prev = head;
        ListNode* next = head->next;
        prev->next = nullptr;
        
        while (next != nullptr) {
            ListNode* reverse = next; // Set the node to have its next modified
            next = reverse->next; // Save that node's next node
            reverse->next = prev; // Set that node's next node to the prev node
            prev = reverse; // Set the prev node to the modified node
        }

        return prev;
    }
};

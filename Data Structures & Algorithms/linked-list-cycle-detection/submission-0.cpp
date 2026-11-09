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
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, int> nodes;
        int index = -1;
        int i = 0;

        while (index == -1) {
            if (head == nullptr) break;
            
            auto nodeLocation = nodes.find(head);
            
            if (nodeLocation != nodes.end()) {
              index = nodeLocation->second;
              continue;
            }
            
            nodes[head] = i++;
            head = head->next;
        }

        return index != -1;
    }
};

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
    ListNode* rotateRight(ListNode* head, int k) {
        // Base case: empty list, single node, or no rotation needed
        if (!head || !head->next || k == 0) {
            return head;
        }
        
        // 1. Compute the length of the linked list and find the tail
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        
        // 2. Optimize k to prevent unnecessary full rotations
        k = k % length;
        if (k == 0) {
            return head; // No rotation needed
        }
        
        // 3. Connect tail to head to make it circular
        tail->next = head;
        
        // 4. Find the new tail node (at position length - k)
        // Moving length - k steps from the old tail brings us to the new tail
        int stepsToNewTail = length - k;
        while (stepsToNewTail--) {
            tail = tail->next;
        }
        
        // 5. Set the new head and break the circular connection
        head = tail->next;
        tail->next = nullptr;
        
        return head;
    }
};

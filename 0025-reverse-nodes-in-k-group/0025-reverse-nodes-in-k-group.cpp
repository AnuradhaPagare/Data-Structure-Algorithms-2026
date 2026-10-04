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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        // Dummy node helps manage the new head seamlessly
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* groupPrev = dummy;
        
        while (true) {
            // Check if there are at least k nodes left to reverse
            ListNode* kth = getKthNode(groupPrev, k);
            if (!kth) break; // Less than k nodes left, leave them as they are
            
            ListNode* groupNext = kth->next;
            
            // Reverse the current group of k nodes
            ListNode* prev = kth->next; // Point the first node's next to the next group's start
            ListNode* curr = groupPrev->next;
            
            while (curr != groupNext) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            
            // Connect the previous group to the new head of the reversed group
            ListNode* tmp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = tmp; // The original first node becomes the last node of the group
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; // Free dummy node memory
        return newHead;
    }

private:
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};

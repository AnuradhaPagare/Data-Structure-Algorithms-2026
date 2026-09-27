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
    // Custom comparator to order the min-heap by node values
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap to store the current nodes of each list
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        
        // Push the head of each non-empty list into the min-heap
        for (auto list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }
        
        // Dummy node to simplify handling the head of the merged list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        // Process nodes until the heap is empty
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            
            // Append the smallest node to the result list
            tail->next = smallest;
            tail = tail->next;
            
            // If the popped node has a next node, push it into the heap
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }
        
        ListNode* result = dummy->next;
        delete dummy; // Clean up memory
        return result;
    }
};

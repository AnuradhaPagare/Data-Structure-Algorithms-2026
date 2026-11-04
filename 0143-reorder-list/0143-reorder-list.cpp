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

        if (head == nullptr) return;

        vector<ListNode*> inky;

        ListNode* curr = head;

        while (curr != nullptr) {
            inky.push_back(curr);
            curr = curr->next;
        }

        int left = 0;
        int right = inky.size() - 1;

        while (left < right) {

            inky[left]->next = inky[right];
            left++;

            if (left == right) break;

            inky[right]->next = inky[left];
            right--;
        }

        inky[left]->next = nullptr;
    }
};
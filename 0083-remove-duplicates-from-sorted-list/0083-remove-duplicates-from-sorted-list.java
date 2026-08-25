/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        // Handle empty list or single node list
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode current = head;
        
        // Traverse through the list
        while (current != null && current.next != null) {
            // If current value equals the next value, skip the next node
            if (current.val == current.next.val) {
                current.next = current.next.next;
            } else {
                // Otherwise, move to the next unique node
                current = current.next;
            }
        }
        
        return head;
    }
}

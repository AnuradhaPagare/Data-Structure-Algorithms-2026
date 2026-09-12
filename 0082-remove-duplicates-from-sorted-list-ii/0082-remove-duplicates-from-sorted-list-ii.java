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
        // Create a dummy node that points to the head
        ListNode dummy = new ListNode(0, head);
        // 'prev' will always point to the last node in the distinct sublist
        ListNode prev = dummy;
        
        while (head != null) {
            // Check if it's the start of a duplicate sequence
            if (head.next != null && head.val == head.next.val) {
                // Move 'head' forward until we reach the last node of the duplicates
                while (head.next != null && head.val == head.next.val) {
                    head = head.next;
                }
                // Skip all the duplicates by linking 'prev.next' past them
                prev.next = head.next;
            } else {
                // If no duplicates are found, move 'prev' forward
                prev = prev.next;
            }
            // Move 'head' forward for the next iteration
            head = head.next;
        }
        
        return dummy.next;
    }
}

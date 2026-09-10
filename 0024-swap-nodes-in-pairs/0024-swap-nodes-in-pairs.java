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
    public ListNode swapPairs(ListNode head) {
        // Base case: If the list is empty or has only one node, no swaps are needed
        if (head == null || head.next == null) {
            return head;
        }
        
        // Initialize dummy node to ease handling of the head pointer
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        
        // 'prev' keeps track of the node just before the pair we are swapping
        ListNode prev = dummy;
        
        // Loop runs as long as there is a pair of nodes available to swap
        while (prev.next != null && prev.next.next != null) {
            ListNode first = prev.next;
            ListNode second = prev.next.next;
            
            // Re-wiring the pointers to swap 'first' and 'second'
            first.next = second.next;
            second.next = first;
            prev.next = second;
            
            // Move 'prev' forward by two nodes for the next iteration
            prev = first;
        }
        
        return dummy.next;
    }
}

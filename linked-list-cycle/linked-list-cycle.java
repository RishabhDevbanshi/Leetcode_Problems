/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null) return false;
        ListNode tor = head , hare = head;
        while(hare != null && hare.next != null)
        {
            hare = hare.next.next;
            tor = tor.next;
            
            if(hare == tor) return true;
        }
        
        return false;
    }
}
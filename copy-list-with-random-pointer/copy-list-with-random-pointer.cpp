/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        
        //step 1 : insert the copy nodes in between the original nodes
        //ie, if 1->2->3->X then it becomes 1->1'->2->2'->3->3'->X
        
        Node* tmp = head;
        while(tmp)
        {
            Node* copy = new Node(tmp->val);
            Node* next = tmp->next;
            tmp->next = copy;
            copy->next = next;
            tmp = next;
        }
        
        //step 2 : place then random pointers of the copied nodes 
        //to their correct pos
        
        tmp = head;
        while(tmp)
        {
            if(tmp->random)
            {
                tmp->next->random = tmp->random->next;
            }
            
            tmp = tmp->next->next;
        }
        
        //step 3 : spearating the original and copied lists
        
        tmp = head;
        Node* copy = new Node(0);
        Node* newHead = copy;
        while(tmp)
        {
            Node* front = tmp->next->next;
            copy->next = tmp->next;
            tmp->next = front;
            tmp = tmp->next;
            copy = copy->next;
        }
        
        return newHead->next;
    }
};





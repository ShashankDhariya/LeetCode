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
        if(!head)   return NULL;

        Node* ptr = head;
        while(ptr){
            Node* p = ptr->next;
            ptr->next = new Node(ptr->val);
            ptr->next->next = p;
            ptr = p;
        }

        ptr = head;
        while(ptr){
            if(ptr->random) ptr->next->random = ptr->random->next;
            ptr = ptr->next->next;
        }

        Node* ans = new Node(0);
        Node* p = ans;
        while(head){
            p->next = head->next;
            
            p = p->next;
            head->next = head->next->next;
            head = head->next;
        }

        return ans->next;
    }
};

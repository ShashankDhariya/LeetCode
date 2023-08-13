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
    
    ListNode* reverse(ListNode* head){
        ListNode* ptr = head;
        ListNode* nxt = NULL;
        ListNode* next = NULL;
        while(ptr){
            next = ptr->next;
            ptr->next = nxt;
            nxt = ptr;
            ptr = next;
        }
        return nxt;
    }
    
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        
        ListNode* ptr = head;
        int carry = 0;
        while(ptr){
            int value = 2*ptr->val;
            ptr->val = carry + (value % 10); 
            carry = value / 10;
            ptr = ptr->next;
        }
        head = reverse(head);
        
        if(carry){
            ListNode* node = new ListNode(carry);
            node->next = head;
            head = node;
        }
        
        return head;
    }
};

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        
        while(ptr1 && ptr2){
            ListNode* ptr = new ListNode(gcd(ptr1->val, ptr2->val));
            ptr1->next = ptr;
            ptr->next = ptr2;
            
            ptr1 = ptr2;
            if(ptr1) ptr2 = ptr1->next;
        }
        
        return head;
    }
};

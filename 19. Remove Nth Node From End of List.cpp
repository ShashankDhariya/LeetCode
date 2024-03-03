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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int idx1 = 0;
        int idx2 = 0;

        ListNode* prev = head;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        while(ptr2){
            if(idx2 - idx1 == n){
                idx1++;
                prev = ptr1;
                ptr1 = ptr1->next;
            }

            ptr2 = ptr2->next;
            idx2++;
        }
        
        if(ptr1 == head)
            return head->next;

        prev->next = prev->next->next;

        return head;
    }
};

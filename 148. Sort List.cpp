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

    ListNode* mergeList(ListNode* ptr1, ListNode* ptr2){
        ListNode* p = new ListNode(0);
        ListNode* curr = p;

        while(ptr1 && ptr2){
            if(ptr1->val < ptr2->val){
                curr->next = ptr1;
                ptr1 = ptr1->next;
            }
            else{
                curr->next = ptr2;
                ptr2 = ptr2->next;
            }
            curr = curr->next;
        }

        if(!ptr1)
            curr->next = ptr2;
        else if(!ptr2)
            curr->next = ptr1;

        return p->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* ptr = NULL;

        while(fast && fast->next){
            ptr = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ptr->next = NULL;

        ListNode* x = sortList(head);
        ListNode* y = sortList(slow);

        return mergeList(x, y);
    }
};

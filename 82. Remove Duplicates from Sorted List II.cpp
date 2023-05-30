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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = head;
        int curr = INT_MIN;
        while(ptr){
            if(ptr->next && curr == ptr->val){
                *ptr = *(ptr->next);
                continue;
            }
                
            else if(ptr->next && ptr->val == ptr->next->val){
                curr = ptr->val;
                *ptr = *(ptr->next);
                continue;
            }
            ptr = ptr->next;
        }

        if(head && curr == head->val)
            return NULL;

        ptr = head;
        while(ptr){
            if(ptr->next && ptr->next->val == curr)
                ptr->next = NULL;
            ptr = ptr->next;
        }
        return head;
    }
};

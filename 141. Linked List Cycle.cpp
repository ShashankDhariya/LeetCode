/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* ptr = head;
        ListNode* ctr = NULL;
        if(ptr) ctr = ptr->next;

        while(ctr && ctr->next){
            if(ptr == ctr)
                return 1;
            ptr = ptr->next;
            ctr = ctr->next->next;
        }

        return 0;
    }
};

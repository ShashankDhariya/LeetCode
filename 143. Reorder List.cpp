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
        while(ptr){
            ListNode* next = ptr->next;
            ptr->next = nxt;
            nxt = ptr;
            ptr = next;
        }

        return nxt;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        if(!fast)
            return;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* h1 = head;
        ListNode* h2 = slow->next;
        slow->next = NULL;

        h2 = reverse(h2);
        while(h2){
            ListNode* next1 = h1->next;
            ListNode* next2 = h2->next;

            h2->next = h1->next;
            h1->next = h2;

            h1 = next1;
            h2 = next2;
        }
    }
};

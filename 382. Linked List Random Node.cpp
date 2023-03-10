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
    ListNode* ptr = NULL;
    int n = 0;
    Solution(ListNode* head) {
        ptr = head;
        while(ptr){
            n++;
            ptr = ptr->next;
        }
        ptr = head;
    }
    
    int getRandom() {
        int ans;
        int r = rand() % n;
        ListNode* h = ptr;
        while(h && r--)
            h = h->next;
        return h->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

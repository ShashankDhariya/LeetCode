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

// TC - O(N) and SC - O(1) Maintaining two lists then appending them
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);
        ListNode* sStart = small;
        ListNode* lStart = large;

        while(head){
            if(head->val < x){
                small->next = head;
                small = small->next;
            }
            else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = NULL;
        small->next = lStart->next;
        return sStart->next;
    }
};


// TC - O(N) and SC - O(1) Adding larger element to the last
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next)
            return head;

        int size = 1;
        ListNode* ptr = head;
        ListNode* last = NULL;
        while(ptr->next){
            size++;
            ptr = ptr->next;
            last = ptr;
        }

        ptr = head;
        ListNode* prev = NULL;
        while(size-- && ptr){
            if(ptr->val >= x){
                if(ptr == last)
                    continue;
                else if(!prev){
                    head = ptr->next;
                    ptr->next = NULL;
                    last->next = ptr;
                    last = last->next;
                    ptr = head;
                }
                else {
                    prev->next = ptr->next;
                    ptr->next = NULL;
                    last->next = ptr;
                    last = last->next;
                    ptr = prev->next;
                }
            }
            else {
                prev = ptr;
                ptr = ptr->next;
            }
        }
        return head;
    }
};


// TC - O(N) and SC - O(N) for 2 queues
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return head;

        queue<ListNode*> q1;
        queue<ListNode*> q2;

        ListNode* ptr = head;
        while(ptr){
            if(ptr->val < x)
                q1.push(ptr);
            else 
                q2.push(ptr);
            ptr = ptr->next;
        }

        ListNode* num;
        ListNode* h;
        if(!q1.size())
            h = q2.front();
        else 
            h = q1.front();

        while(!q1.empty()){
            num = q1.front();
            q1.pop();
            if(!q1.empty())
                num->next = q1.front();
        }
        if(num && q2.size())
            num->next = q2.front();

        while(!q2.empty()){
            num = q2.front();
            q2.pop();
            if(!q2.empty())
                num->next = q2.front();
        }
        if(num)
            num->next = NULL;
        return h;
    }
};

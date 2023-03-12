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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>> > pq;
        
        for(int i=0;i<n;i++){
            ListNode* ptr = lists[i];
            while(ptr){
                pq.push({ptr->val, ptr});
                ptr = ptr->next;
            }
        }

        ListNode* ans = NULL;
        ListNode* head = NULL;

        while(!pq.empty()){
            if(!ans){
                ans = pq.top().second;
                head = ans;
            }
            else {
                ans->next = pq.top().second;
                ans = ans->next;
            }
            pq.top().second->next = NULL;
            pq.pop();
        }
        return head;
    }
};

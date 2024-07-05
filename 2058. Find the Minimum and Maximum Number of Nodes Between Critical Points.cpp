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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int dist = -1;
        int prevD = -1;

        int mini = 1e9;
        int maxi = -1;

        ListNode* ptr = head->next;
        int prev = head->val;
        int d = 0;
        while(ptr && ptr->next){
            if((prev > ptr->val && ptr->val < ptr->next->val) || (prev < ptr->val && ptr->val > ptr->next->val)){
                if(dist == -1)
                    dist = d;
                
                else {
                    mini = prevD == -1? -1: min(mini, d - prevD);
                    maxi = d - dist;
                }

                prevD = d;
            }

            d++;
            prev = ptr->val;
            ptr = ptr->next;
        }

        mini = mini == 1e9? -1: mini;
        return {mini, maxi};
    }
};

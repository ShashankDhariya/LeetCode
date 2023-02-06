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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* ptr = head;
        vector<int> ans;

        while(ptr){
            ans.push_back(ptr->val);
            ptr = ptr->next;
        }

        stack<int> st;
        for(int i=ans.size()-1;i>-1;i--){
            int num = ans[i];
            
            while(st.size() && st.top() <= num)
                st.pop();
            
            ans[i] = st.size()? st.top(): 0;
            st.push(num);
        }
        return ans;
    }
};

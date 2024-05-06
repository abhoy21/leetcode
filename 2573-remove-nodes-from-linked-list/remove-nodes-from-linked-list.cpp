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
    ListNode* removeNodes(ListNode* head) {
        stack<int> st;
        ListNode* curr = head;
        while(curr){
            while(!st.empty() && curr->val > st.top())
                st.pop();
            st.push(curr->val);
            curr = curr->next;
        }
        ListNode* temp = nullptr;
        while(!st.empty()){
            curr = new ListNode(st.top());
            curr->next = temp;
            temp = curr;
            st.pop();
        }

        return curr;
    }
};
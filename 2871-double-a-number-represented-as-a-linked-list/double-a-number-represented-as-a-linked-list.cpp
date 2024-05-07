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
    ListNode* doubleIt(ListNode* head) {
        stack<int> st;
        while(head){
            st.push(head->val);
            head = head->next;
        }

        ListNode* temp = nullptr;
        int res = 0;

        while(!st.empty() || res != 0){
            temp = new ListNode(0, temp);
            if(!st.empty()){
                res += st.top() * 2;
                st.pop();
            }
            temp->val = res % 10;
            res /= 10;
        }
        return temp;
    }
};
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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* nextptr = nullptr;
        ListNode* prevptr = nullptr;
        while(slow)
        {
            nextptr = slow->next;
            slow->next = prevptr;
            prevptr = slow;
            slow = nextptr;
        }
        int maximum = 0;
        ListNode* temp = head;
        while(prevptr)
        {
            maximum = max(maximum, temp->val+prevptr->val);
            temp = temp->next;
            prevptr = prevptr->next;
        }
        
        return maximum;
    }
};
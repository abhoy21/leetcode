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
    ListNode* reverseList(ListNode* head) {
        ListNode* prevptr = NULL;
        ListNode* crntptr = head;
        ListNode* nextptr;
        
        while(crntptr != NULL)
        {
            nextptr = crntptr->next;
            crntptr->next = prevptr;
            prevptr = crntptr;
            crntptr = nextptr;
        }
        
        return prevptr;
    }
};
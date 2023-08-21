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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l3 = new ListNode();
        ListNode* temp = l3;
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        
        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val < l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
                temp = temp->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
                temp = temp->next;
            }
        }
        
        if(l1!=nullptr)
            temp->next = l1;
        else
            temp->next = l2;
        
        return l3->next;
    }
};
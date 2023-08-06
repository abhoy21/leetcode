/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length1 = 0, length2 = 0;
        
        ListNode* temp = headA;
        while(temp)
        {
            length1++;
            temp = temp->next;
        }
        
        temp = headB;
        while(temp)
        {
            length2++;
            temp = temp->next;
        }
        
        ListNode* list1 = headA;
        ListNode* list2 = headB;

         if(length1<length2)
         {
             int k = length2 - length1;
             while(k--)
             {
                 list2 = list2->next;
             }
         }
        else
        {
            int k = length1 - length2;
            while(k--)
            {
                list1 = list1->next;
            }
        }
        
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1==list2)
                return list1;
            list1 = list1->next;
            list2 = list2->next;
        }
        
        return nullptr;
    }
};
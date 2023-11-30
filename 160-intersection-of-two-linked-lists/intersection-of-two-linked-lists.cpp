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
        int l1 = 0, l2 = 0;
        ListNode* temp = headA;
        while(temp){
            l1++;
            temp = temp->next;
        }

        temp = headB;
        while(temp){
            l2++;
            temp = temp->next;
        }

        ListNode* list1 = headA;
        ListNode* list2 = headB;

        if(l1 > l2){
            int k = l1 - l2;
            while(k--){
                list1 = list1->next;
            }
        }
        else{
            int k = l2 - l1;
            while(k--){
                list2 = list2->next;
            }
        }

        while(list1 != nullptr && list2 != nullptr){
            if(list1 == list2)
                return list1;
            list1 = list1->next;
            list2 = list2->next;
        }

        return nullptr;
    }
};
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
    ListNode* sortList(ListNode* head) {

        if(head == NULL || head ->next == NULL)
            return head;
        
        
        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        

        while(fast !=  NULL && fast -> next != NULL)
        {
            temp = slow;
            slow = slow->next;        
            fast = fast ->next ->next;  
            
        }   
        temp -> next = NULL;            
        
        ListNode* l1 = sortList(head);    
        ListNode* l2 = sortList(slow);    
        
        return mergeList(l1, l2);         
            
    }

    ListNode* mergeList(ListNode* l1, ListNode* l2)
    {
        ListNode* curr = new ListNode(0);
        ListNode* ptr = curr;

        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val < l2->val)
            {
                ptr->next = l1;
                l1 = l1->next;
            }
            else
            {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }

        if(l1 != nullptr)
        {
            ptr->next = l1;
            // l1 = l1->next;
        }
        if(l2 != nullptr)
        {
            ptr->next = l2;
            // l2 = l2->next;
        }

        return curr->next;
    }
};
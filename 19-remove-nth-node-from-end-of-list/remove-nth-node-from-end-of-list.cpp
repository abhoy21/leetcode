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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode *s=head, *f=head;          
    
        for(int i=1;i<=n+1;i++)
        {            
            if(f==NULL) return head->next;  
            f=f->next;
        }
        
        while(f!=NULL)
        {
            s = s->next;
            f = f->next;
        }
        s->next = s->next->next;
        
        return head;
    }
};
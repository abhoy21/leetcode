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
    ListNode* reverselist(ListNode* slow)
    {
        ListNode* nextptr;
        ListNode* currptr = slow->next;
        slow->next = nullptr;
        ListNode* prevptr = nullptr;
        
        while(currptr != nullptr)
        {
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        
        return prevptr;
    }
    
    ListNode* findmiddle(ListNode* head)
    {
        ListNode* f = head->next;
        ListNode* s = head;
        while(f != nullptr && f->next !=nullptr)
        {
            f = f->next->next;
            s = s->next;
        }
        
        return s;
    }
    
    void reorderList(ListNode* head) 
    {      
        ListNode* slow = findmiddle(head);
        
        ListNode* temp = head;
        ListNode* prevptr = reverselist(slow);
        
        ListNode* l;
        ListNode* r;
        while(prevptr != nullptr && temp != nullptr)
        {
            l = temp->next;
            r = prevptr->next;
            
            temp->next = prevptr;
            prevptr->next = l;
            
            temp = l;
            prevptr = r;
        }
        
    }
};
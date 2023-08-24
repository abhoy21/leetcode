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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* temp = head;
        ListNode* currptr = slow;
        slow = nullptr;
        ListNode* nextptr;
        ListNode* prevptr = nullptr;
        
        while(currptr!= nullptr)
        {
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        
        while(temp->next!=nullptr)
        {
            if(temp->val != prevptr->val)
                return false;
            
            temp = temp->next;
            prevptr = prevptr->next;
                
        }
        
        return true;
    }
};
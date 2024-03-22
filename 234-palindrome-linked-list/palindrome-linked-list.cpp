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

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* temp = head;
        ListNode* curr = slow;
        slow = nullptr;
        ListNode* prev = nullptr;
        ListNode* nextptr;

        while(curr){
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }

        while(temp->next){
            if(temp->val != prev->val)
                return false;
            temp = temp->next;
            prev = prev->next;
        }
        return true;
    }
};
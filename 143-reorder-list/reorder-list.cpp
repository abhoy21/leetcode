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
    ListNode* reverseList(ListNode* slow){
        ListNode* currptr = slow->next;
        slow->next = nullptr;
        ListNode* nextptr;
        ListNode* prevptr = nullptr;

        while(currptr != nullptr){
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }

        return prevptr;
    }
    ListNode* mid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = mid(head);

        ListNode* temp = head;
        ListNode* prevptr = reverseList(slow);

        ListNode* l;
        ListNode* r;

        while(prevptr != nullptr && temp != nullptr){
            l = temp->next;
            r = prevptr->next;

            temp->next = prevptr;
            prevptr->next = l;

            temp = l;
            prevptr = r;
        }
        

    }
};
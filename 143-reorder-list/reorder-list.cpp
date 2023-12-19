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
    ListNode* reverse(ListNode* root){
        ListNode* currptr = root->next;
        root->next = nullptr;
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

    ListNode* mid(ListNode* root){
        ListNode* slow = root;
        ListNode* fast = root->next;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    void reorderList(ListNode* head) {
        ListNode* m = mid(head);
        ListNode* prev = reverse(m);
        ListNode* temp = head;

        ListNode* l;
        ListNode* r;
        while(prev != nullptr && temp != nullptr){
            l = temp->next;
            r = prev->next;

            temp->next = prev;
            prev->next = l;

            temp = l;
            prev = r;
        }
    }
};
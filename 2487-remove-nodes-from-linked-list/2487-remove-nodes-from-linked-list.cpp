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
    ListNode* removeNodes(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next= NULL;
        if (head == NULL || head->next == NULL){
            return head;
        }    
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
        curr = head;
        int maxseen = head->val;
        while(curr->next != NULL) {
            if(curr->next->val < maxseen) {
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
                maxseen = curr->val;
            }
        }
        curr = head;
        prev = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
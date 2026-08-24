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
    ListNode* findmiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

        }
        return slow;
    }
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }

        }
        if(l1) temp->next = l1;
        else temp->next = l2;
        return dummyNode->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* middle = findmiddle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = NULL;

        left = sortList(left);
        right = sortList(right);
        return mergeList(left, right);
    }
};
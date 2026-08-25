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
    ListNode* findnthNode(ListNode* temp, int k) {
        int count = 1;
        while(temp != NULL) {
            if(count == k) {
                return temp;
            }
            count++;
            temp = temp->next;
        }
        return temp;

    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) {
            return head;
        }
        ListNode* tail = head;
        int len = 1;
        while(tail->next != NULL) {
            tail = tail->next;
            len += 1;
        }
        if(k % len == 0) return head;
        k = k % len;
        tail->next = head;
        ListNode* lastNode = findnthNode(head, len-k);
        head = lastNode->next;
        lastNode->next = NULL;
        return head;
    }
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        // Move prev to the node just before position left
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* nextnode = nullptr;

        for (int i = 0; i < right - left; i++) {
            nextnode = curr->next;
            curr->next = nextnode->next;
            nextnode->next = prev->next;
            prev->next = nextnode;
        }

        return dummy->next;
    }
};
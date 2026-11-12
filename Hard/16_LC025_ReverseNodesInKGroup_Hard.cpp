class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* prevGroup = &dummy;

        while (true) {
            // find the k-th node of this group
            ListNode* kth = prevGroup;
            for (int i = 0; i < k && kth != nullptr; i++) {
                kth = kth->next;
            }
            if (kth == nullptr) break;   // fewer than k nodes left

            ListNode* groupNext = kth->next;
            ListNode* prev = groupNext;
            ListNode* curr = prevGroup->next;

            // reverse the group
            while (curr != groupNext) {
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }

            ListNode* groupFirst = prevGroup->next;   // becomes the group's tail
            prevGroup->next = kth;
            prevGroup = groupFirst;
        }
        return dummy.next;
    }
};

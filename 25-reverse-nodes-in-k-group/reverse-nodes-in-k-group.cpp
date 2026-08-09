class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        // Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroup = dummy;

        while (true) {

            // Find the kth node
            ListNode* kth = prevGroup;

            for (int i = 0; i < k; i++) {
                kth = kth->next;

                // Less than k nodes remain
                if (kth == nullptr) {
                    return dummy->next;
                }
            }

            // Node after the current group
            ListNode* nextGroup = kth->next;

            // Reverse current group
            ListNode* prev = nextGroup;
            ListNode* curr = prevGroup->next;

            while (curr != nextGroup) {
                ListNode* next = curr->next;

                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Connect previous part to reversed group
            ListNode* oldStart = prevGroup->next;

            prevGroup->next = kth;

            // oldStart is now the end of reversed group
            prevGroup = oldStart;
        }

        return dummy->next;
    }
};
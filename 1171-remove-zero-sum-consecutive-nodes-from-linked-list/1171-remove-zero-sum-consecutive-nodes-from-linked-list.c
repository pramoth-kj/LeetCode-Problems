/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *temp = dummy;

    while (temp != NULL) {
        struct ListNode *current = temp->next;
        int sum = 0;

        while (current != NULL) {
            sum += current->val;
            if (sum == 0) {
                temp->next = current->next;
                break;
            }
            current = current->next;
        }

        if (current == NULL) {
            temp = temp->next;
        }
    }

    return dummy->next;
}
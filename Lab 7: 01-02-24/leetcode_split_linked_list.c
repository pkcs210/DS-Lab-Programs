int getLength(struct ListNode* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    int length = getLength(head);
    int width = length / k;
    int remainder = length % k;
    struct ListNode** result = (struct ListNode**)malloc(k * sizeof(struct ListNode*));

    struct ListNode* current = head;
    for (int i = 0; i < k; i++) {
        result[i] = current;
        int partSize = width + (i < remainder ? 1 : 0);
        for (int j = 0; j < partSize - 1; j++) {
            if (current != NULL) {
                current = current->next;
            }
        }
        if (current != NULL) {
            struct ListNode* temp = current;
            current = current->next;
            temp->next = NULL;
        }
    }

    *returnSize = k;
    return result;
}

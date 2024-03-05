int getLength(struct ListNode* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    int length = getLength(head);
    k = k % length;
    if (k == 0) {
        return head;
    }

    struct ListNode* tail = head;
    for (int i = 0; i < length - k - 1; i++) {
        tail = tail->next;
    }

    struct ListNode* newHead = tail->next;
    tail->next = NULL;

    struct ListNode* current = newHead;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head;

    return newHead;
}

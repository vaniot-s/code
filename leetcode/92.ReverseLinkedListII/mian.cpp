//
// Created by vaniot on 18-12-9.
//

#include "mian.h"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    ListNode *head = createLinkedList(arr, n);
    printLinkedList(head);
    return 0;
}
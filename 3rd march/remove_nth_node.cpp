#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode(); // Dummy node to handle edge case where the head itself needs to be removed
        start->next = head;
        ListNode* fast = start;
        ListNode* slow = start;

        // Move fast pointer n+1 steps ahead
        for(int i = 0; i < n + 1; ++i) {
            fast = fast->next;
        }

        // Move both pointers together until fast reaches the end
        while(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end
        slow->next = slow->next->next;

        // Store the head of the modified list
        ListNode* result = start->next;
        delete start; // Free dummy node memory

        return result;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original List: ";
    printList(head);

    Solution sol;
    int n = 2; // Remove 2nd node from end

    ListNode* modifiedHead = sol.removeNthFromEnd(head, n);

    std::cout << "Modified List: ";
    printList(modifiedHead);

    // Freeing memory
    ListNode* temp;
    while (modifiedHead != nullptr) {
        temp = modifiedHead;
        modifiedHead = modifiedHead->next;
        delete temp;
    }

    return 0;
}

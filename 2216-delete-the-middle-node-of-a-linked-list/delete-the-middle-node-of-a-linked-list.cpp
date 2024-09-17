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
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: if the list is empty or contains only one node
        if (head == NULL || head->next == NULL) {
            return NULL; // Return NULL since there's no middle to delete
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL; // To keep track of the node before 'slow'

        // Move fast pointer two steps at a time and slow one step at a time
        while (fast != NULL && fast->next != NULL) {
            prev = slow;         // Store the node before the middle
            slow = slow->next;   // Move slow pointer by one
            fast = fast->next->next; // Move fast pointer by two
        }

        // 'slow' is now pointing at the middle node. Remove it.
        prev->next = slow->next; // Bypass the middle node
        delete(slow);            // Free the memory of the middle node

        return head; // Return the head of the modified list
    }
};

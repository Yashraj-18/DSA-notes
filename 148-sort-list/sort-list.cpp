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
    // Function to find the middle of a linked list
    ListNode* findMiddle(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;  // Start fast at head->next to ensure proper middle splitting
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    // Function to merge two sorted linked lists
    ListNode* mergeTwoSortedLinkedLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        // Attach remaining nodes of either list
        temp->next = (list1 != nullptr) ? list1 : list2;

        ListNode* sortedHead = dummyNode->next;
        delete dummyNode;  // Free the dummy node to prevent memory leaks
        return sortedHead;
    }

    // Function to perform merge sort on a linked list
    ListNode* sortList(ListNode* head) {
        // Base case: if the list is empty or has only one node, it is already sorted
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Find the middle of the list
        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;  // Split the list into two halves
        ListNode* left = head;

        // Recursively sort the left and right halves
        left = sortList(left);
        right = sortList(right);

        // Merge the sorted halves
        return mergeTwoSortedLinkedLists(left, right);
    }
};

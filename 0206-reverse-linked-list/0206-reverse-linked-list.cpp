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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp) {
            ListNode* next = temp->next;  // Save next node
            temp->next = prev;            // Reverse the link
            prev = temp;                  // Move prev forward
            temp = next;                  // Move temp forward
        }

        return prev;
    }
};

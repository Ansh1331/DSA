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
    ListNode* reverseLL(ListNode*head){
        ListNode* temp=head;
        ListNode*prev=nullptr;
        ListNode*front=nullptr;
        while(temp){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* secondHalf=slow->next;
        slow->next=nullptr;
        ListNode* secondhead=secondHalf;
        ListNode* compare2=reverseLL(secondHalf);

        while(compare2){
            if(head->val != compare2->val) return false;
            head=head->next;
            compare2=compare2->next;
        }
        return true;
    }
};
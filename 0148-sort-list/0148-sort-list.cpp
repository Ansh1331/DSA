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
   ListNode* getMid(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    return prev;  // return node *before* middle
}

    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;

        while(left && right){
            if(left->val <= right->val){
                temp->next=left;
                left=left->next;
            }
            else{
                temp->next=right;
                right=right->next;
            }
            temp=temp->next;
        }
        if(left){
            temp->next=left;
        }
        else{
            temp->next=right;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;

        ListNode* breakpoint=getMid(head);
        ListNode* secondhalf=breakpoint->next;
        breakpoint->next=nullptr;

        ListNode* lefthead =sortList(head);
        ListNode* righthead =sortList(secondhalf);
        return merge(lefthead,righthead);
    }
};
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
    class compare{
        public:
        bool operator()(ListNode* a,ListNode*b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> minheap;

        for(int i=0;i<lists.size();i++){
           if(lists[i]!=nullptr){
                minheap.push(lists[i]);
           }
        }
        ListNode* head=NULL;
        ListNode* tail=NULL;

        while(!minheap.empty()){
            ListNode* temp=minheap.top();
            minheap.pop();

            if(head==nullptr){
                head=temp;
                tail=temp;
            }
            else{
                tail->next= temp;
                tail=temp;
            }

            if(temp->next != NULL){
                minheap.push(temp->next);
            }
        }
        return head;
    }   
};
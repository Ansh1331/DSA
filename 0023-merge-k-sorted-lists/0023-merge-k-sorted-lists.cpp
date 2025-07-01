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
class Compare{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummynode=new ListNode();
        ListNode* temp=dummynode;
        priority_queue< ListNode*, vector<ListNode*> ,Compare> minh;

        for(int i=0;i<lists.size();i++){
            if(lists[i]){
            minh.push(lists[i]);

            }
        }

        while(!minh.empty()){
            ListNode* it= minh.top();
            minh.pop();

            temp->next= it;
            temp=temp->next;

            if(it->next != NULL){
                minh.push(it->next);
            }
        }
        return dummynode->next;
    }
};
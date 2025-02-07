/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator{
    stack<TreeNode*> st;
    //reverse=false means finding next
    //reverse=true means finding before
    bool reverse=true;

public:
    BSTIterator(TreeNode* root, bool Isreverse){
        reverse= Isreverse;
        pushAll(root);
    }

    int next(){
        TreeNode* el=st.top();
        st.pop();
        if(!reverse){
            pushAll(el->right);
        }
        else{
            pushAll(el->left);
        }
        return el->val;
    }

    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            if(reverse==true){
                root=root->right;
            }
            else{
                root=root->left;
            } 
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;

        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            if(i+j < k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};
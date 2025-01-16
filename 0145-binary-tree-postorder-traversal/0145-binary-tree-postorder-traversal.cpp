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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st1,st2;
        if(root==NULL) return res;

        st1.push(root);
        while(!st1.empty()){
            TreeNode* el=st1.top();
            st1.pop();
            st2.push(el);
            if(el->left != NULL) st1.push(el->left);
            if(el->right != NULL) st1.push(el->right);
        }

        while(!st2.empty()){
            TreeNode* el=st2.top();
            if(el==NULL) break;
            st2.pop();
            res.push_back(el->val);
        }
        return res;
    }
};

   
    

    /*
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root,res);
        return res;
    }

    void postorder(TreeNode* root,vector<int>& res){
        if(root==NULL) return;

        postorder(root->left,res);
        postorder(root->right,res);
        res.push_back(root->val);
    }   
    */
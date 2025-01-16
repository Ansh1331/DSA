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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* el=st.top();
            res.push_back(el->val);
            st.pop();
            if(el->right != NULL) st.push(el->right);
            if(el->left != NULL) st.push(el->left);
        }
        return res;
    }


    /*
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        pre(root,res);
        return res;
    }

    void pre(TreeNode* root,vector<int>& res){
        if(root==NULL) return;
        res.push_back(root->val);
        pre(root->left,res);
        pre(root->right,res);
    }   
    */
};
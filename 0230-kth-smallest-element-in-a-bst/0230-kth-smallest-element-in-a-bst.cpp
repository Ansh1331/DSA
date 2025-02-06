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
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return -1;
        int res=-1;
        int count=0;
        inorder(root,k,res,count);
        return res;
    }

    void inorder(TreeNode* root,int k,int & res,int & count){  
        if(root==NULL) return;      
        inorder(root->left,k,res,count);
        count++;
        if(count==k){
            res=root->val;
            return;
        }
        inorder(root->right,k,res,count);
    }
};
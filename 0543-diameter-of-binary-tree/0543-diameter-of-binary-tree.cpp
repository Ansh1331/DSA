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
    int diameterOfBinaryTree(TreeNode* root) {
        int start=0;
        helper(root,start);
        return start;
    }

    int helper(TreeNode* root,int& start){
        if(root==NULL) return 0;

        int lh= helper(root->left,start);
        int rh= helper(root->right,start);
        
        start=max(start,lh+rh);

        return 1+max(lh,rh);
    }
};
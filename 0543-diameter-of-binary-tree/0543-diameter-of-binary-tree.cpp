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
    int maxDepth(TreeNode* root,int & count){
        if(root==NULL) return 0;

        int lh=maxDepth(root->left,count);
        int rh=maxDepth(root->right,count);
        count=max(count,lh+rh);
        return 1+ max(lh,rh);
    }


    int diameterOfBinaryTree(TreeNode* root) {
        int count=0;
        maxDepth(root,count);
        return count;
    }

};
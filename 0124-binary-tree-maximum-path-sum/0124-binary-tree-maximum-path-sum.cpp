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
    int maxPathSum(TreeNode* root) {
        int start=INT_MIN;
        helper(root,start);
        return start;
    }

    int helper(TreeNode* root, int& start){
        if(root==NULL) return 0;

        int lsum=max(0,helper(root->left,start));
        int rsum=max(0,helper(root->right,start));

        start=max(start,lsum+rsum+root->val);
        return root->val+max(lsum,rsum);
    }
};
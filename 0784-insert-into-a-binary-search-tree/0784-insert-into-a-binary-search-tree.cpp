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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp=root;
        TreeNode* newnode= new TreeNode(val);
        if(root==NULL) return newnode;
        
        while(true){
            if(temp->val < val){
                if(temp->right) temp=temp->right;
                else{
                    temp->right= newnode;
                    break;
                }
            }
            else{
                if(temp->left) temp=temp->left;
                else{
                    temp->left=newnode;
                    break;
                }
            }
        }
        return root;
    }
};
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
    TreeNode* findrightmost(TreeNode* node){
        while(node->right){
            node=node->right;
        }
        return node;
    }
    TreeNode* helper(TreeNode* root){
   //     TreeNode* rightmost= findright(root);
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        TreeNode* right=root->right;
        TreeNode* rightmostinleft= findrightmost(root->left);
        rightmostinleft->right=right;
        return root->left;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if(root->val == key){
            return helper(root);
        }
        TreeNode* dummy=root;
        while(root){
            if(root->val < key){
                if(root->right && root->right->val==key){
                    root->right=helper(root->right);
                    break ;
                }
                else{
                    root=root->right;
                }
            }
            else{
                if(root->left && root->left->val==key){
                    root->left=helper(root->left);
                    break ;
                }
                else{
                    root=root->left;
                }
            }
        }
        return dummy;
    }
};
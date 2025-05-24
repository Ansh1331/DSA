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
    TreeNode* buildTrees(vector<int> preorder,int pstart,int pend,vector<int> inorder,int istart,int iend,map<int,int> & mpp){
        if(pstart>pend || istart>iend) return NULL;

        TreeNode* root=new TreeNode(preorder[pstart]);
        int inroot= mpp[root->val];
        int numsleft=inroot-istart;

        root->left=buildTrees(preorder,pstart+1,pstart+numsleft,inorder,istart,inroot-1,mpp);
        root->right=buildTrees(preorder,pstart+numsleft+1,pend,inorder,inroot+1,iend,mpp);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        int n=preorder.size();

        TreeNode* root= buildTrees(preorder,0,n-1,inorder,0,n-1,mpp);
        return root;
    }
};
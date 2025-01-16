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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        bool leftTOright=true;
        queue<TreeNode*> q;
        q.push(root);

        helper(root,res,leftTOright,q);
        return res;
    }

    void helper(TreeNode* root, vector<vector<int>>& res,bool& leftTOright,
                                queue<TreeNode*> q){
        if(root==NULL) return;

        while(!q.empty()){
            int size=q.size();
            vector<int> curr(size);
            for(int i=0;i<size;i++){
                TreeNode* el=q.front();
                q.pop();

                //finding position to put element
                int index= (leftTOright) ? i: (size-i-1);
                curr[index]=el->val;

                if(el->left != NULL) q.push(el->left);
                if(el->right != NULL) q.push(el->right);
            }
            leftTOright= !leftTOright;
            res.push_back(curr);
        }
    }
};
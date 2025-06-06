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
        bool zigzag=true;
        queue<TreeNode*> q;
        if(root==NULL) return res;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            zigzag=!zigzag;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(zigzag){
                reverse(temp.begin(),temp.end());
                res.push_back(temp);
            }
            else{
                res.push_back(temp);
            }
        }
        return res;
    }
};
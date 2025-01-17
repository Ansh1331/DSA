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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if(root==NULL) return ans;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* el=q.front();
                q.pop();
                
                if(i==size-1){
                    ans.push_back(el->val);
                }

                if(el->left){
                    q.push(el->left);
                }
                if(el->right){
                    q.push(el->right);
                }
            }
        }

        return ans;
    }
};


/*
vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        map<int,int> mpp;
        vector<int> ans;
        if(root==NULL) return ans;
        q.push({root,0});

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                TreeNode* el=it.first;
                int line=it.second;
                mpp[line]=el->val;

                if(el->left){
                    q.push({el->left,line+1});
                }
                if(el->right){
                    q.push({el->right,line+1});
                }
            }
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
*/
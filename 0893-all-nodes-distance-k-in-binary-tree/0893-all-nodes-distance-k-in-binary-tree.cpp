/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent,queue<TreeNode*>& q){
        if(root==NULL) return;
        q.push(root);
        parent[root]=NULL;

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                TreeNode* curr_parent=it;
                if(it->left){
                    q.push(it->left);
                    parent[it->left]=curr_parent;
                }
                if(it->right){
                    q.push(it->right);
                    parent[it->right]=curr_parent;
                }
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        queue<TreeNode*> q2;
        findparent(root,parent,q2);

        int count=0;
        vector<int> res;
        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*,bool>vis;
        vis[target]=true;

        while(k--){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                TreeNode* curr=it;
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(parent[curr] && !vis[parent[curr]]){
                    q.push(parent[curr]);
                    vis[parent[curr]]=true;
                }

            }
        }

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            res.push_back(it->val);
        }
        return res;
    }
};
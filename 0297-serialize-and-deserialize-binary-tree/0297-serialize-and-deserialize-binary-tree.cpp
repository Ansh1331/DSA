/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);


        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node==NULL) s.append("#,");
                else s.append(to_string(node->val)+',');

                if(node!=NULL){
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        queue<TreeNode*> q;

        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root= new TreeNode(stoi(str));
        q.push(root);

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#"){
                node->left=NULL;
            }
            else{
                TreeNode* newnode= new TreeNode(stoi(str));
                node->left=newnode;
                q.push(newnode);
            }

            getline(s,str,',');
            if(str=="#"){
                node->right=NULL;
            }
            else{
                TreeNode* newnode= new TreeNode(stoi(str));
                node->right=newnode;
                q.push(newnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& inorderTraversal) {
        if (root == nullptr) return;
        inorder(root->left, inorderTraversal);
        inorderTraversal.push_back(root->val);
        inorder(root->right, inorderTraversal);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> inorderTraversal;
        inorder(root, inorderTraversal);
        for (int i = 1; i < inorderTraversal.size(); ++i) {
            if (inorderTraversal[i] <= inorderTraversal[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

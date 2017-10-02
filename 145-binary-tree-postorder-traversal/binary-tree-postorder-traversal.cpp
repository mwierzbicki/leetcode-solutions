// Given a binary tree, return the postorder traversal of its nodes' values.
//
//
// For example:
// Given binary tree {1,#,2,3},
//
//    1
//     \
//      2
//     /
//    3
//
//
//
// return [3,2,1].
//
//
// Note: Recursive solution is trivial, could you do it iteratively?


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
private:
vector<int> sol;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root!=NULL) {
            dfs(root);
        }
        return sol;
    }
    void dfs(TreeNode* node) {
        if (node->left!=NULL) {
            dfs(node->left);
        }
        if (node->right!=NULL) {
            dfs(node->right);
        }
        sol.push_back(node->val);
        return;
    }
};

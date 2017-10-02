// Given a binary tree, return the preorder traversal of its nodes' values.
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
// return [1,2,3].
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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> po,h;
        if (root!=NULL) {
            po.push_back(root->val);
            if (root->left!=NULL) {
                h=preorderTraversal(root->left);
                po.insert(po.end(), h.begin(), h.end());
            }
            if (root->right!=NULL) {
                h=preorderTraversal(root->right);
                po.insert(po.end(), h.begin(), h.end());
            }
        }
        return po;
    }
};

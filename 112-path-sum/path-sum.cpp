//
// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
//
//
// For example:
// Given the below binary tree and sum = 22,
//
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1
//
//
//
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.


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
bool sol;
int gsum;
public:
    bool hasPathSum(TreeNode* root, int sum) {
        sol=false;
        gsum=sum;
        test(root,0);
        return sol;
    }
    void test(TreeNode* root, int sum) {
        int lsol=sum;
        if (root!=NULL) {
            if (root->left==NULL && root->right==NULL && lsol+root->val==gsum) {
                sol=1;
            }
            if (root->left!=NULL) {
                test(root->left,lsol+root->val);
            }
            if (root->right!=NULL) {
                test(root->right,lsol+root->val);   
            }
        }
        return;
    }
};

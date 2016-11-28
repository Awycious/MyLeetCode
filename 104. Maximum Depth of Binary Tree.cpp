/* ************************************************************* *
 *      Annie Wang 2016.11.23                                    *
 * Idea: Recursion, tooooo simple, I'm gonna do another to       *
 *      fullfill my task tooday                                  *
 * Remark: N/A                                                   *
 * ************************************************************* *
 */
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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

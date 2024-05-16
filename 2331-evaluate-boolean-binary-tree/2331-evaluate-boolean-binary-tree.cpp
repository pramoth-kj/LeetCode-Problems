/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool evaluateTree(struct TreeNode* root) {
    if(root->val == 0)          //Leaf (False)
        return false;
    else if(root->val == 1)     //Leaf (True)
        return true;
    else if(root->val == 2)     //Non-leaf (OR)
        return evaluateTree(root->left) || evaluateTree(root->right);
    return evaluateTree(root->left) && evaluateTree(root->right);   //Non-leaf (AND)
}
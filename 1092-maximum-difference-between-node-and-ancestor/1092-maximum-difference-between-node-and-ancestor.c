
int madHelper(struct TreeNode* node, int min_seen, int max_seen) {
    int leftdiff,rightdiff;
    if (!(node -> val < min_seen || node -> val > max_seen))
        ;
    else {
        if (node -> val > max_seen)
            max_seen = node -> val; 
        else 
            min_seen = node -> val;    
        }
    int diff = max_seen - min_seen;
    if (node -> left == NULL && node -> right == NULL)
        return diff;
    else if (!(node -> left != NULL && node -> right != NULL)) {
        if (node -> left == NULL) {
            leftdiff = 0;
            rightdiff = madHelper(node -> right, min_seen, max_seen);
            return (rightdiff > diff ? rightdiff : diff);
        } else {
            rightdiff = 0;
            leftdiff = madHelper(node -> left, min_seen, max_seen);
            return (leftdiff > diff ? leftdiff : diff);
        }
    }
    else {
        leftdiff = madHelper(node -> left, min_seen, max_seen);
        rightdiff = madHelper(node -> right, min_seen, max_seen);
        return leftdiff > rightdiff ? leftdiff : rightdiff;
    }
}

int maxAncestorDiff(struct TreeNode* root){
    if (root == NULL)
        return 0;
    else 
        return madHelper(root, root -> val, root -> val);
}
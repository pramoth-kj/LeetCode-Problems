/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode TreeNode_t;
typedef struct { int* arr; int size; int len; } DynamicArray_t;
#define D_ARR_BEGIN_SIZE 8
#define D_ARR_INIT(dArr) (dArr)=(DynamicArray_t){.len=0,                 \
    .arr=malloc(D_ARR_BEGIN_SIZE*sizeof(int)), .size=D_ARR_BEGIN_SIZE}
#define D_ARR_APPEND(dArr, val) {                                        \
    if((dArr)->size<=(dArr)->len+1)                                      \
    { (dArr)->arr=realloc((dArr)->arr, ((dArr)->size*=2)*sizeof(int)); } \
    (dArr)->arr[(dArr)->len++]=(val);                                    \
}

bool traverse(TreeNode_t* node, DynamicArray_t* dArr, int depth) {
    if(depth%2 && node->val%2){ return false; }
    if(!(depth%2) && !(node->val%2)){ return false; }
    
    if(dArr->len>depth) {
        if(depth%2 && dArr->arr[depth]<=node->val){ return false; }
        if(!(depth%2) && dArr->arr[depth]>=node->val){ return false; }
        dArr->arr[depth]=node->val;
    } else { D_ARR_APPEND(dArr, node->val); }

    if(node->left && !traverse(node->left, dArr, depth+1)){ return false; }
    if(node->right && !traverse(node->right, dArr, depth+1)){ return false; }
    return true;
}

bool isEvenOddTree(TreeNode_t* root) {
    DynamicArray_t dArr; D_ARR_INIT(dArr);
    bool result=traverse(root, &dArr, 0); free(dArr.arr);
    return result;
}
/**
 * Definition for a binary tree TreeNode.
 * struct TreeTreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */                                                   
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
int minDepth(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    int left_depth = minDepth(root->left);
    int right_depth = minDepth(root->right);
    return (left_depth < right_depth) ? left_depth + 1 : right_depth + 1;
}
int main() {
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->data = 1;
    root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->data = 2;
    root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->data = 3;
    root->left->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->left->data = 4;
    root->left->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->right->data = 5;
    printf("The minimum depth of the tree is %d\n", minDepth(root));
    return 0;
}



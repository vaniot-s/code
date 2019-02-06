//
// Created by vaniot on 18-12-14.
//
/*
 *
 * 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
*/
#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H
 Definition for a binary tree node.
 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

class main {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root==NULL){
            return false;
        }
        if(root->left==NULL&&root->right==NULL){ //递归的终止条件
            returnroot->val==sum;
        }
        if(hasPathSum(root->left,sum-root->val)){
            return true;
        }
        if (hasPathSum((root->right,sum-root->val))){
            return true;
        }
        return false;
    }
};


#endif //NOTES_MAIN_H

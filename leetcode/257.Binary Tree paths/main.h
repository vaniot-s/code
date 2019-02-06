//
// Created by vaniot on 18-12-14.
//

#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H
/*
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

*/
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class main {
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        //递归的终止条件
        if(root==NULL){
            return res;
        }
        if(root->left==NULL&&root->right==NULL){ //节点没有后代节点,返回节点
            res.push_back(to_string(root->val));
            return res;
        }

       vector<string> leftS=binaryTreePaths(root->left);
        for (int i = 0; i < leftS.size(); ++i) {
            res.push_back(to_string(root->val+"->"+leftS[i]);
        }
        vector<string> rightS=binaryTreePaths(root->right);
        for (int i = 0; i < rightS.size(); ++i) {
            res.push_back(to_string(root->val+"->"+rightS[i]);
        }

        return  res;
    }
};


#endif //NOTES_MAIN_H

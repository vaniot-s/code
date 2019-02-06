//
// Created by vaniot on 18-12-11.
//
/*
 * 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

*/
#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class main {
public:
    vector <vector<int>> levelOrder(TreeNode *root) {
        vector <vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue <pair<TreeNode *, int>> q; //pair trenode int 第几层
        q.push(make_pair(root, 0)); //节点的层数
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            if (level == res.size()) {
                res.push_back(vector<int>());
            }
            res[level].push_back(node->val);
            if(node->left){
                q.push(make_pair(node->left,level+1));
            }
            if(node->right){
                q.push(make_pair(node->right,level+1));
            }
        }
        return res;
    }
};


#endif //NOTES_MAIN_H

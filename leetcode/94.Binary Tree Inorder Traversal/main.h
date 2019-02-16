//
// Created by vaniot on 18-12-11. Container With Most Water.
//

#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H

#include <vector>

using namespace std;

/*
 * 给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]

进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Command {
    string s;
    TreeNode *node;

    Command(string s, TreeNode *node) : s(s), node(node) {}
};

class main {
public:
    vector<int> InorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }

        stack <Command> stack;
        stack.push(Command("go", root));
        while (!stack.empty()) {
            Command command = stack.top();
            stack.pop();
            if (command.s == "print") {
                res.push_back(command.node->val);
            } else {
                assert(command.s == "go");
                if (command.node->right) {
                    stack.push(Command("go", command.node->right));
                }
                stack.push(Command("print", command.node));
                if (command.node->left) {
                    stack.push(Command("go", command.node->left));
                }

            }
        }
        return res;
    }
};


#endif //NOTES_MAIN_H

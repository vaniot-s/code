//
// Created by vaniot on 18-12-11.
//
/*
 *

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [3,2,1]

进阶: 递归算法很简单，你可以通过迭代算法完成吗？*/
#ifndef NOTES_MAIN_H
#define NOTES_MAIN_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Command {
    string s;
    TreeNode *node;
    Command(string s, TreeNode *node) : s(s),node(node){}
};

class main {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }

        stack<Command> stack;
        stack.push(Command("go",root));
        while(!stack.empty()){
            Command command=stack.top();
            stack.pop();
            if (command.s=="print"){
                res.push_back(command.node->val);
            }else{
                assert(command.s=="go");
                stack.push(Command("print",command.node));
                if (command.node->right){
                    stack.push(Command("go",command.node->right));
                }
                if (command.node->left){
                    stack.push(Command("go",command.node->left));
                }

            }
        }
        return res;
    }
};


#endif //NOTES_MAIN_H

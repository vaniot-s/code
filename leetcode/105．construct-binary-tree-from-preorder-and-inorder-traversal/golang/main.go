/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func buildTree(preorder []int, inorder []int) *TreeNode {
if len(preorder)!=len(inorder)||len(preorder)==0{
    return nil
}

   // 根节点
   root :=preorder[0]
   rootIndex :=0
   for i:=0; i<len(inorder); i++{
       if inorder[i]==root{
           rootIndex=i
       }
   }

  //

inLeft,inRight :=inorder[:rootIndex],inorder[rootIndex+1:] // 左子树，右子树
preLeft,preRight:=preorder[1:rootIndex+1],preorder[rootIndex+1:] // 前序遍历的特点，根节点在前

 // 递归
 left:=buildTree(preLeft,inLeft)
 right:=buildTree(preRight,inRight)
 return &TreeNode{Val:root,Left:left,Right:right}
}

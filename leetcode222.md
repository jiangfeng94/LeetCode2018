# 222. Count Complete Tree Nodes

> Given a complete binary tree, count the number of nodes.

## 思路一：
递归，分别计算左右两个node
```
    int countNodes(TreeNode* root) {
        if(root)  return countNodes(root->left)+countNodes(root->right) +1;
        else return 0;
    }
```
> 结果超时了

## 思路二：
先计算左右的深度是否相等，相等则为满二叉树，满二叉树的节点个数为深度的平方减一,即depth^2-1；如果不相等，则递归以同样的方式计算左子树和右子树，并返回两者个数之和加一。
```
 int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int ldepth = getLeftDepth(root);
        int rdepth = getRightDepth(root);
        //return the square of leftdepth -1
        if(ldepth == rdepth) return (1 << ldepth) - 1;

        return countNodes(root->left)+countNodes(root->right)+1;
    }
    //compute the depth of left tree
    int getLeftDepth(TreeNode *root){
        int depth = 0;
        while(root){
            depth++;
            root = root->left;
        }
        return depth;
    }
    //compute the depth of right tree
    int getRightDepth(TreeNode *root){
        int depth = 0;
        while(root){
            depth++;
            root = root->right;
        }
        return depth;
    }
```
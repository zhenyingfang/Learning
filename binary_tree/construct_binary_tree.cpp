/*
 * @Author: fzy
 * @Date: 2018-12-14 20:42:00
 * @LastEditors: Zhenying
 * @LastEditTime: 2018-12-14 20:46:08
 * @Description: 根据中序遍历和后序遍历，以及先序遍历和中序遍历重建二叉树
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// 由中序和后序重建二叉树

TreeNode* helper1(vector<int>& inorder, vector<int>& postorder, int l1, int r1, int l2, int r2) {
    if (r1 < l1 || r2 < l2)
        return NULL;
    TreeNode* tmp = new TreeNode(postorder[r2]);
    if (l2 == r2)
        return tmp;
    int n1 = postorder[r2];
    int len = 0;
    for (int i = l1; i <= r1; ++i) {
        if (inorder[i] == n1)
            break;
        len++;
    }
    tmp->left = helper1(inorder, postorder, l1, l1 + len - 1, l2, l2 + len - 1);
    tmp->right = helper1(inorder, postorder, l1 + len + 1, r1, l2 + len, r2 - 1);
    return tmp;
}

TreeNode* buildTree1(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() == 0)
        return NULL;
    return helper1(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}

// 由先序和中序重建二叉树

TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int l1, int r1, int l2, int r2) {
    if (r1 < l1 || r2 < l2) {
        return NULL;
    }
    
    int nval = preorder[l1];
    
    TreeNode* tmp = new TreeNode(nval);
    if (l1 == r1 || l2 == r2) {
        return tmp;
    }
    
    int len = 0;
    for (int i = l2; i <= r2; ++i) {
        if (inorder[i] == nval)
            break;
        len++;
    }
    
    tmp->left = helper(preorder, inorder, l1 + 1, l1 + len, l2, l2 + len - 1);
    tmp->right = helper(preorder, inorder, l1 + len + 1, r1, l2 + len + 1, r2);
    
    return tmp;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0)
        return NULL;
    return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

/*
 * @Author: fzy
 * @Date: 2018-12-14 15:17:33
 * @LastEditors: Zhenying
 * @LastEditTime: 2018-12-14 15:35:01
 * @Description: 二叉树先中后，层次遍历。递归，非递归，morris
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> res1;
vector<vector<int>> res2;

// 递归版先序遍历、中序遍历、后序遍历

void preorder(TreeNode* root) {
    if (root == NULL)
        return;
    res1.push_back(root->val);
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (root == NULL)
        return;
    preorder(root->left);
    res1.push_back(root->val);
    preorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == NULL)
        return;
    preorder(root->left);
    preorder(root->right);
    res1.push_back(root->val);
}

// 非递归版，先序遍历、中序遍历、后序遍历

vector<int> preorderTraversal(TreeNode* root) {
    if (root == NULL)
        return res1;
    stack<TreeNode*> s;
    TreeNode* node = root;
    
    while (node || !s.empty()) {
        while (node) {
            res1.push_back(node->val);
            s.push(node);
            node = node->left;
        }
        TreeNode* tmp = s.top();
        s.pop();
        node = tmp->right;
    }
    
    return res1;
}

vector<int> inorderTraversal(TreeNode* root) {
    if (root == NULL)
        return res1;
    
    stack<TreeNode*> s;
    TreeNode* node = root;
    
    while (node || !s.empty()) {
        while (node) {
            s.push(node);
            node = node->left;
        }
        TreeNode* tmp = s.top();
        s.pop();
        res1.push_back(tmp->val);
        node = tmp->right;
    }
    
    return res1;
}

vector<int> postorderTraversal(TreeNode* root) {
        
    if (root == NULL)
        return res1;
    
    stack<TreeNode*> s;
    TreeNode* node = root;
    
    while (node || !s.empty()) {
        while (node) {
            res1.insert(res1.begin(), node->val);
            s.push(node);
            node = node->right;
        }
        
        TreeNode* tmp = s.top();
        s.pop();
        node = tmp->left;
    }
    
    return res1;
}

// 层次遍历

vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == NULL) return res2;
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        vector<int> tmp;
        while (size--) {
            TreeNode* node = q.front();
            q.pop();
            tmp.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        res2.push_back(tmp);
    }
    return res2;
}

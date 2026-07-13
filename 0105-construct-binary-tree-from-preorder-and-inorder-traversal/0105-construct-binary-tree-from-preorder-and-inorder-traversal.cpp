/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    TreeNode* create(vector<int> &preorder, vector<int> &inorder, int &pre, int inStart, int inEnd)
    {
        if (inStart > inEnd) return nullptr;

        // create a new node for current root
        TreeNode* root = new TreeNode(preorder[pre]);

        // find root in inorder array
        int mid = -1;
        for (int i = inStart; i <= inEnd; i++)
        {
            if (inorder[i] == preorder[pre])
            {
                mid = i;
                break;
            }
        }

        // build left subtree
        if (mid > inStart)
        {
            pre++;
            root->left = create(preorder, inorder, pre, inStart, mid - 1);
        }

        // build right subtree
        if (mid < inEnd)
        {
            pre++;
            root->right = create(preorder, inorder, pre, mid + 1, inEnd);
        }

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty() || inorder.empty())
            return nullptr;

        int pre = 0;
        return create(preorder, inorder, pre, 0, inorder.size() - 1);
    }
};
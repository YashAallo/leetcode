#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    void dfs(TreeNode *root, TreeNode *p, TreeNode *q, vector<TreeNode*> &parent, vector<TreeNode*> &p_parent, vector<TreeNode*> &q_parent)
    {
        if (!root)
        {
            return;
        }

        parent.push_back(root);

        dfs(root->left, p, q, parent, p_parent, q_parent);
        dfs(root->right, p, q, parent, p_parent, q_parent);

        if (root == p)
        {
            p_parent = parent;
        }
        if (root == q)
        {
            q_parent = parent;
        }

        parent.pop_back();
        return;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode*> parent;
        vector<TreeNode*> p_parent;
        vector<TreeNode*> q_parent;

        dfs(root, p, q, parent, p_parent, q_parent);

        int mini = min(p_parent.size(), q_parent.size());

        int common;
        for (int i = 0; i < mini; i++)
        {
            if (p_parent[i] == q_parent[i])
            {
                common = i;
            }
            else
                break;
        }
        return p_parent[common];
    }
};
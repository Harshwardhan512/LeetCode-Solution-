/**
 * Definition for a binary tree node (already provided by LeetCode).
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        // Queue holds each node with its position index in a "complete" tree
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        unsigned long long maxWidth = 1;

        while (!q.empty()) {
            int levelSize = q.size();
            unsigned long long first = q.front().second;  // leftmost index of this level
            unsigned long long
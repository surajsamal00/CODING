#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        while (curr != nullptr) {
            // Case 1: No left child
            if (!curr->left) {
                res.push_back(curr->val);
                curr = curr->right;
            }
            // Case 2:
            else {
                // Find the right most of left child
                TreeNode* temp = curr->left;
                while (temp->right != nullptr && temp->right != curr) {
                    temp = temp->right;
                }

                // 2a: If no bridge:
                if (temp->right == nullptr) {
                    temp->right = curr;
                    curr = curr->left;
                }
                // 2b: If bridge:
                else {
                    temp->right = nullptr; // break the old bridge
                    res.push_back(curr->val); // process current node inorder and travel right
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};
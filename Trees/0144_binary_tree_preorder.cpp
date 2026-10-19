// LeetCode 144 - Binary Tree Preorder Traversal
// Topic: Trees, DFS, Recursion
// Approach: Root -> Left -> Right
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    void solve(TreeNode* root, vector<int>& ans) {
        // Base case
        if (root == nullptr) {
            return;
        }

        // Step 1: Visit root
        ans.push_back(root->val);

        // Step 2: Traverse left subtree
        solve(root->left, ans);

        // Step 3: Traverse right subtree
        solve(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

int main() {
    // Creating the binary tree
    //       1
    //      / \//
    //     2   3
    //    / \//
    //   4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;
    vector<int> result = obj.preorderTraversal(root);
    cout << "Preorder Traversal: ";
    for (int value : result) {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}
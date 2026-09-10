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
class Pair {
public:
    int first;
    int second;

    Pair(int first, int second) {
        this->first = first;
        this->second = second;
    }
};

class Solution {
    int count = 0;

    Pair postOrder(TreeNode* root) {
        if(root == nullptr) {
            return Pair(0, 0);
        }

        Pair left = postOrder(root->left);
        Pair right = postOrder(root->right);

        int sum = left.first + right.first + root->val;
        int nodeCount = left.second + right.second + 1;

        if(sum / nodeCount == root->val) {
            count++;
        }

        return Pair(sum, nodeCount);
    }

public:
    int averageOfSubtree(TreeNode* root) {
        count = 0;
        postOrder(root);
        return count;
    }
};
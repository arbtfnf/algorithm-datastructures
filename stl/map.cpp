class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        search(root, 1);

        int bestLevel = 1;
        for (const auto &p : sums) {
            // the map sums is iterated in order of levels
            if (p.second > sums[bestLevel]) {
                bestLevel = p.first;
            }
        }
        return bestLevel;
    }
private:
    void search(TreeNode* root, const int level) {
        if (!root) {
            return;
        }

        sums[level] += root->val;
        search(root->left , level+1);
        search(root->right, level+1);
    }

    map<int, int> sums; // level : sum
};
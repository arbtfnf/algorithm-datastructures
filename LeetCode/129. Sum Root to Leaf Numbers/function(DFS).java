/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int sumNumbers(TreeNode root) {
        
        if(root == null) return 0;
 
        return dfs(root, 0);
    }

    int dfs(TreeNode node ,int store) {
        if (node == null) return 0;

        
        int sumParent = store*10 + node.val;

        if (node.left == null && node.right == null){
            return sumParent;
               
        } else {
            return dfs(node.left, sumParent) + dfs(node.right, sumParent);
        }

    }
}

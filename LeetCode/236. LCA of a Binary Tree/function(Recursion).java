/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q) return root;

        TreeNode lNode = lowestCommonAncestor(root.left, p, q);
        TreeNode rNode = lowestCommonAncestor(root.right,p, q);

        if(lNode != null && rNode != null) return root;

        return lNode != null ? lNode : rNode;
        
    }

}

// Time: O(logn) worst case in a skew tree O(n).
// Space: O(logn) stack storage for the recursion worst case O(n).

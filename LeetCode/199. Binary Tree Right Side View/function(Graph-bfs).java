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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        if (root == null) {
            return res;
        }
        
        bfs(root, res);
        return res;

    }

    void bfs(TreeNode root, List<Integer> store) {
        Queue<TreeNode> q = new LinkedList<TreeNode>();

        q.add(root);

        while (!q.isEmpty()) {
            int size = q.size();

            for (int i=0; i<size; i++) {
                TreeNode node = q.poll();

                if(i==0) store.add(node.val);

                if(node.right != null) {
                    q.add(node.right);
                }

                if(node.left != null) {
                    q.add(node.left);
                }
            }

        }
        return;
    }
}

//Time complexity: O(n) -> in bfs we visit each node
//Space complexity: O(m) -> maximum node stored in the queue worst case n/2

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public int _IsBalanced(TreeNode root, ref bool ans) {
        if(root == null) return -1;
        if(root.left == null && root.right == null) return 0;

        var left = _IsBalanced(root.left, ref ans);
        var right = _IsBalanced(root.right,ref ans);

        if(Math.Abs(left-right) > 1)
        {
            ans = false;
        } 
        return Math.Max(left, right) + 1;
    }
    public bool IsBalanced(TreeNode root) {
        if(root == null) return true;
        bool ans = true;
        _IsBalanced(root, ref ans);
        return ans;
    }
}
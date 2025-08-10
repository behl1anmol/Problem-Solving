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
    public bool HasPathSum(TreeNode root, int targetSum) {
        if(root == null) return false;

        //Console.WriteLine($"targetSum:{targetSum} | root:{root.val}");
        bool l=false,r=false;
        if(root.left == null && root.right == null)
        {
            return (targetSum-root.val) == 0;
        }
        if(root.left != null) l = HasPathSum(root.left, targetSum-root.val);
        if(root.right != null) r= HasPathSum(root.right, targetSum-root.val);

        //Console.WriteLine($"targetSum:{targetSum} | root:{root.val} | l:{l} | r:{r}");
        
        //Console.WriteLine($"res = {l||r}");
        return l || r;
    }
}
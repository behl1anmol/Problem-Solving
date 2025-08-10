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
    public int MaxDepth(TreeNode root) {
        var stack = new Stack<KeyValuePair<TreeNode, int>>();
        var maxDepth = 0;
        if (root == null)
            return 0;
        
        stack.Push(new KeyValuePair<TreeNode, int>(root,  1));
        while (stack.Any())
        {
            var top = stack.Pop();
            var node = top.Key;
            var currentDepth = top.Value;
            if (node.left == null && node.right == null)
            {
                maxDepth = Math.Max(maxDepth, currentDepth);
            }
            else
            {
                if (node.left != null)
                {
                    stack.Push(new KeyValuePair<TreeNode, int>(node.left
                                , currentDepth+1));
                }
                if (node.right != null)
                {
                    stack.Push(new KeyValuePair<TreeNode, int>(node.right
                                , currentDepth+1));
                }
            }
        }
        return maxDepth;
    }
}
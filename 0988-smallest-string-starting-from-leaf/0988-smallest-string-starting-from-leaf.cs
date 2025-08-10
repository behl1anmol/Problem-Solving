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
    private readonly List<string> hash = new List<string>()
    {
        "a", "b", "c", "d", "e", "f","g" ,"h", "i",
        "j", "k", "l", "m", "n", "o", "p", "q",
        "r", "s", "t", "u", "v", "w", "x", "y", "z"
    };

    public string SmallestFromLeaf(TreeNode? root)
    {
        var stack = new Stack<KeyValuePair<TreeNode, string>>();
        var smallest = "~";
        if (root == null)
            return "";
        
        stack.Push(new KeyValuePair<TreeNode, string>(root,  hash[root.val]));
        while (stack.Any())
        {
            var top = stack.Pop();
            var node = top.Key;
            var currentPath = top.Value;
            if (node.left == null && node.right == null)
            {
                // Leaf node, check if the current path is smaller
                if (string.Compare(currentPath, smallest, StringComparison.Ordinal) < 0)
                {
                    smallest = currentPath;
                }
            }
            else
            {
                // Traverse left and right children
                if (node.left != null)
                {
                    stack.Push(new KeyValuePair<TreeNode, string>(node.left
                                , hash[node.left.val] + currentPath));
                }
                if (node.right != null)
                {
                    stack.Push(new KeyValuePair<TreeNode, string>(node.right
                                , hash[node.right.val] + currentPath));
                }
            }
            
        }

        return smallest;
    }
}
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
    public void PathSum(TreeNode root, int targetSum, List<IList<int>> ans, List<int> currList, int currSum)
    {
        if (root == null) return;
    
        // Add current node to path
        currList.Add(root.val);
        currSum += root.val;
        
        // Check if we have a valid path to a leaf node
        if (root.left == null && root.right == null && currSum == targetSum)
        {
            // Add a copy of the current path to answers
            ans.Add(new List<int>(currList));
        }
        
        // Continue traversal
        PathSum(root.left, targetSum, ans, currList, currSum);
        PathSum(root.right, targetSum, ans, currList, currSum);
        
        // Backtrack - remove current node from path before returning
        currList.RemoveAt(currList.Count - 1);
    }
    public IList<IList<int>> PathSum(TreeNode root, int targetSum) {
        var ans = new List<IList<int>>();
        var currList = new List<int>();
        PathSum(root, targetSum, ans, currList, 0);
        return ans;
    }
}
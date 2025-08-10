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
    public IList<IList<int>> LevelOrderBottom(TreeNode root) 
    {
        var q = new Queue<TreeNode>();
        var ans = new List<IList<int>>();
        if(root == null) return ans;
        q.Enqueue(root);
        while(q.Any())
        {
            var n = q.Count();
            var lvl = new List<int>(); 
            for(int i=0; i< n; i++)
            {
                var f = q.Dequeue();
                lvl.Add(f.val);
                if(f.left != null) q.Enqueue(f.left);
                if(f.right != null) q.Enqueue(f.right);
            }
            ans.Add(lvl);
        }
        ans.Reverse();
        return ans;   
    }
}
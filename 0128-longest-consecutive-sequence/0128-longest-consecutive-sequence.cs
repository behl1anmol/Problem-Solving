public class Solution {

    class UF{
        private int[] parent;
        private int[] size;

        public UF(int n){
            parent = new int[n];
            size = new int[n];
            for(int i = 0; i< n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        private int Find(int x){
            if(parent[x] == x) return x;
            return parent[x] = Find(parent[x]);
        }

        public void Union(int x, int y){
            int rootX = Find(x);
            int rootY = Find(y);

            if(rootX != rootY){
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            }
        }

        public int LongestComponentLength(){
            int maxSize = 0;
            for(int i=0; i<parent.Length; i++){
                if(parent[i] == i && size[i] > maxSize){
                    maxSize = size[i];
                }
            }
            return maxSize;
        }
    }


    public int LongestConsecutive(int[] nums) {
        UF uf = new UF(nums.Length);
        Dictionary<int,int> dict = new Dictionary<int,int>();

        for(int i=0; i<nums.Length;i++){
            if(dict.ContainsKey(nums[i])) continue;

            if(dict.ContainsKey(nums[i]-1)) uf.Union(i, dict[nums[i]-1]);

            if(dict.ContainsKey(nums[i]+1)) uf.Union(i, dict[nums[i]+1]);

            dict.Add(nums[i], i);
        }
        return uf.LongestComponentLength();
    }
}
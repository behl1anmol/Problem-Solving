public class Solution {
    public int FirstCompleteIndex(int[] arr, int[][] mat) {
        Dictionary<int,KeyValuePair<int,int>> dict = new Dictionary<int,KeyValuePair<int,int>>();
        int row = mat.Length;
        int col = mat[0].Length;
        List<int> cols = Enumerable.Repeat(row, col).ToList();
        List<int> rows = Enumerable.Repeat(col, row).ToList();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                dict[mat[i][j]] = new KeyValuePair<int,int>(i,j);
            }
        }

        for(int i=0;i<arr.Length;i++){
            var idx = dict[arr[i]];
            rows[idx.Key]--;
            cols[idx.Value]--;
            if(rows[idx.Key] == 0 || cols[idx.Value] == 0){
                return i;
            }
        }


        return -1;
    }
}
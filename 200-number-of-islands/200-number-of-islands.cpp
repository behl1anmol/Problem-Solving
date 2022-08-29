class Solution {
public:
    
    pair<int,int> makePair(int i, int j){
        pair<int,int> pr;
        pr.first = i;
        pr.second = j;
        return pr;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        stack<pair<int,int>> st;
        int n = grid.size();
        int m = grid[0].size();
        pair<int,int> pr;       
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]=='1'){
                    grid[i][j] = '-1';
                    st.push(makePair(i,j));
                    ans+=1;
                }
                while(!st.empty()){
                    pair<int,int> top = st.top();
                    st.pop();
                    int a = top.first;
                    int b = top.second;
                    if(b+1<m &&  grid[a][b+1]=='1'){
                        grid[a][b+1] = '0';
                        st.push(makePair(a,b+1));
                    }
                     if(a+1<n && grid[a+1][b]=='1'){
                        grid[a+1][b] = '0';
                        st.push(makePair(a+1,b));
                    }
                    if(a-1>=0 && grid[a-1][b]=='1'){
                        grid[a-1][b] = '0';
                        st.push(makePair(a-1,b));
                    }
                    if(b-1>=0 && grid[a][b-1]=='1'){
                        grid[a][b-1] = '0';
                        st.push(makePair(a,b-1));
                    }
                }
            }
        }
        return ans;
    }
};
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    static bool compare(pair<int,int>p1, pair<int,int>p2){
        return p1.second<p2.second;
    }
    
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> item(n);
        
        for(int i=0;i<n;i++){
            item[i] = pair<int,int>{start[i],end[i]};
        }
        
        sort(item.begin(),item.end(), compare);
        int ans=1;
        
        
        
        for(int i=1,j=0;i<n;i++){
            
            if(item[j].second<item[i].first){
                j=i;
                ans++;
            }
            
        }
        
        return ans;
        /*for(int i=0;i<n;i++){
            cout<<item[i].first<<" "<<item[i].second<<endl;
        }*/
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
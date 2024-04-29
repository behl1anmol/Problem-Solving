class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        cout<<n<<endl;
        int arr[n][n];
        memset(arr,0, sizeof arr);

        for(int i=0;i<n;i++){
            arr[i][i] = 1;
        }

        for(int i=0;i<n;i++){
            char lastAdded = s[i];
            for(int j=i+1;j<n;j++){
               //cout<<j<<" ";
               //cout<<s[j]<<" "<<lastAdded<<" "<<(s[j] - lastAdded)<<endl;
                int isAdded = abs(s[j] - lastAdded);
                //cout<<isAdded<<" ";
                if(isAdded <= k){
                    //cout<<lastAdded<<" ";
                    arr[i][j] = arr[i][j-1]+1;
                    lastAdded = s[j];
                   // cout<<i<<" "<<j<<" "<<lastAdded<<" "<<arr[i][j]<<endl;
                }
                else{
                    arr[i][j] = arr[i][j-1];
                }
            }
        }

        int ans = -1;
        for(int i=0;i<n;i++){
            cout<<arr[i][n-1]<<" ";
            ans = ans<arr[i][n-1]?arr[i][n-1]:ans;
        }

        return ans;

    }
};
class Solution {
public:
        string removeDuplicates(string s) {

        string ans = s;

        int n = ans.size();
        for(int i=0;i<n-1;){
            if(ans[i]==ans[i+1]){
                //cout<<i<<" "<<i+1<<" "<<n<<endl;
                ans.erase(i,1);
                ans.erase(i,1);
                n-=2;
                if(i!=0) i--;
                //cout<<i<<" "<<i+1<<" "<<n<<endl;
            }
            else{
                i++;
            }
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        stack<int> q;
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        for(int i=0;i<n2;i++){
            st.push(nums2[i]);
        }
        
        
        vector<int> ans(n1,-1);
        
        
        for(int i=0;i<n1;i++){
            
            int front = st.top();

            while(front!=nums1[i]){
                q.push(front);
                st.pop();
                front = st.top();

            }

            while(!q.empty()){
                int qf = q.top();
                if(qf>nums1[i] && ans[i]==-1){
                    ans[i] = qf;
                }
                st.push(qf);
                q.pop();
            }
            
            
        }
        return ans;
    }
};
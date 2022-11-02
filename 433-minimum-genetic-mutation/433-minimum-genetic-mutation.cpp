class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        unordered_set<string> st;
        q.push(start);
        st.insert(start);
        
        int ans = 0;
        
        while(!q.empty()){
            int n = q.size();
            
            for(int j=0; j<n; j++){
                string front = q.front();
                q.pop();
                
                if(front == end) return ans;
                    for (char c: "ACGT") {
                    for (int i = 0; i < front.size(); i++) {
                        string neighbor = front;
                        neighbor[i] = c;
                        if (!st.count(neighbor) && find(bank.begin(), bank.end(), neighbor) != bank.end()) {
                            q.push(neighbor);
                            st.insert(neighbor);
                        }
                    }
                }
            }
            ans++;
        }
        
        return -1;
    }
};
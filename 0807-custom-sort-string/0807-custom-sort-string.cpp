class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> mp;
        string ans = "";
        string post = "";
        for(int i = 0; i<s.size(); i++){
            mp[s[i]]++;
        }

        //for (auto i = mp.begin(); i != mp.end(); i++) {
          //  cout<<i->first<<" "<<i->second<<endl;
        //}

        for(int i = 0; i < order.size(); i++){
            char c = order[i];
            if(mp.find(c) != mp.end()){
                //cout<<string(mp[c],c)<<endl;
                ans = ans + string(mp[c], c);
                mp.erase(c);
            }
        }

        for (auto i = mp.begin(); i != mp.end(); i++) {
            ans = ans + string(i->second,i->first);
        }

        return ans;
    }
};
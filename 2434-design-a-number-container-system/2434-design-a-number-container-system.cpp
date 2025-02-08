class NumberContainers {
public:
    map<int, set<int>> mpq;
    map<int,int> mp;
    NumberContainers() {
        
    }

     void change(int index, int number) {
        
        if(mp.find(index) != mp.end())
        {
            int prevNumber = mp[index];
            if(prevNumber == number)
                return;
            if(mpq.find(prevNumber) != mpq.end())
            {
                mpq[prevNumber].erase(index);
                if(mpq[prevNumber].empty()) mpq.erase(prevNumber);
            }
        }
        mp[index] = number;
        mpq[number].insert(index);
    }
    
    int find(int number) {
        if(mpq.find(number) != mpq.end() && !mpq[number].empty())
            return *(mpq[number].begin());
        return -1;
    }
};
    

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
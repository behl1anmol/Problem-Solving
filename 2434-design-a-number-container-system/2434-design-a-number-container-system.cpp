class NumberContainers {
public:
    map<int, int> mapp;
    map<int, set<int>> m;
    NumberContainers() {}
    void change(int i, int num) {
        if (mapp.find(i) != mapp.end()) {
            int o = mapp[i];
            if (o == num)
                return;
            if (m.find(o) != m.end()) {
                m[o].erase(i);
                if (m[o].empty())
                    m.erase(o);
            }
        }
        mapp[i] = num;
        m[num].insert(i);
    }
    int find(int num) {
        if (m.find(num) != m.end() && !m[num].empty())
            return *(m[num].begin());
        return -1;
    }
};
/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
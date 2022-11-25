class LRUCache {
public:
    int capacity;
    list<pair<int,int> > lru;
    unordered_map<int,list<pair<int,int>>::iterator > mp;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        lru.clear();
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){ 
            return -1;
        }
        int val = mp[key]->second;
        lru.erase(mp[key]);
        lru.push_front({key,val});
        mp[key] = lru.begin();
        return val;
    }
    
    void put(int key, int value) {
        //pair<int,int> ins = make_pair(key,value);
        if(mp.find(key)==mp.end()){
            if(lru.size()==capacity){
                pair<int,int> last = lru.back();
                lru.pop_back();
                mp.erase(last.first);
            }
        }
        else{
            lru.erase(mp[key]);
        }
        lru.push_front({key,value});
        mp[key] = lru.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
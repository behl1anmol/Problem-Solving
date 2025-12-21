class LFUCache {

private:
    class Node
    {
        public:
            int key;
            int value;
            int freq;

        Node(int key, int value, int freq)
        {
            this->key = key;
            this->value = value;
            this->freq = freq;
        }
    };
    const int defaultfreq = 1;
    int leastFreq = 1;
    unordered_map<int, list<Node*>> mp;
    unordered_map<int, Node*> hashTable;
    int capacity = 0;



public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(hashTable.find(key)==hashTable.end()){
            return -1;
        }

        //grab the node and its freq
        Node *node = hashTable[key];
        RemapToNewFreq(key);

        return node->value;
    }
    
    void RemapToNewFreq(int key)
    {
         //grab the node and its freq
        Node *node = hashTable[key];
        int oldFreq = node->freq;

        //remove the node from old LRU Cache and insert into new lru cache at the head as it is most recently used
        mp[oldFreq].remove(node);
        node->freq++;
        mp[node->freq].push_front(node);

        //if the least freq list is empty we need to increment the least freq list
        if(mp.find(leastFreq) == mp.end() || mp[leastFreq].size() == 0){
            leastFreq++;
        }
    }

    void put(int key, int value) {
        //if the key is present we update the value and add to new freq LRU
        if(hashTable.find(key) != hashTable.end()){
            hashTable[key]->value = value;
            RemapToNewFreq(key);
        
        }
        //if the key is not present and cache under capacity then add the new key with least freq
        else if(capacity > hashTable.size()){
            Node *node = new Node(key, value, defaultfreq);
            hashTable[key] = node;
            mp[1].push_front(node);
        }
        //if the key is not present and the cache is out of capacity remove the LRU key from the frequency
        else
        {
            Node *node = mp[leastFreq].back();
            mp[leastFreq].pop_back();
            hashTable.erase(node->key);
            Node *newNode = new Node(key, value, defaultfreq);
            hashTable[key] = newNode;
            mp[1].push_front(newNode);
        }

        //if the least freq list is empty we need to increment the least freq list
        if(mp.find(leastFreq) != mp.end() || mp[leastFreq].size() != 0){
            leastFreq = defaultfreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);

1->3
2->1
3->2

2- 3
1-2


 */
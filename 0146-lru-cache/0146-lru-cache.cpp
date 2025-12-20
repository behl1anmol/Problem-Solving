class LRUCache {

private:
    class DoublyLinkedList
    {   
        public:
            pair<int,int> value;
            DoublyLinkedList *previous;
            DoublyLinkedList *next;

        DoublyLinkedList(int key, int value)
        {
            this->value = make_pair(key, value);
            previous = NULL;
            next = NULL;
        }
        DoublyLinkedList(int key, int value, DoublyLinkedList *previous, DoublyLinkedList *next)
        {
            this->value = make_pair(key, value);
            this->previous = previous;
            this->next = next;
        }
    };
    DoublyLinkedList *head;
    unordered_map<int,DoublyLinkedList*> hashTable;
    DoublyLinkedList *tail;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        tail = head;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        if(hashTable.find(key) != hashTable.end())
        {
            RemapToHead(key);
            return hashTable[key]->value.second;
        }
        return -1;
    }
    
    void InsertHead(int key, int value)
    {
        DoublyLinkedList *temp = new DoublyLinkedList(key, value);
        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            head->previous = temp;
            temp->next = head;
            head = temp;
        }

        hashTable[key] = head;
    }

    void DeleteTail()
    {
        DoublyLinkedList *d = tail;
        if(tail == head) head = NULL;
        int key = d->value.first;
        if(tail->previous!=NULL)
        {
            tail->previous->next = NULL;
        }
        tail = tail->previous;
        d->previous = NULL;

        delete d;
        cout<<"key to delete:"<<key<<endl;
        hashTable.erase(key);
    }

    void RemapToHead(int key)
    {
        DoublyLinkedList *node = hashTable[key];
        if(node->next == NULL & node->previous == NULL) return;

        node->previous->next = node->next;
        if(node->next != NULL)
        {
            node->next->previous = node->previous;
        }
        else
        {
            tail = node->previous;
        }
        node->previous = NULL;

        InsertHead(node->value.first, node->value.second);
        delete node;

    }

    void put(int key, int value) {
        //update the value of key if exists
        if(hashTable.find(key) != hashTable.end())
        {
            hashTable[key]->value.second = value;
            RemapToHead(key);
            Print();
            return;
        }

        //add key value to cache if less than capacity
        if(capacity > hashTable.size())
        {
            InsertHead(key,value);
            Print();
            return;
        }

        //if capacity is less than size then delete the tail of LL and remove from hashTable
        //insert the new node to head
        if(capacity <= hashTable.size())
        {
            DeleteTail();
            cout<<hashTable.size()<<endl;
            InsertHead(key, value);
        }
        Print();

    }

    void Print()
    {
        DoublyLinkedList *temp = head;

        cout<<hashTable.size()<<endl;
        while(temp!= NULL)
        {
            cout<<temp->value.first<<" "<<temp->value.second<<endl;
            temp = temp->next;
        }

        for (const auto& pair : hashTable) {
            cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
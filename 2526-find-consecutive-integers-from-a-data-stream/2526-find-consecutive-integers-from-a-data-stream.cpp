class DataStream {
private:
    int value = 0;
    int k = 0;
    int count;
public:
    DataStream(int value, int k) : value(value),k(k),count(0) {
        
    }
    
    bool consec(int num) {
        if(num == value)
            count++;
        else
            count = 0;
        return count>=k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
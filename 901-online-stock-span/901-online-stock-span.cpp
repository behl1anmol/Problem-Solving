class StockSpanner {
public:
    unordered_map<int,int> cache;
    vector<int> stock;
    int sz;
    StockSpanner() {
        sz= 0;
    }
    
    int next(int price) {
        stock.push_back(price);
        sz = stock.size();
        int span = 1;
        if(sz==1){
            cache[price] = span;
            return span;
        }


        //if more than one stock
        for(int i=sz-2;i>=0;i--){
            if(stock[i] > price) break;
            else{
                span += cache[stock[i]];
                i -= (cache[stock[i]]-1);
                //cout<<i<<endl;
            }
        }
        cache[price] = span;
        return span;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
class MyCalendar {
public:
    vector<vector<int>> lastBookedEvents;
    MyCalendar() {
        lastBookedEvents.push_back({0,0});
    }
    
    bool book(int start, int end) {

                
        for(int i=0;i<lastBookedEvents.size();i++)
            if(lastBookedEvents[i][0]<end && start<lastBookedEvents[i][1]) return false;        
        lastBookedEvents.push_back({start,end});
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
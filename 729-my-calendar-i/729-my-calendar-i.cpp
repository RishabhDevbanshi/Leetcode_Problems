class MyCalendar {
    vector<pair<int,int>> cal;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto &[s,e] : cal)
        {
            if((s<=start and start<e) || (s<end and end<=e))
                return false;
            if((start<=s and s<end) || (start<e and e<=end))
                return false;
        }
        cal.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
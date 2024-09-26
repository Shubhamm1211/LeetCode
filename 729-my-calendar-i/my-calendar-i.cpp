class MyCalendar {
public:
    vector<pair<int, int>>temp;
    MyCalendar() {

    }
    bool book(int start, int end) {
        for(auto x:temp){
            if(x.first < end and x.second > start){
                return false;
            }
        }
        temp.push_back({start,end});
        return true;
    }
};
class MyCalendarTwo {
    map<int , int> mp;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        int sum = 0;
        mp[start]++;
        mp[end]--;
        for(auto it : mp){
            sum += it.second;
            if(sum > 2){
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true ; 
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
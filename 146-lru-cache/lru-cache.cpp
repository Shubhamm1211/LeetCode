class LRUCache {
public:
    int n;
    list <int> dll;
    map <int,pair< list<int> :: iterator, int >> mp;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        else{
            dll.erase(mp[key].first);
            dll.push_front(key);
            mp[key].first = dll.begin();
            return mp[key].second;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            dll.erase(mp[key].first);
            dll.push_front(key);
            mp[key].first = dll.begin();
        }
        else{
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }
        if(n < 0){
            int delkey = dll.back();
            mp.erase(delkey);
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
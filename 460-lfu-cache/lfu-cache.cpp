class LFUCache {
public:
    int cap;
    int size;
    unordered_map<int, list<vector<int>>::iterator> mp; // {key -> add}
    map <int, list<vector<int>>> freq; // {counter -> {key,val,counter}} ;
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    void help(int key){
        auto &vec = *(mp[key]);
        int f = vec[2];
        int val = vec[1];
        freq[f].erase(mp[key]);
        if(freq[f].empty()) freq.erase(f);
        f++;
        freq[f].push_front({key,val,f});
        mp[key] = freq[f].begin();
    }
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        else{
            auto &vec = (*(mp[key]));
            int ans = vec[1];
            help(key);
            return ans;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            auto &vec = (*(mp[key]));
            vec[1] = value;
            help(key);
        }
        else{
            if(size < cap){
                size++;
                freq[1].push_front({key,value,1});
                mp[key] = freq[1].begin();
            }
            else{
                auto &firstList = freq.begin() -> second;
                int keyDel = (firstList.back())[0];
                firstList.pop_back();
                if(firstList.empty()) freq.erase(freq.begin() -> first);
                freq[1].push_front({key,value,1});
                mp.erase(keyDel);
                mp[key] = freq[1].begin();
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


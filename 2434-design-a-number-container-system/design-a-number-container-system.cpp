class NumberContainers {
public:
    map<int, int> mp1;  // {ind, num}
    map<int, set<int>> mp2;  // {num, <ind>}
    
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if (mp1.find(index) != mp1.end()) {
            int old = mp1[index];
            mp2[old].erase(index);
            if (mp2[old].empty()) {
                mp2.erase(old);
            }
        }
        
        mp1[index] = number;
        mp2[number].insert(index);
    }
    
    int find(int number) {
        if (mp2.find(number) == mp2.end() or mp2[number].empty()) {
            return -1;
        }
        return *mp2[number].begin();
    }
};
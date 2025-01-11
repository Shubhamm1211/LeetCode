class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp ={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            char curr = s[i];
            char next = s[i + 1];
            if(mp[curr] < mp[next]){
                ans += mp[next] - mp[curr];
                i++;
            }
            else{
                ans += mp[curr];
            }
        }
        return ans;
    }
};
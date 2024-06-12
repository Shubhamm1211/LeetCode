class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char,int> mp;
        for(int i = 0;i<chars.size();i++)
            mp[chars[i]] = vals[i];
        vector<int> temp;
        for(char c : s){
            if(mp.find(c) != mp.end())
                temp.push_back(mp[c]); 
            else
                temp.push_back(c - 'a' + 1);
        }
        int ans = 0;
        int curr = 0;
        int n = temp.size();
        for(int i = 0;i<n;i++){
            curr = max(temp[i],curr + temp[i]);
            ans = max(ans,curr);
        }

        return ans;
    }
};
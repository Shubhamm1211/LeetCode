class Solution {
public:
    vector<int> queryResults(int l, vector<vector<int>>& q) {
        // vector <int> vis(l + 1,0);
        vector <int> ans;
        unordered_map <int,int> mp;
        unordered_map <int,int> freq;
        for(int i = 0; i < q.size(); i++){
            int ball = q[i][0];
            int c = q[i][1];
            if(mp.count(ball) != 0){
                freq[mp[ball]]--;
                if(freq[mp[ball]] == 0) freq.erase(mp[ball]);
                freq[c]++;
            }
            else{
                // vis[ball] = 1;
                freq[c]++;
            }
            mp[ball] = c;
            ans.push_back(freq.size());
        }
        mp.clear();
        freq.clear();
        return ans;
    }
};
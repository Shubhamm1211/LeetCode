class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        int k = n;
        vector <pair<int,int>> v;
        for(int i = 0; i < nums.size(); i++){
            for(auto x : nums[i]){
                v.push_back({x,i + 1});
            }
        }
        sort(begin(v),end(v));
        vector <int> seq;
        for(int i = 0; i < v.size(); i++){
            seq.push_back(v[i].second);
        }
        unordered_map <int,int> mp;
        vector<int> ans;
        int i = 0, j = 0;
        int mini = INT_MAX;
        while(j < seq.size()){
            mp[seq[j]]++;
            while(mp.size() == k){
                int range = v[j].first - v[i].first;
                cout << v[i].first << " " << v[j].first << " Range = " << range << endl;
                if(range < mini){
                    ans.clear();
                    ans.push_back(v[i].first);
                    ans.push_back(v[j].first);
                    mini = range;
                }
                mp[seq[i]]--;
                if(mp[seq[i]] == 0) mp.erase(seq[i]);
                i++;
            }
            j++;
        }
        cout << mini << endl;
        return ans;
    }
};

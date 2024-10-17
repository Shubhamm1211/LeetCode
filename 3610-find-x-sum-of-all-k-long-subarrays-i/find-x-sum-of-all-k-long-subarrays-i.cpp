class Solution {
public:
    int xsum(vector<int> &temp, int x){
        set <int> st(temp.begin(),temp.end());
         if(st.size() < x){
            int t = accumulate(begin(temp),end(temp),0);
            return t;
        }
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i = 0; i < temp.size(); i++){
            mp[temp[i]]++;
        }
        priority_queue <pair<int,int>> pq;
        for(auto x: mp){
            pq.push({x.second,x.first});
        }
        while(x > 0){
            int f = pq.top().first;
            int ele = pq.top().second;
            ans += (f * ele);
            pq.pop();
            x--;
        }
        return ans;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector <int> ans;
        // set <int> st(nums.begin(),nums.end());
        // if(st.size() < x){
        //     int t = accumulate(begin(nums),end(nums),0);
        //     return {t};
        // }
        for(int i = 0; i <= n - k; i++){
            vector <int> temp; 
            for(int j = i; j < i + k; j++){
                temp.push_back(nums[j]);
            }
            int t = xsum(temp,x);
            ans.push_back(t);
        }
        return ans;
    }
};
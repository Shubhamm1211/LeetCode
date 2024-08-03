class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        unordered_map<int,int> mp ;
        int n = arr.size() ; 
        for (int i = 0 ; i < n ; i++){
            mp[arr[i]]++;
        }
        sort(arr.begin(), arr.end() ) ; 
        vector<int>ans;
        for(int i = 0 ; i < n ; i++){
            int num = arr[i] ;
            if(mp[num]==0) continue ;
            else if(mp[num*2] == 0 ){
                return {};
            }
            ans.push_back(num);
            mp[num]--;
            mp[num*2]--;
        }
        if(ans.size() != arr.size()/2) return {};
        return ans;
    }
};
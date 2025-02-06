// class Solution {
// public:
//     int tupleSameProduct(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,vector<vector<int>>> mp;
//         for(int i = 0; i < n; i++){
//             for(int j = i + 1; j < n; j++){
//                 int pro = nums[i] * nums[j];
//                 mp[pro].push_back({nums[i],nums[j],0});
//             }
//         }
//         int ans = 0;
//         for(int i = 0; i < n; i++){
//             for(int j = i + 1; j < n; j++){
//                 if(mp.find(nums[i] * nums[j]) != mp.end()){
//                     for(int k = 0; k < mp[nums[i] * nums[j]].size(); k++){
//                         vector <int> temp = mp[nums[i] * nums[j]][k];
//                         if(temp[0] != nums[i] and temp[1] != nums[j] and !temp[2]){
//                             ans += 4;
//                             temp[2] = 1;
//                         }
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int pro = nums[i] * nums[j];
                mp[pro]++;
            }
        }
        for (auto& it : mp) {
            int freq = it.second;
            if (freq > 1) {
                ans += (freq * (freq - 1) / 2) * 8; 
            }
        }

        return ans;
    }
};

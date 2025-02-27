class Solution {
public:
    map <int,int> mp;
    int solve(int j, int k, vector <int> &arr){
        int tar = arr[k] - arr[j];
        if(mp.find(tar) != mp.end()){
            if(mp[tar] < j){
                return 1 + solve(mp[tar],j,arr);
            }
        }
        return 2;

    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0;
        for(int i = 0; i < n; i++){
            mp[arr[i]] = i;
        }
        for(int j = 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int temp = solve(j,k,arr);
                if(temp >= 3){
                    maxi = max(maxi,temp);
                }
            }
        }
        return maxi;
    }
};
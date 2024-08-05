class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mp;
        int n = arr.size() ;
        for(int i=0 ; i<n ; i++){
            mp[arr[i]]++;
        }
        vector<string>single;
        for(int i=0;i<n;i++){
            if(mp[arr[i]]==1){
                single.push_back(arr[i]);
            }
        }
        if(k>single.size())return "";
        return single[k-1];
    }
};
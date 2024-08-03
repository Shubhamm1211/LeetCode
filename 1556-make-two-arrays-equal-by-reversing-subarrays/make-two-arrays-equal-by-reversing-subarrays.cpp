class Solution {
public:
    bool canBeEqual(vector<int>& tar, vector<int>& arr) {
        sort(tar.begin(),tar.end());
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(tar[i]!=arr[i])return false;
        }
        return true;
    }
};
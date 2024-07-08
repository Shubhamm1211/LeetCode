class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int t) {
        vector<vector<int>>ans;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(i>0 and arr[i-1]==arr[i])continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 and arr[j-1]==arr[j])continue;
                int l=j+1;
                int k=n-1;
                while(l<k){
                    long long int sum=arr[i];
                    sum+=arr[j];
                    sum+=arr[k];
                    sum+=arr[l];
                    if(sum==t){
                        vector<int>v={arr[i],arr[j],arr[l],arr[k]};
                        ans.push_back(v);
                        l++;
                        k--;
                        while(l<k and arr[l]==arr[l-1])l++;
                        while(l<k and arr[k]==arr[k+1])k--;
                    }
                    else if(sum>t){
                        k--;
                    }
                    else l++;
                }
            }
        }
        return ans;
    }
};
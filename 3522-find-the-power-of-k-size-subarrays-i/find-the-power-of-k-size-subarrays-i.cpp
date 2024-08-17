class Solution {
public:
    bool checksort(vector<int>temp){
        for(int i=0;i<temp.size()-1;i++){
            if(temp[i]>temp[i+1])return false;
        }
        return true;
    }
    bool checkcons(vector<int>temp){
        if(checksort(temp)==false)return false;
        else{
            int diff=temp.back()-temp[0];
            if(temp.size()-1==diff)return true;
            else return false;
        }
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        // if(k==1)return nums;
        vector<int>ans;
        for(int i=0;i<=n-k;i++){
            vector<int>temp;
            bool f=true;
            for(int j=i;j<i+k;j++){
                if(!temp.empty() and temp.back()+1!=nums[j]) f=false;
                else temp.push_back(nums[j]);
            }
            for(auto x:temp)cout<<x<<" ";
            cout<<endl;
            if(f){
                ans.push_back(temp.back());
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};
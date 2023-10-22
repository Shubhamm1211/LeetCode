class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.begin(),tasks.end(),greater<int>());
        vector<int> a;
        for(int j=0;j<processorTime.size();j++){
            for(int i=0;i<4;i++){
                a.push_back(processorTime[j]);
            }
        }
        int ans=0;
        for(int i=0;i<tasks.size();i++){
            ans=max(ans,a[i]+tasks[i]);
        }
        return ans;
    }
};
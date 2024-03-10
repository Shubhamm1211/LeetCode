class Solution {
public:
    int ls(int k,vector<int>arr){
        for(int i=0;i<arr.size();i++){
            if(arr[i]==k)return i;
        }
        return -1;
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int>pq;
        for(auto x:score){
            pq.push(x);
        }
        int i=1;
        vector<int>ans(score.size(),-1);
        while(!pq.empty()){
            int t=pq.top();
            pq.pop();
            int ind=ls(t,score);
            ans[ind]=i;
            i++;
        }
        vector<string>ret(ans.size(),"");
        for(int i=0;i<ans.size();i++){
            if(ans[i]==1)ret[i]="Gold Medal";
            else if(ans[i]==2)ret[i]="Silver Medal";
            else if(ans[i]==3)ret[i]="Bronze Medal";
            else ret[i]=to_string(ans[i]);
        }
        return ret;
    }
};
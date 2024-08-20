class Solution {
public:
    int stoneGameVI(vector<int>& av, vector<int>& bv) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<av.size();i++){
            pq.push({av[i]+bv[i],i});
        }
        bool f=true;
        int as=0,bs=0;
        while(!pq.empty()){
            int ind=pq.top().second;
            pq.pop();
            if(f){
                as+=av[ind];
            }
            else bs+=bv[ind];
            f=!f;
        }
        if(as>bs)return 1;
        else if(as<bs)return -1;
        return 0;
    }
};
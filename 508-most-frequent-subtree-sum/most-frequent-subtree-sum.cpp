class Solution {
public:
    unordered_map<int,int>mp;
    int solve(TreeNode*root,int &maxfreq){
        if(root==NULL)return 0;
        int lsum=solve(root->left,maxfreq);
        int rsum=solve(root->right,maxfreq);
        int s=lsum+rsum+root->val;
        mp[s]++;
        maxfreq=max(maxfreq,mp[s]);
        return s;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int maxfreq = 0;
        solve(root,maxfreq);
        vector<int>res;
        for(auto x:mp){
            if(x.second == maxfreq){
                res.push_back(x.first);
            }
        }
        return res;
    }
};
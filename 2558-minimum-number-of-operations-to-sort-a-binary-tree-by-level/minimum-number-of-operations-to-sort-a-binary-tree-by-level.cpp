/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> arr;
            int s = q.size();
            for(int i = 0; i < s; i++){
                TreeNode *temp = q.front();
                q.pop();
                arr.push_back(temp -> val);
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
            v.push_back(arr);
        }
        int ans = 0;
        for(auto vec : v){
            map<int,int> mp;
            vector <int> s(begin(vec), end(vec));
            sort(begin(s), end(s));
            for(int i = 0; i < vec.size(); i++){
                mp[vec[i]] = i;
            }
            int cnt = 0;
            for(int i = 0; i < vec.size(); i++){
                if(s[i] != vec[i]){
                    int prev = vec[i];
                    int ind = mp[s[i]];
                    cout << "Swapping : " << vec[i] << " and " << vec[mp[s[i]]] << endl;
                    swap(vec[i],vec[mp[s[i]]]);
                    cnt++;
                    mp[s[i]] = i;
                    mp[prev] = ind;
                }
            }
            ans += cnt;
        }
        return ans;
    }
};
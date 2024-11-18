class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector <int> ans;
        if(k >= 0){
            for(int i = 0; i < n; i++){
                int sum = 0;
                for(int j = i + 1; j <= i + k; j++){
                    sum += code[j%n];
                }
                ans.push_back(sum);
            }
        }
        else{
            reverse(begin(code), end(code));
            k = k * -1;
            cout << "k = " << k <<endl;
            for(int i = 0; i < n; i++){
                int sum = 0;
                for(int j = i + 1; j <= i + k; j++){
                    sum += code[j%n];
                }
                ans.push_back(sum);
            }
            reverse(begin(ans), end(ans));
        }
        return ans;
    }
};
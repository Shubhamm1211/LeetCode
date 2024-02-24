class Solution {
public:
    int rev(int n){
        string s= to_string(n);
        reverse(s.begin(),s.end());
        int r=stoi(s);
        return r;
    }
    bool sumOfNumberAndReverse(int num) {
        if(num==0)return true;
        for(int i=1;i<=num;i++){
            if(i+rev(i)==num)return true;
        }
        return false;
    }
};
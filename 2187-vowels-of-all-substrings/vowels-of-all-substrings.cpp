#define ll long long
class Solution {
public:
    bool isvowel(char c){
        if(c=='a' ||c=='e' ||c=='i' ||c=='o' ||c=='u' )return true;
        return false;
    }

    
    long long countVowels(string word) {
        ll n=word.size(),ans=0;
        for(int i=0;i<n;i++){
            if(isvowel(word[i])){
                ll left=n-i;
                ll right=i+1;
                ans=ans+(left*right);
            }
        }
        return ans;
    }
};
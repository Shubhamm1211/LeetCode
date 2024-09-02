class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        int n1=c1[0]-'a';
        int n2=c1[1]-'0';
        int m1=c2[0]-'a';
        int m2=c2[1]-'0';
        string col1,col2;
        if(n1%2==n2%2){
            col1="w";
        }
        else col1="b";
        if(m1%2==m2%2){
            col2="w";
        }
        else col2="b";
        if(col1==col2)return true;
        else return false;
    }
};
class Solution {
public:
    string findLatestTime(string s) {
        char h1=s[0];
        char h2=s[1];
        char m1=s[3];
        char m2=s[4];
        if(h1=='?' && h2=='?'){
            h1='1';
            h2='1';
        }
        else if(h1=='?' && h2!='?'){
            int ih2=h2;
            if(h2!='0' && h2!='1' )h1='0';
            else h1='1';
        }
        else if(h1!='?' && h2=='?'){
            int ih1=(int)h1;
            if(h1=='0')h2='9';
            else h2='1';
        }
        if(m1=='?' && m2=='?'){
            m1='5';
            m2='9';
        }
        else if(m1=='?' && m2!='?'){
            m1='5';
        }
        else if(m1!='?' && m2=='?'){
            m2='9';
        }
        s[0] = h1;
        s[1] = h2;
        s[3] = m1;
        s[4] = m2;
        return s;
    }
};
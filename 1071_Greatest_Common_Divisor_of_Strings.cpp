// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/greatest-common-divisor-of-strings

// @1st approch (Unoptimized approch)
class Solution {
public:
    string buildString(string s,int k){
        string temp="";
        for(int i=0;i<k;i++){
            temp+=s;
        }
        return temp;
    }

    string gcdOfStrings(string str1, string str2) {
        int n1=str1.size();
        int n2=str2.size();

        for(int i=min(n1,n2);i>=1;i--){

            if(n1%i !=0 || n2%i !=0) continue;
            int k1=n1/i,k2=n2/i;

            string base=str1.substr(0,i);
            string s1= buildString(base,k1);
            string s2= buildString(base,k2); 

            if(s1==str1 && s2==str2) return base;

        }
        return "";
    }
};

// @Optimized approch using gcd calculation
class Solution {
public:
    int gcd(int a,int b){
        while(b != 0){
            int temp=a%b;
            a=b;
            b=temp;
        }
        return a;
    }

    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 != str2+str1) return "";

        return str1.substr(0,gcd(str1.size(),str2.size()));
    }
};

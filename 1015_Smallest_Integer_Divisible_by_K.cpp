// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/smallest-integer-divisible-by-k/?envType=problem-list-v2&envId=maths-m2-divisibility-modular-arithmetic

class Solution {
public:
    int smallestRepunitDivByK(int k) {
    	map<int,bool>mp;
        
        int length=0,rem=0;
        while(true){
        	length++;
            int n=rem*10+1;
            if(n%k==0) return length;
            
            rem=n%k;
            if(mp[rem]) return -1;
            mp[rem]=true;
        }
        return -1;
    }
};

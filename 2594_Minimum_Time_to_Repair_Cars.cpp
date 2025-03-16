// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/minimum-time-to-repair-cars

typedef long long ll;

class Solution {
public:
    bool isPossible(vector<int>&ranks,int cars,ll time){
        ll count=0;
      
        for(int i=0;i<ranks.size();i++){
            count+=(ll)sqrt(time/(ll)ranks[i]);
        }
        return count>=cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
      
        ll l=0;
        ll h=*min_element(ranks.begin(),ranks.end())*1LL*cars*cars;

        while(l<=h){
            ll mid=l+(h-l)/2;
          
            if(isPossible(ranks,cars,mid)){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ++h;
    }
};

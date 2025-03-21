// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies

// @1st approch using recursive dfs to check if recipe possible or not
class Solution {
public:
    bool dfs(vector<vector<string>>& ingredients,unordered_map<string,bool>&canCook,unordered_map<string,int>&indexes,string recipe){
        if(canCook.find(recipe) != canCook.end()) return canCook[recipe];
        if(indexes.find(recipe)==indexes.end()) return false;
        
        canCook[recipe]=false;

        for(auto &adj : ingredients[indexes[recipe]]){
            if(!dfs( ingredients,canCook,indexes,adj)){
                return false;
            }
        }
        return canCook[recipe]=true;
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,bool>canCook;
        unordered_map<string,int>indexes;

        vector<string>ans;

        for(int i=0;i<supplies.size();i++){
            canCook[supplies[i]]=true;
        }

        for(int i=0;i<recipes.size();i++){
            indexes[recipes[i]]=i;
        }

        for(int i=0;i<recipes.size();i++){
            if(dfs(ingredients,canCook,indexes,recipes[i])) ans.push_back(recipes[i]);
        }
        return ans;

    }
};

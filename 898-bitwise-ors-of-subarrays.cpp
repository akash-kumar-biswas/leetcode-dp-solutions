class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> dp;
        unordered_set<int> curr;
        unordered_set<int> ans;

        for(auto num: arr){
            for(auto calculated_or: dp){
                curr.insert(calculated_or | num);
                ans.insert(calculated_or | num);

            }
            curr.insert(num);
            ans.insert(num);
            dp = curr;
            curr.clear();
        }
        return ans.size();
    }
};
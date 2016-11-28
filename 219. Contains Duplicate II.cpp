class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> myDict;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(myDict.find(nums[i]) == myDict.end() || i - myDict[nums[i]] > k){
                myDict[nums[i]] = i;
            } else {
                return true;
            }
        }
        return false;
    }
};
/* *********************************************************************************
 *          Annie Wang 2016.11.18                                                  *
 *                                                                                 *
 * Idea: simple question                                                           *
 * Remark: map, map.find, map.end()                                                *
 *                                                                                 *
 * *********************************************************************************

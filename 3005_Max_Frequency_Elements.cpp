//better approach but has scope of optimizing it in single loop
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> count;
        int max=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]+=1;
            if(count[nums[i]]>max) { max=count[nums[i]]; }
        }
        for (auto it : count) {
            if (it.second == max) {
                ans += it.second;
            }
        }
       
        return ans;
    }
};



//optimized code


class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> count;
        int max=0;
        int ans=0;

        for(int num:nums){
           count[num] += 1;
           int freq=max;
            if(count[num]>max) max=count[num];
            if(count[num]==max){
                if(max!=freq) ans=count[num];
                else ans+=count[num];
            }
        }
       
        return ans;
    }
};

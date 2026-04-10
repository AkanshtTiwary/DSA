class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
        m[nums[i]].push_back(i);
        }
         int minm=INT_MAX;
        for(auto &it : m) {
            vector<int> &v = it.second;
            if(v.size() >= 3) {
                for(int i = 0; i + 2 < v.size(); i++) {
                    int a = v[i], b = v[i+1], c = v[i+2];
                    int sum = abs(a-b) + abs(b-c) + abs(c-a);
                    minm = min(minm, sum);
                }
            }
        }
        if(minm==INT_MAX)
        return -1;
        else return minm;
    }
};
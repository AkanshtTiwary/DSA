#include <memory_resource>
pmr::unsynchronized_pool_resource pool;
class Solution {
public:
    static vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        const int n=nums.size(), qz=queries.size();
        vector<int> ans(qz, -1);
        
       
        pmr::unordered_map<int, vector<int>> x2i(&pool);
        x2i.reserve(n);   
        for (int i=0; i<n; i++) 
            x2i[nums[i]].push_back(i);

        for (int i=0; i<qz; i++) {
            const int q=queries[i], x=nums[q];
            auto& idx=x2i[x];
            const int sz=idx.size();

            if (sz==1) continue;

  
            auto i0=lower_bound(idx.begin(), idx.end(), q)-idx.begin();

            int d=n-1, j0=idx[i0];  
          
            if (i0+1!=sz) d=min(d, idx[i0+1]-j0);
            else d=min(d, n+idx[0]-j0);  

            if (i0!=0) d=min(d, j0-idx[i0-1]);
            else d=min(d, n+j0-idx.back()); 
            ans[i]=d;
        }
        return ans;
    }
};

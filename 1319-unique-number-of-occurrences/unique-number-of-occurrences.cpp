class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int, int> frq;

        for(int num : arr){
            frq[num]++;
        }

        unordered_set<int> st;

        for(auto &p : frq){
            if(st.count(p.second)){
                return false;
            }
            st.insert(p.second);
        }

        return true;
    }
};
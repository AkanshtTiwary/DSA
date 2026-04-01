class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<vector<int>> robots;
        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(robots.begin(), robots.end());

        stack<int> st; 

        for (int i = 0; i < n; i++) {
            if (robots[i][2] == 'R') {
                st.push(i);
            } else {
                while (!st.empty() && robots[i][1] > 0) {
                    int j = st.top(); 

                    if (robots[j][1] < robots[i][1]) {
                        robots[i][1]--;
                        robots[j][1] = 0;
                        st.pop();
                    } 
                    else if (robots[j][1] > robots[i][1]) {
                        robots[j][1]--;
                        robots[i][1] = 0;
                    } 
                    else {
                        robots[j][1] = 0;
                        robots[i][1] = 0;
                        st.pop();
                    }
                }
            }
        }

        vector<int> ansByIndex(n, 0);
        for (int i = 0; i < n; i++) {
            if (robots[i][1] > 0) {
                ansByIndex[robots[i][3]] = robots[i][1];
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (ansByIndex[i] > 0) {
                ans.push_back(ansByIndex[i]);
            }
        }

        return ans;
    }
};
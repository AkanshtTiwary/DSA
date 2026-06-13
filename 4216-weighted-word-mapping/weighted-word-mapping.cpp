class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s;

        for (string& word : words) {
            int idx = 0;

            for (char& c : word) {
                idx += weights[c - 'a'];
            }

            idx %= 26;
            s.push_back('a' + (25 - idx));
        }

        return s;
    }
};
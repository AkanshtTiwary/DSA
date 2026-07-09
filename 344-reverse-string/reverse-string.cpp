class Solution {
public:
    void reverse(vector<char>& s, int start, int end){
        if(start>=end) return;
        swap(s[start], s[end]);
        reverse(s, ++start,--end);
    }
    void reverseString(vector<char>& s) {
        int n = s.size();
        reverse(s, 0, n-1);
        
    }
};
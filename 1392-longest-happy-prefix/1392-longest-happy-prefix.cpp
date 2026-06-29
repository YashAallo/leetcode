class Solution {
public:
    string longestPrefix(string s) {

        int n = s.size();

        vector<int> lps(n, 0);
        // vector<string> ans(n,"");

        int l = 0;
        int i = 1;

        while (i < n) {
            if (s[i] == s[l]) {
                l++;
                lps[i] = l;
                i++;
            } else {
                if (l != 0) {
                    l = lps[l - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        string ans;
        for (int i = 0; i < lps[n - 1]; i++) {
            ans.push_back(s[i]);
        }

        return ans;
    }
};
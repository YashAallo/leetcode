class Solution {
public:
    bool ismatch(string &s, string &t) {
    int n = s.size(), m = t.size();

    for (int start = 0; start + n <= m; start++) {
        int k = 0;
        while (k < n && s[k] == t[start + k])
            k++;

        if (k == n)
            return true;
    }

    return false;
}
    int numOfStrings(vector<string>& patterns, string word) {

        int count = 0;
        for (auto str : patterns) {
            if (ismatch(str, word))
                count++;
        }

        return count;
    }
};
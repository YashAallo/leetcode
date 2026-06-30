class Solution {
public:
    bool present(int freq[]) { return freq[0] && freq[1] && freq[2]; }

    int numberOfSubstrings(string s) {

        int freq[3] = {0};
        int n = s.size();

        int l = 0;
        int r = -1;

        int count = 0;

        while (true) {
            if (present(freq)) {
                count += (n - r);
                freq[s[l] - 'a']--;
                l++;
            } else {
                if (r == n - 1)
                    break; // no more characters to add
                r++;
                freq[s[r] - 'a']++;
            }
        }
        return count;
    }
};
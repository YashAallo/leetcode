class Solution {
public:
    bool isChain(string& s, string& t) {

    if (t.size() != s.size() + 1)
        return false;

    int i = 0, j = 0;

    while (i < s.size() && j < t.size()) {

        if (s[i] == t[j]) {
            i++;
            j++;
        } else {
            j++;   // skip one character in t
        }
    }

    return i == s.size();
}

    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(),
             [](auto a, auto b) { return a.size() < b.size(); });



        int n=words.size();

        int maxi=1;

        vector<int> dp(n,1);

        for(int i=0;i<n;i++)
        {

            for(int j=0;j<i;j++)
            {

                if( isChain(words[j],words[i])  && dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }   

        return maxi;  
    }
};
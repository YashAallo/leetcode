class Solution {
public:
    int strStr(string haystack, string needle) {

        for (int j = 0; j < haystack.size(); j++) {

            if (haystack[j] == needle[0]) {

                if (j + needle.size() > haystack.size())
                    break;

                int i = 0;

                for (; i < needle.size(); i++) {
                    if (haystack[j + i] != needle[i])
                        break;
                }

                if (i == needle.size())
                    return j;
            }
        }

        return -1;
    }
};
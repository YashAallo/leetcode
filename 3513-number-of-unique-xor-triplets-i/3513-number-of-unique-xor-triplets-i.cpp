class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        int n = nums.size();

        if (n <= 2)
            return n;

        int msb = 0;

        while (n) {
            msb += 1;
            n=n >> 1;
        }
        return pow(2,msb );
    }
};
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();
        int l = n - 1;
        int carry = 1;
        while (l >= 0) {
            if (digits[l] + carry > 9) {

                digits[l] = 0;
                l--;
            } else {
                carry = 0;
                digits[l] += (1 + carry);
                break;
            }
        }

        if (carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }

};
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int i = digits.size() - 1;
        int carry = 1;
        
        while(carry == 1 && i >= 0) {
            digits[i] += carry;
            carry--;
            
            if(digits[i] == 10) {
                digits[i] = 0;
                carry = 1;
            }
            i--;
        }
        
        if (carry == 1) {
            digits.insert(begin(digits), 1, carry);
        }
        
        return digits;
        
    }
};
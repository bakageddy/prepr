class Solution {
public:
    int sum_of_digits(int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    int addDigits(int num) {
        if (num < 10) return num;
        return addDigits(sum_of_digits(num));
    }
};

pub struct Solution;

#[allow(dead_code)]
impl Solution {
    #[inline]
    pub fn char_to_int(c: u8) -> i32 {
        match c {
            b'I' | b'i' => 1,
            b'V' | b'v' => 5,
            b'X' | b'x' => 10,
            b'L' | b'l' => 50,
            b'C' | b'c' => 100,
            b'D' | b'd' => 500,
            b'M' | b'm' => 1000,
            _ => unreachable!("wow wow"),
        }
    }
    pub fn roman_to_int(s: String) -> i32 {
        let mut num = 0;
        let s = s.as_bytes();
        for i in 0..s.len() {
            if let Some(&curr) = s.get(i)
                && let Some(&next) = s.get(i + 1)
            {
                if Solution::char_to_int(curr) < Solution::char_to_int(next) {
                    num += -Solution::char_to_int(curr);
                } else {
                    num += Solution::char_to_int(curr);
                }
            } else if let Some(&curr) = s.get(i) {
                num += Solution::char_to_int(curr);
            }
        }
        num
    }
}

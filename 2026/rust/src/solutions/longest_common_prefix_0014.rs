pub struct Solution;

#[allow(dead_code)]
impl Solution {
    pub fn longest_common_prefix(mut strs: Vec<String>) -> String {
        strs.sort();
        let mut result = String::new();
        if let Some(first) = strs.first()
            && let Some(last) = strs.last()
        {
            for (f, l) in first.chars().zip(last.chars()) {
                if f == l {
                    result.push(f);
                } else {
                    return result;
                }
            }
        }
        result
    }
}

pub struct Solution;

#[allow(dead_code)]
impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack = Vec::new();
        for c in s.chars() {
            if c == '[' || c == '(' || c == '{' {
                stack.push(c);
            } else if c == ']' && let Some(&'[') = stack.last() {
                stack.pop();
            } else if c == '}' && let Some(&'{') = stack.last() {
                stack.pop();
            } else if c == ')' && let Some(&'(') = stack.last() {
                stack.pop();
            } else {
                return false;
            }
        }
        stack.is_empty()
    }
}

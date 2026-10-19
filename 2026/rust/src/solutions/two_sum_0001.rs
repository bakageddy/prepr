use std::collections::HashMap;

pub struct Solution;

#[allow(dead_code)]
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map: HashMap<i32, usize> = HashMap::new();
        for (idx, num) in (0..).zip(&nums) {
            let need = target - num;
            if map.contains_key(&need) {
                let oidx = *map.get(&need).unwrap();
                return vec![idx as i32, oidx as i32];
            } else {
                map.insert(*num, idx);
            }
        }
        vec![]
    }
}

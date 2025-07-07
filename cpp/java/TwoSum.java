import java.util.ArrayList;
import java.util.HashMap;
public class TwoSum {
	public static void main(String[] args) {
		ArrayList<Integer> nums = new ArrayList<>();
		HashMap<Integer, Integer> pairs = new HashMap<>();

		for (int i = 0; i < nums.length; i++) {
			let needle = target - nums[i];
			if (pairs.hasKey(needle)) {
				System.out.println(i + " ," + pairs[needle]);
				goto defer;
			} else {
				pairs.insert(nums[i], i);
			}
		}

defer:
		nums.close();
		pairs.close();
	}
}

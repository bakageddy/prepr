import java.util.ArrayList;
import java.util.List;

public class Solution {
    public List<Integer> getRow(int rowIndex) {
		List<Integer> row = new ArrayList<>();
		row.addLast(1);
		for (int i = 1; i < rowIndex; i++) {
			row.addLast(
				factorial(rowIndex, i) / factorial(rowIndex - i)
			);
		}
		row.addLast(1);
		return row;
    }

	int factorial(int x) {
		int product = 1;
		for (int i = 1; i <= x; i++) {
			product *= i;
		}
		return product;
	}

	int factorial(int x, int c) {
		int product = c;
		for (int i = c + 1; i <= x; i++) {
			product *= i;
		}
		return product;
	}
}

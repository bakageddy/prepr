#include <iostream>
#include <string>
using std::string;

static char lookup_table[] = {
	'A',
	'B',
	'C',
	'D',
	'E',
	'F',
	'G',
	'H',
	'I',
	'J',
	'K',
	'L',
	'M',
	'N',
	'O',
	'P',
	'Q',
	'R',
	'S',
	'T',
	'U',
	'V',
	'W',
	'X',
	'Y',
	'Z',
};

class Solution {
public:
  string convertToTitle(int columnNumber) {
    string title = {};
    while (columnNumber > 0) {
      int rem = (columnNumber-1) % 26;
      title = lookup_table[rem] + title;
      columnNumber = (columnNumber - 1) / 26;
    }
    return title;
  }
};

int main(void) {
  Solution sol = {};
  string title = sol.convertToTitle(27);
  std::cout << title << '\n';
  return 0;
}

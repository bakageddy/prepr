#include <string>
#include <unordered_map>
using std::string, std::unordered_map;

static unordered_map<int, string> lookup_table = {
	{1, "I"},
	{2, "II"},
	{3, "III"},
	{4, "IV"},
	{5, "V"},
	{6, "VI"},
	{7, "VII"},
	{8, "VIII"},
	{9, "IX"},
	{10, "X"},
	{50, "L"},
	{100, "C"},
	{500, "D"},
	{1000, "M"},
};

class Solution {
public:
    string intToRoman(int num) {
    }
};
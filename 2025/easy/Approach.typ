#set text(font: "New Computer Modern", size: 14pt)

= 0001: Remove Duplicates
Traverse the collection. Compute the required value to reach the target. Remember the required value in a hashmap and the index of the original value. Check if the required value is already there in the collection.

= 0009: Palindromic Numeral
Reverse the number with mathematics and check if it's the same

= 0013: Roman Numeral to Integer
Traverse the roman numeral from the end and add all the mapped integer values if it's smaller than the previously visited value
If it's not smaller, subtract it from the *accumulated* value

= 0014: Longest Common Subsequence
Find the smallest string (in length) from the given collection
Iterate the collection, checking with every character of the smallest string with every other string

= 0020: Valid Parenthesis
Use a stack which keeps track of the open delimiter that it visits.
If we visit a closed delimiter, then we peek the stack and check if it's a open delimiter of the same type
If it's of the same type, pop the stack, else return false
At the end of the loop check whether the stack is empty

*TODO*: Use Recursion.

= 0021: Merge Sorted Lists
Recursive Approach: Compare two heads of the list, only traverse the head that is small, recursively and assign the result to the smaller head's tail

= 0026: Remove Duplicates
Two Pointer Approach. Overwrite and Visitor pattern, Overwrite is slow and Visitor is fast. Overwrite moves only when they are on different elements.

= 0027: Remove Element
Same Two Pointer Approach. Overwrite and a Visitor pattern. Skip whenever the visitor visits the val. Overwrite each time it doesn't.

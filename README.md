# palindromic-table

Lucy has a table of digits with rows and columns. She considers each cell of the table as a rectangle. The top left cell has the coordinates of and the bottom right cell has the coordinates of

. Cells can be grouped together to form larger rectangles.

Lucy is on the lookout for palindromic sequences. She glances at the table and tries to find the sub-rectangle with the largest area such that its digits form a palindromic sequence. She calls such a rectangle a beautiful rectangle. She notices that there can be multiple such rectangles present and is happy to consider any one of them as long as the palindromic sequence formed by its digits don't contain a leading zero. Note that a sequence of only
element can contain , but

is invalid as it contains a leading zero.

Can you help Lucy find and print the area and coordinates of the largest beautiful rectangle?

image

For example, in the above table, the largest beautiful rectangle has top left coordinate of
and bottom right coordinate of , since it's digits form the palindromic sequence . The digits can also be rearranged to another palindrome

which isn't valid because it has a leading zero.

Note A single digit

is a valid palindrome.

Input Format

The first line contains two integers,
and .
The following lines contains

digits each.

Constraints

Output Format

In the first line print the largest area.
In the second line print the rectangle
, , , where (,

).
If there are multiple beautiful rectangles with the largest area, output any of them.

Sample Input 0

3 3
1 1 1
1 0 1
1 1 1

Sample Output 0

9
0 0 2 2

Explanation 0

In this case we can take whole table, because it consists of digits
we can rearrange them and obtain a palindromic string with these digits:

Sample Input 1

3 5
1 2 0 3 2
0 1 2 3 4
0 9 8 9 0

Sample Output 1

8
0 0 1 3

Explanation 1

If we take rectangle
, we will have digits and we can rearrange them and obtain a palindromic string: 

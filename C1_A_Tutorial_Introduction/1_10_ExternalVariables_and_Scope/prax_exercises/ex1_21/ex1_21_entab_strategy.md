## Problem: 
Write a program `entab` that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for `detab`. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?

`spaces % tab_length`

if you have one space, replace it with a space.
if you have a number of spaces that is greater than the length of a tab stop, you can do a modulo to get the number of spaces to add beyond the number of tabs. i suppose you could do an integer division to get the number of tabs, and the number of spaces.

now how does the number of spaces affect the 
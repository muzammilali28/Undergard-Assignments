//declaring array with mixed data types;
var arr=[1,'a',2,'b',3,'c',4,'b',5,'c'];
document.write("Array : "+arr+"<br>");

//Finds the Length of the Array  (1) (arr.length)
document.write("<br>\\\\\\\\ <u>Length</u> ////<br>");
var size = arr.length;
document.write("<br>Array Length : "+size+"<br>");

//Determines whether an array includes a certain element  (2) does the (arr.include(this value))
document.write("<br>\\\\\\\\ <u>Include</u> ////<br>");
var answer = arr.includes('a');
document.write("<br>Array includes 'a': "+answer+"<br>");

//Search the array for an element and returns its first index  (3) check for first occurence of an element from L-->R (arr.indefOf(value))
document.write("<br>\\\\\\\\ <u>First Occurance</u> ////<br>");
var index = arr.indexOf('b');
document.write("<br>The character 'b' has first occured at index : "+index+"<br>");

//Search the array for an element, starting at the end, and returns its last index  (4) check for last occurence of an element from R-->L (arr.indefOf(value))
document.write("<br>\\\\\\\\ <u>Last Occurance</u> ////<br>");
var lstIndex = arr.lastIndexOf('b');
document.write("<br>The character 'b' has last occured at index : "+lstIndex+"<br>");

//Adds one or more elements to the end of an array, and returns the array's new length  (5) push a value and get new size (arr.push(value))
document.write("<br>\\\\\\\\ <u>Push</u> /////<br>");
var newSize = arr.push(99);
document.write("<br>Array : "+arr+"<br>");
document.write("New Size : "+newSize+"<br>");

//Removes the last element from an array, and returns that element  (6) Works as a stack and removes the last element (arr.pop())
document.write("<br>\\\\\\\\ <u>Pop</u> ////<br>");
var popElement = arr.pop();
document.write("<br>Array : "+arr+"<br>");
var SIZE = arr.length;
document.write("New Size : "+SIZE+"<br>");

//Removes the first element from an array, and returns that element  (7) Works as a queue and removes the first element (arr.shift())
document.write("<br>\\\\\\\\ <u>Shift</u> ////<br>");
var First = arr.shift();
document.write("<br>The First Element of Array is : "+First+"<br>");
document.write("Array : "+arr+"<br>");

//Adds new elements to the beginning of an array, and returns the array's new length  (8) Insert the element at start index (arr.unshift(value))
document.write("<br>\\\\\\\\ <u>UnShift</u> ////<br>");
var expandedSize = arr.unshift(1);
document.write("<br>Array : "+arr+"<br>");
document.write("New Size : "+expandedSize+"<br>");

//Reverses the order of the elements in an array  (9) Reverses the array (arr.reverse())
document.write("<br>\\\\\\\\ <u>Reverse</u> ////<br>");
arr.reverse();
document.write("<br>Reversed Array : "+arr+"<br>");

//Sorts the elements of an array (10) Sorts the Arrays in Ascending Order (arr.sort())
document.write("<br>\\\\\\\\ <u>Sort</u> ////<br>");
arr.sort();
document.write("<br>Sorted Array : "+arr+"<br>");

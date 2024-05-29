#ifndef STATIC_LIBRARY_HPP
#define STATIC_LIBRARY_HPP

#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>



class StaticLib {
public:
   //----------------------------------------------------------------------------------------------------
   /*
   Given a sorted array of distinct integers and a target value, return the index if the target is found.
   If not, return the index where it would be if it were inserted in order.
   */
   static int searchInsert(std::vector <int> &nums, int target);
   //----------------------------------------------------------------------------------------------------
   /*
   Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
   - Integers in each row are sorted in ascending from left to right.
   - Integers in each column are sorted in ascending from top to bottom.
   */
   static bool searchMatrix(std::vector <std::vector <int> > &matrix, int target);
   //----------------------------------------------------------------------------------------------------
   /*
   Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums.
   If target exists, then return its index. Otherwise, return -1.
   */
   static int binarySearch(std::vector <int> &nums, int target);
   //----------------------------------------------------------------------------------------------------
   /*
   Given a non-negative integer x, return the square root of x rounded down to the nearest integer.
   The returned integer should be non-negative as well.
   */
   static int sqrt(int x);
   //----------------------------------------------------------------------------------------------------
   /*
   Given a positive integer num, return true if num is a perfect square or false otherwise.
   A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.
   You must not use any built-in library function, such as sqrt.
   */
   static bool isPerfectSquare(int num);
   //----------------------------------------------------------------------------------------------------
   /*
   A sentence is a list of words that are separated by a single space with no leading or trailing spaces.
   Each of the words consists of only uppercase and lowercase English letters (no punctuation).
   For example, "Hello World", "HELLO", and "hello world hello world" are all sentences.
   You are given a sentence s​​​​​​ and an integer k​​​​​​.
   You want to truncate s​​​​​​ such that it contains only the first k​​​​​​ words. Return s​​​​​​ after truncating it.
   */
   static std::string truncateSentence(std::string s, int k);
   //----------------------------------------------------------------------------------------------------
   /*
   A sentence is a list of words that are separated by a single space with no leading or trailing spaces.
   For example, "Hello World", "HELLO", "hello world hello world" are all sentences.
   Words consist of only uppercase and lowercase English letters.
   Uppercase and lowercase English letters are considered different.
   A sentence is circular if:
   -The last character of a word is equal to the first character of the next word.
   -The last character of the last word is equal to the first character of the first word.
   -For example, "leetcode exercises sound delightful", "eetcode", "leetcode eats soul" are all circular sentences. However, "Leetcode is cool", "happy Leetcode", "Leetcode" and "I like Leetcode" are not circular sentences.
   Given a string sentence, return true if it is circular. Otherwise, return false.
   */
   static bool isCircularSentence(std::string sentence);
   //----------------------------------------------------------------------------------------------------
   /*
   Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.
   Note that elements beyond the length of the original array are not written.
   Do the above modifications to the input array in place and do not return anything.
   */
   static void duplicateZeros(std::vector <int> &arr);
   //----------------------------------------------------------------------------------------------------
   /*
   Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
   */
   static std::vector <int> sortedSquares(std::vector <int> &nums);
   //----------------------------------------------------------------------------------------------------
   /*
   Given an array nums of integers, return how many of them contain an even number of digits.
   */
   static int findNumbers(std::vector <int>& nums);
   //----------------------------------------------------------------------------------------------------
   /*
   Given a binary array nums, return the maximum number of consecutive 1's in the array.
   */
   static int findMaxConsecutiveOnes(std::vector <int> &nums);
   //----------------------------------------------------------------------------------------------------
   /*			
   Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
   Each letter in magazine can only be used once in ransomNote.
   */
   static bool canConstruct(std::string ransomNote, std::string magazine);
   //----------------------------------------------------------------------------------------------------
   /*
   Given an integer num, return the number of steps to reduce it to zero.
   In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.
   */
   static int numberOfSteps(int num);
   //----------------------------------------------------------------------------------------------------
   /*
   You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank.
   Return the wealth that the richest customer has.
   A customer's wealth is the amount of money they have in all their bank accounts.
   The richest customer is the customer that has the maximum wealth.
   */
   static int maximumWealth(std::vector <std::vector <int> >& accounts);
   //----------------------------------------------------------------------------------------------------
   /*
   Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
   Return the running sum of nums.
   */
   static std::vector<int> runningSum(std::vector<int>& nums);
   //----------------------------------------------------------------------------------------------------
   /*
   Given two integers num1 and num2, return the sum of the two integers.
   */
   static int Sum(int num1, int num2);
   //----------------------------------------------------------------------------------------------------
   /*
   You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have.
   Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.
   Letters are case sensitive, so "a" is considered a different type of stone from "A".
   */
   static int numJewelsInStones(std::string jewels, std::string stones);
   //----------------------------------------------------------------------------------------------------
   /*
   Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
   A shift on s consists of moving the leftmost character of s to the rightmost position.
   For example, if s = "abcde", then it will be "bcdea" after one shift.
   */
   static bool rotateString(std::string s, std::string goal);
   //----------------------------------------------------------------------------------------------------
   /*
   Write a function that reverses a string. The input string is given as an array of characters s.
   */
   static void reverseString(std::vector <char> &s);
   //----------------------------------------------------------------------------------------------------
   /*
   Given an integer n, return a string array answer (1-indexed) where:
   answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
   answer[i] == "Fizz" if i is divisible by 3.
   answer[i] == "Buzz" if i is divisible by 5.
   answer[i] == i (as a string) if none of the above conditions are true.
   */
   static std::vector<std::string> fizzBuzz(int n);
   //----------------------------------------------------------------------------------------------------
   /*
   Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

   Symbol       Value
   I             1
   V             5
   X             10
   L             50
   C             100
   D             500
   M             1000

   For example, 2 is written as II in Roman numeral, just two ones added together.
   12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

   Roman numerals are usually written largest to smallest from left to right.
   However, the numeral for four is not IIII. Instead, the number four is written as IV.
   Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX.
   There are six instances where subtraction is used:

   I can be placed before V (5) and X (10) to make 4 and 9. 
   X can be placed before L (50) and C (100) to make 40 and 90. 
   C can be placed before D (500) and M (1000) to make 400 and 900.
   Given a roman numeral, convert it to an integer.
   */
   static int romanToInt(std::string s);
   //----------------------------------------------------------------------------------------------------
   /*
   You are given an array of strings words and a string pref.
   Return the number of strings in words that contain pref as a prefix.
   A prefix of a string s is any leading contiguous substring of s.
   */
   static int prefixCount(std::vector <std::string> &words, std::string pref);
   //----------------------------------------------------------------------------------------------------
   /*
   Given a 0-indexed string s, repeatedly perform the following operation any number of times:
   Choose an index i in the string, and let c be the character in position i.
   Delete the closest occurrence of c to the left of i (if any) and the closest occurrence of c to the right of i (if any).
   Your task is to minimize the length of s by performing the above operation any number of times.
   Return an integer denoting the length of the minimized string.
   */
   static int minimizedStringLength(std::string s);
   //----------------------------------------------------------------------------------------------------
   /*
   You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
   For each index i, names[i] and heights[i] denote the name and height of the ith person.
   Return names sorted in descending order by the people's heights.
   */
   static std::vector <std::string> sortPeople(std::vector <std::string> &names, std::vector <int> &heights);
   //----------------------------------------------------------------------------------------------------
   /*
   International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:

   'a' maps to ".-",
   'b' maps to "-...",
   'c' maps to "-.-.", and so on.

   For convenience, the full table for the 26 letters of the English alphabet is given below:
   [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

   Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter.
   For example, "cab" can be written as "-.-..--...", which is the concatenation of "-.-.", ".-", and "-...".
   We will call such a concatenation the transformation of a word.
   Return the number of different transformations among all words we have.
   */
   static int uniqueMorseRepresentations(std::vector <std::string> &words);
   //----------------------------------------------------------------------------------------------------
   /*
   A password is said to be strong if it satisfies all the following criteria:

   It has at least 8 characters.
   It contains at least one lowercase letter.
   It contains at least one uppercase letter.
   It contains at least one digit.
   It contains at least one special character. The special characters are the characters in the following string: "!@#$%^&*()-+".
   It does not contain 2 of the same character in adjacent positions (i.e., "aab" violates this condition, but "aba" does not).

   Given a string password, return true if it is a strong password. Otherwise, return false.
   */
   static bool strongPasswordCheckerII(std::string password);
   //----------------------------------------------------------------------------------------------------
   /*
   There is a robot starting at the position (0, 0), the origin, on a 2D plane.
   Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.
   You are given a string moves that represents the move sequence of the robot where moves[i] represents its ith move.
   Valid moves are 'R' (right), 'L' (left), 'U' (up), and 'D' (down).
   Return true if the robot returns to the origin after it finishes all of its moves, or false otherwise.
   Note: The way that the robot is "facing" is irrelevant.
   'R' will always make the robot move to the right once, 'L' will always make it move left, etc.
   Also, assume that the magnitude of the robot's movement is the same for each move.
   */
   static bool judgeCircle(std::string moves);
   //----------------------------------------------------------------------------------------------------
   /*
   Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
   */
   static std::string reverseWords(std::string s);
   //----------------------------------------------------------------------------------------------------
};



#endif /* STATIC_LIBRARY_HPP! */
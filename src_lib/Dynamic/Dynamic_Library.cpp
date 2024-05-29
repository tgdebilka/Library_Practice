#include "Dynamic_Library.hpp"



//----------------------------------------------------------------------------------------------------
int DynamicLib::searchInsert(std::vector <int> &nums, int target)
{
   int left = 0;
   int right = nums.size() - 1;
   int middle{};

   if (target > nums[right])
      return right + 1;
   else if (target < nums[left])
      return left;

   while (left <= right)
   {
      middle = left + (right - left) / 2;

      if (target == nums[middle])
         return middle;
      if (target < nums[middle])
         right = middle - 1;
      else
         left = middle + 1;
   }

   return left;
}
//----------------------------------------------------------------------------------------------------
bool DynamicLib::searchMatrix(std::vector <std::vector <int> > &matrix, int target)
{
   if ( matrix.empty() )
      return false;

   int row = matrix.size() - 1;
   int col = 0;
   int cols_count = matrix[0].size();

   while (row >= 0 && col < cols_count)
   {
      if (matrix[row][col] == target)
         return true;
      else if (matrix[row][col] > target)
         row--;
      else
         col++;
   }

   return false;
}
//----------------------------------------------------------------------------------------------------
int DynamicLib::binarySearch(std::vector <int> &nums, int target)
{
   int left = 0;
   int right = nums.size() - 1;
   int middle;

   while (left <= right)
   {
      middle = left + (right - left) / 2;

      if (nums[middle] == target)
         return middle;
      else if (nums[middle] < target)
         left = middle + 1;
      else
         right = middle - 1;
   }

   return -1;
}
//----------------------------------------------------------------------------------------------------
int DynamicLib::algorithm_sqrt(int x)
{
   if (x < 0)
      return -1;
   else if (x == 1)
      return 1;

   int left = 0;
   int right = x;
   long long middle;

   while (left <= right)
   {
      middle = left + (right - left) / 2;

      if (middle * middle == x)
         return middle;
      else if (middle * middle < x)
         left = middle + 1;
      else
         right = middle - 1;
   }

   return left;
}
//----------------------------------------------------------------------------------------------------
bool DynamicLib::isPerfectSquare(int num)
{
   long long result = algorithm_sqrt(num);
   return (result * result == num);
}
//----------------------------------------------------------------------------------------------------
std::string DynamicLib::truncateSentence(std::string s, int k)
{
   if (s == "") { return s;  }

   std::vector<std::string> words;

   std::string word = "";
   int size_s = s.length();
   for (size_t i = 0; i <= size_s; ++i) {
      if ( (s[i] == ' ') && (i != 0) && (i != (size_s - 1)) || i == size_s) {
         words.push_back(word);
         word = "";
      } else
         word += s[i];
   }

   s = "";
   for (size_t i = 0; i < k; ++i) {
      if (i == k - 1)
         s += words[i];
      else
         s += (words[i] + ' ');
   }

   return s;
}
//----------------------------------------------------------------------------------------------------
bool DynamicLib::isCircularSentence(std::string sentence)
{
   std::vector <std::string> words;
   std::string word;
   size_t sentence_size = sentence.size();

   for (size_t i = 0; i < sentence_size; ++i) {
      if (sentence[i] != ' ') {
         word += sentence[i];
      }
      else {
         words.push_back(word);
         word = "";
      }
   }
   words.push_back(word);
   word.clear();

   size_t words_size = words.size();
   if (words_size == 1) { return (words[0][words[0].length() - 1] == words[0][0]) ? true : false; }
   if (words[0][0] != words[words_size - 1][words[words_size - 1].length() - 1]) { return false; }
   for (size_t i = 0; i < words_size - 1; ++i)
      if (words[i][words[i].length() - 1] != words[i + 1][0]) { return false; }

   return true;
}
//----------------------------------------------------------------------------------------------------
void DynamicLib::duplicateZeros(std::vector <int> &arr)
{
   size_t size = arr.size();
   for (size_t i = 0; i < size; ++i) {
      if (arr[i] == 0) {
         for (size_t j = size - 1; j > i; --j)
            arr[j] = arr[j - 1];

         if (i + 1 < size) {
            arr[i + 1] = 0;
            ++i;
         }
      }
   }

}
//----------------------------------------------------------------------------------------------------
int DynamicLib::findNumbers(std::vector <int>& nums)
{
   if (nums.empty()) { return 0; }

   unsigned short count_even    = 0;
   unsigned short digit_number  = 1;
   unsigned short degree_number = 10;
   for (int num : nums) {
      while (num > 9) {
         num /= degree_number;
         ++digit_number;
      }

      if (digit_number % 2 == 0) { ++count_even; }
      digit_number = 1;
   }

   return count_even;
}
//----------------------------------------------------------------------------------------------------
int DynamicLib::findMaxConsecutiveOnes(std::vector <int> &nums)
{
   unsigned int max_consecutive = 0;
   unsigned int temp            = 0;
   for (size_t i = 0; i < nums.size(); ++i) {
      if (nums[i] == 1) { ++temp; }

      if ( (nums[i] == 0) || (i == (nums.size() - 1)) ) {
         if (temp > max_consecutive) { max_consecutive = temp; }
         temp = 0;
      }
   }

   return max_consecutive;
}
//----------------------------------------------------------------------------------------------------
bool DynamicLib::canConstruct(std::string ransomNote, std::string magazine)
{
   bool IsCanConstruct  = false;
   unsigned int size_note = ransomNote.size();
   unsigned int size_magazine = magazine.size();

   for (size_t i = 0; i <= size_note; ++i) {
      for (size_t j = 0, begin_note = 0; j <= size_magazine; ++j) {
         if (ransomNote[begin_note] == magazine[j]) {
            magazine.erase(j, 1);
            ransomNote.erase(begin_note, 1);
            break;
         }
      }

      if (ransomNote.empty()) {
         IsCanConstruct = true;
         break;
      }
   }

   return IsCanConstruct;
}
//----------------------------------------------------------------------------------------------------
int DynamicLib::numberOfSteps(int num)
{
   unsigned int steps = 0;

   while (num != 0)
   {
      (num % 2 == 0) ? num /= 2 : --num;
      ++steps;
   }

   return steps;
}
//----------------------------------------------------------------------------------------------------
int DynamicLib::maximumWealth(std::vector <std::vector <int> >& accounts)
{
   unsigned int max_rich   = 0;
   unsigned int sum        = 0;
   for (auto account : accounts) {
      sum = 0;

      for (int unit : account) { sum += unit;    }
      if  (sum >= max_rich   ) { max_rich = sum; }
   }

   return max_rich;
}
//----------------------------------------------------------------------------------------------------
int DynamicLib::Sum(int num1, int num2)
{
   return num1 + num2;
}
//----------------------------------------------------------------------------------------------------
bool DynamicLib::rotateString(std::string s, std::string goal)
{
   if (s.length() != goal.length())
      return false;

   bool isCorrectGoal = false;

   for (size_t i = 0; i < s.size(); i++) {
      if (s[i] == goal[0]) {
         size_t j = i;
         isCorrectGoal = true;
         for (size_t k = 0; k < goal.size(); k++, j++) {
            if (j == goal.size())
               j = 0;

            if (goal[k] != s[j]) {
               isCorrectGoal = false;
               break;
            }
         }
         if (isCorrectGoal)
            break;
      }
   }

   return isCorrectGoal;
}
//----------------------------------------------------------------------------------------------------
void DynamicLib::reverseString(std::vector<char>& s)
{
   size_t left = 0;
   size_t right = s.size() - 1;

   while (left < right)
      std::swap(s[left++], s[right--]);
}
//----------------------------------------------------------------------------------------------------
int DynamicLib::romanToInt(std::string s)
{
   short size_s = s.size();

   int roman_int {};
   for (char i = size_s - 1; i >= 0; --i)
   {
      switch (s[i])
      {
      case 'I':
         roman_int++;
         break;
      case 'V':
         roman_int += 5;
         break;
      case 'X':
         roman_int += 10;
         break;
      case 'L':
         roman_int += 50;
         break;
      case 'C':
         roman_int += 100;
         break;
      case 'D':
         roman_int += 500;
         break;
      case 'M':
         roman_int += 1000;
         break;
      default:
         roman_int += 0;
         break;
      }

      if (i != 0 && s[i] > s[i - 1])
         roman_int--;
   }

   return roman_int;
}
//----------------------------------------------------------------------------------------------------
int DynamicLib::prefixCount(std::vector<std::string>& words, std::string pref)
{
   int count_pref = 0;
   std::string local_pref = "";

   for (size_t i = 0; i < words.size(); i++) {
      for (size_t j = 0; j < pref.size(); j++) {
         if (words[i][j] == pref[j])
            local_pref += words[i][j];
         else
            break;
      }

      if (local_pref == pref)
         ++count_pref;

      local_pref.clear();
   }

   return count_pref;
}
//----------------------------------------------------------------------------------------------------
int DynamicLib::minimizedStringLength(std::string s)
{
   std::map<char, short> map;

   for (char c : s)
      map[c] = c;

   return map.size();
}
//----------------------------------------------------------------------------------------------------
bool DynamicLib::judgeCircle(std::string moves)
{
   short vertical = 0;
   short horizontal = 0;

   for (size_t i = 0; i < moves.size(); i++) {
      switch (moves[i]) {
      case 'U':
         vertical++;
         break;
      case 'D':
         vertical--;
         break;
      case 'R':
         horizontal++;
         break;
      case 'L':
         horizontal--;
         break;
      }
   }

   return ((vertical == 0) && (horizontal == 0));
}
//----------------------------------------------------------------------------------------------------
std::string DynamicLib::reverseWords(std::string s)
{
   std::string current_word = "";
   std::string reverse_str = "";

   for (size_t i = 0; i < s.size(); i++) {
      if (s[i] != ' ')
         current_word += s[i];

      if (s[i] == ' ' || i == (s.size() - 1)) {
         for (size_t j = 0; j < current_word.size(); j++)
            reverse_str += current_word[current_word.size() - 1 - j];

         current_word.clear();

         if (i != (s.size() - 1))
            reverse_str += ' ';
      }
   }

   return reverse_str;
}
//----------------------------------------------------------------------------------------------------
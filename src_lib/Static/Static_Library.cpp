#include "Static_Library.hpp"



//----------------------------------------------------------------------------------------------------
int StaticLib::searchInsert(std::vector <int> &nums, int target)
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
bool StaticLib::searchMatrix(std::vector <std::vector <int> > &matrix, int target)
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
int StaticLib::binarySearch(std::vector <int> &nums, int target)
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
int StaticLib::sqrt(int x)
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
bool StaticLib::isPerfectSquare(int num)
{
   long long result = sqrt(num);
   return (result * result == num);
}
//----------------------------------------------------------------------------------------------------
std::string StaticLib::truncateSentence(std::string s, int k)
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
bool StaticLib::isCircularSentence(std::string sentence)
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
void StaticLib::duplicateZeros(std::vector <int> &arr)
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
std::vector <int> StaticLib::sortedSquares(std::vector <int> &nums)
{
   int size = nums.size();
   std::vector <int> result(size);

   int left  = 0;
   int right = size - 1;
   int index = size - 1;

   while (left <= right) {
      int leftSquare  = nums[left]  * nums[left];
      int rightSquare = nums[right] * nums[right];

      if (leftSquare > rightSquare) {
         result[index] = leftSquare;
         ++left;
      } else {
         result[index] = rightSquare;
         --right;
      }

      --index;
   }

   return result;
}
//----------------------------------------------------------------------------------------------------
int StaticLib::findNumbers(std::vector <int>& nums)
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
int StaticLib::findMaxConsecutiveOnes(std::vector <int> &nums)
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
bool StaticLib::canConstruct(std::string ransomNote, std::string magazine)
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
int StaticLib::numberOfSteps(int num)
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
int StaticLib::maximumWealth(std::vector <std::vector <int> >& accounts)
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
std::vector<int> StaticLib::runningSum(std::vector<int>& nums)
{
   int size = nums.size();

   for (int i = 1; i < size; ++i)
      nums[i] += nums[i - 1];

   return nums;
}
//----------------------------------------------------------------------------------------------------
int StaticLib::Sum(int num1, int num2)
{
   return num1 + num2;
}
//----------------------------------------------------------------------------------------------------
int getLengthStr(std::string str)
{
   int i = 0;
   while (str[i] != '\0')
      ++i;

   return i;
}
//----------------------------------------------------------------------------------------------------
int StaticLib::numJewelsInStones(std::string jewels, std::string stones)
{
   int count_jewels = 0;

   for (size_t i = 0; i < getLengthStr(jewels); i++)
   {
      for (size_t j = 0; j < getLengthStr(stones); j++)
      {
         if (stones[j] == jewels[i])
            ++count_jewels;
      }
   }

   return count_jewels;
}
//----------------------------------------------------------------------------------------------------
bool StaticLib::rotateString(std::string s, std::string goal)
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
void StaticLib::reverseString(std::vector<char>& s)
{
   size_t left = 0;
   size_t right = s.size() - 1;

   while (left < right)
      std::swap(s[left++], s[right--]);
}
//----------------------------------------------------------------------------------------------------
std::vector<std::string> StaticLib::fizzBuzz(int n)
{
   std::vector<std::string> answer;

   for (int i = 1; i <= n; ++i) {
      bool isFizz = (i % 3 == 0);
      bool isBuzz = (i % 5 == 0);

      if (isFizz && isBuzz)
         answer.push_back("FizzBuzz");
      else if (isFizz)
         answer.push_back("Fizz");
      else if (isBuzz)
         answer.push_back("Buzz");
      else
         answer.push_back(std::to_string(i));
   }

   return answer;
}
//----------------------------------------------------------------------------------------------------
int StaticLib::romanToInt(std::string s)
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
int StaticLib::prefixCount(std::vector<std::string>& words, std::string pref)
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
int StaticLib::minimizedStringLength(std::string s)
{
   std::map<char, short> map;

   for (char c : s)
      map[c] = c;

   return map.size();
}
//----------------------------------------------------------------------------------------------------
std::vector <std::string> StaticLib::sortPeople (std::vector <std::string> &names, std::vector <int> &heights)
{
   std::map <int, std::string> humans;

   for (size_t i = 0; i < names.size(); i++)
      humans.insert(std::make_pair(heights[i], names[i]));

   size_t index = 0;
   for (const auto& pair : humans)
   {
      heights[humans.size() - 1 - index] = pair.first;
      names[humans.size() - 1 - index] = pair.second;
      ++index;
   }

   return names;
}
//----------------------------------------------------------------------------------------------------
std::unordered_map <char, std::string> morse_code =
{
   {'a', ".-"},   {'b', "-..."},
   {'c', "-.-."}, {'d', "-.."},
   {'e', "."},    {'f', "..-."},
   {'g', "--."},  {'h', "...."},
   {'i', ".."},   {'j', ".---"},
   {'k', "-.-"},  {'l', ".-.."},
   {'m', "--"},   {'n', "-."},
   {'o', "---"},  {'p', ".--."},
   {'q', "--.-"}, {'r', ".-."},
   {'s', "..."},  {'t', "-"},
   {'u', "..-"},  {'v', "...-"},
   {'w', ".--"},  {'x', "-..-"},
   {'y', "-.--"}, {'z', "--.."}
};

int StaticLib::uniqueMorseRepresentations(std::vector<std::string>& words) {
   std::vector <std::string> morse_code_words;
   std::string morse_code_word = "";
   std::unordered_set <std::string> unique_morse_words;

   for (size_t i = 0; i < words.size(); i++) {
      for (size_t j = 0; j < words[i].size(); j++)
         morse_code_word += morse_code.at(words[i][j]);

      morse_code_words.push_back(morse_code_word);
      morse_code_word.clear();
   }

   for (const std::string& word : morse_code_words)
      unique_morse_words.insert(word);

   return unique_morse_words.size();
}
//----------------------------------------------------------------------------------------------------
const std::vector <char> lowercase_chars =
{  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

const std::vector <char> uppercase_chars =
{  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

const std::vector <char> special_chars =
{  '!', '@', '#', '$',
'%', '^', '&', '*',
'(', ')', '-', '+'};

const std::vector <char> digits_chars =
{  '0', '1', '2', '3',
'4', '5', '6',
'7', '8', '9'};

bool StaticLib::strongPasswordCheckerII(std::string password)
{
   auto CharsChecker = [&password](const std::vector <char>& character_set) -> bool {
      for (size_t i = 0; i < password.size(); i++) {
         for (size_t j = 0; j < character_set.size(); j++) {
            if (password[i] == character_set[j])
               return true;
         }
      }

      return false;
      };

   auto CharsSimilarCheker = [&password]() -> bool {
      for (size_t i = 1; i < password.size(); i++) {
         if (password[i] == password[i - 1])
            return false;
      }

      return true;
      };

   return ((password.size() >= 8) && CharsChecker(lowercase_chars) &&
      CharsChecker(uppercase_chars) && CharsChecker(digits_chars) &&
      CharsChecker(special_chars) && CharsSimilarCheker());
}
//----------------------------------------------------------------------------------------------------
bool StaticLib::judgeCircle(std::string moves)
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
std::string StaticLib::reverseWords(std::string s)
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
#ifndef stringb_in_stringa_h__
#define stringb_in_stringa_h__

//假设这有一个各种字母组成的字符串A，和另外一个字符串B，字符串里B
//的字母数相对少一些。什么方法能最快的查出所有小字符串B 里的字母在大字符
//串A 里都有？
//比如，如果是下面两个字符串：
//String 1: ABCDEFGHLMNOPQRS
//String 2: DCGSRQPO

void test_stringa_in_stringb();

//解法1，最简单的方法，一个一个字符检查 O(m*n)  20131219
bool stringb_in_string1(const char* pstra, const char* pstrb);

//排序后遍历 O(m*logm + n*logn + m + n) 20131219
bool stringb_in_string2(const char* pstra, const char* pstrb);
#endif // stringb_in_stringa_h__

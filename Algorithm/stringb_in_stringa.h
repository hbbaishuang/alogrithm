#ifndef stringb_in_stringa_h__
#define stringb_in_stringa_h__

//��������һ��������ĸ��ɵ��ַ���A��������һ���ַ���B���ַ�����B
//����ĸ�������һЩ��ʲô���������Ĳ������С�ַ���B �����ĸ�ڴ��ַ�
//��A �ﶼ�У�
//���磬��������������ַ�����
//String 1: ABCDEFGHLMNOPQRS
//String 2: DCGSRQPO

void test_stringa_in_stringb();

//�ⷨ1����򵥵ķ�����һ��һ���ַ���� O(m*n)  20131219
bool stringb_in_string1(const char* pstra, const char* pstrb);

//�������� O(m*logm + n*logn + m + n) 20131219
bool stringb_in_string2(const char* pstra, const char* pstrb);
#endif // stringb_in_stringa_h__

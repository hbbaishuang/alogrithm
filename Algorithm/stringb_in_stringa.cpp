#include "stringb_in_stringa.h"
#include <stdio.h>
#include <string.h>

void test_stringa_in_stringb()
{
	char* pa = "oooopqrst";
	char* pb = "oooosttrew";
	char* pc = "hellozp";
	bool bIn = false;
	bIn = stringb_in_string2(pa, pb);
	//bIn = stringb_in_string2(pa, pc);
	if (bIn)
	{
		printf("true");
	}
	else
	{
		printf("false");
	}

}

bool stringb_in_string1(const char* pstra, const char* pstrb)
{
	int nLenA = strlen(pstra);
	int nLenB = strlen(pstrb);
	int ia = 0;
	int ib = 0;
	for (; ib < nLenB; ++ib)
	{
		for (ia = 0; ia < nLenA; ++ia)
		{
			if (pstrb[ib] == pstra[ia])
			{
				break;
			}
		}
		if (ia == nLenA)
		{
			return false;
		}
	}
	return true;
}

bool stringb_in_string2(const char* pstra, const char* pstrb)
{
	//�ȴ�С��������ã������㷨��ûд��
	//sort(pstra)
	//sort(pstrb)
	int nLenA = strlen(pstra);
	int nLenB = strlen(pstrb);
	int i = 0;
	int j = 0;
	while (i < nLenA && j < nLenB)
	{
		if (pstra[i] == pstrb[j])
		{
			//++i ���ﲻ��++i������strbһ���ַ����ֶ�� ��pstra="abcd" pstrb="aaa";
			++j;
		}
		else if (pstra[i] < pstrb[j])
		{
			++i;
		}
		else if (pstra[i] > pstrb[j])
		{
			//���������κ�һ��pstrb�е��ַ�
			break;
		}
	}
	return j == nLenB ? true:false;
}
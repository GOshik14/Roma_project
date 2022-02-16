#include "my_string.hpp"

char* my_strcat(const char* str1, const char* str2)
{
	int length = my_strlen(str1) + my_strlen(str2) + 1;
	
	char* resultStr = (char*)malloc(sizeof(char)*length);
	
	char* pNewStr = resultStr;
	
	while(*resultStr++ = *str1++);
	resultStr--;
	
	while(*resultStr++ = *str2++);
	
	return pNewStr;
}

int my_strlen(const char* pStr)
{
	int length = 0;
	
	while(*pStr++) length++;
	
	return length;
}

void my_strcpy(char* pStr1, const char* pStr2)
{
	while(*pStr1++);
	pStr1--;
	
	while(*pStr1++ = *pStr2++);
}

int my_strcmp(const char* pStr1, const char* pStr2)
{
	
	while(*pStr1++ == *pStr2++ && *pStr1 != '\0' && *pStr2 != '\0');
	
	if((*(pStr1) == '\0') && (*(pStr2) == '\0') && (*--pStr1 == *--pStr2)) return 0;
	else return -1;
}

char* uitoa(unsigned int a)
{
	if(a == 0) return "0";
	
	char* result;
	
	int cd = 0;

	int tmp = a;
	
	while(tmp != 0)
	{
		cd++;
		tmp /= 10;
	}
	
	result = (char*)malloc((cd + 1)*sizeof(char));
	result[cd] = '\0';
	
	
	for(int j = cd - 1; j >= 0; j--) {
		//int devisior = (int)pow(10, j + 1);
		result[j] = '0' + a % 10;	
		a /= 10;
	}
	
	
	
	return result;
}

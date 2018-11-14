//1.实现strcpy
//自字符串插入
//
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
//char *my_strcpy(char *dest, char *src)
//{
//	assert(dest&&src);
//	char *ret = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "abcdef";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	system("pause");
//	return 0;
//}



//2.实现strcat
//字符串追加

//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
//char *my_strcat(char *dest, const char *src)
//{
//	assert(dest&&src);
//	char* ret = dest;
//	while (*dest)
//	{
//	    dest++;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr[20] = "hello ";
//	my_strcat(arr,"world");
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}



//
////3.实现strstr
//
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
//
//char* my_strstr(const char *str, const char*substr)
//{
//	const char *s1 = str;
//	const char *s2 =substr;
//	const char *cur = str;
//	while(*cur)
//	{
//		s1 = cur;
//		s2 = substr;
//		while(*s1 && *s2 && (*s1 == *s2))
//		{
//			s1++;
//			s2++;
//		}
//		if(*s2 == '\0')
//			return (char*)cur;
//		if(*s1 == '\0')
//			return NULL;
//		cur++;
//	}
//	return NULL;
//}
//
//int main()
//{
//	char *p = "abcdef";
//	char *q = "bbc";
//	char *ret = my_strstr(p, q);
//	if(ret != NULL)
//		printf("%s\n", ret);
//	else
//		printf("找不到\n");
//	system("pause");
//	return 0;
//}




//4.实现strchr
//找字符串中一个字符第一次出现的位置

//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
//char *my_strchr(char *str, char a)
//{
//	assert(str);
//	while (*str)
//	{
//		if (*str == a)
//		{
//			return str;
//		}
//		str++;
//	}
//	return NULL;
//}
//
//
//int main()
//{
//	char arr[] = "abcddfghefg";
//	char *ret = my_strchr(arr, 'g');
//	printf("%s\n", ret);
//	system("pause");
//	return 0;
//}




////5.实现strcmp
////字符串比较
//
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
//int my_strcmp(char *str1, char *str2)
//{
//	assert(str1&&str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;
//}
//
//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "abcddfg";
//	int ret = my_strcmp(arr1, arr2);
//	printf("%d\n", ret);
//	if (ret = 0)
//	{
//		printf("相等\n");
//	}
//	else
//	{
//		printf("不相等\n");
//	}
//	system("pause");
//	return 0;
//}


//6.实现memcpy
//内存拷贝

//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
//void *my_memcpy(void *dest, const void *src, size_t sz)
//{
//	
//	assert(dest != NULL);
//	assert(src != NULL);
//	unsigned int i = 0;
//	void *ret = dest;
//	for (i = 0; i < sz; i++)
//	{
//		*(char*)dest = *(char*)src;
//		dest=(char*)dest+1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//
//int main()
//{
//
//	int arr1[10] = { 0 };
//	int arr2[] = { 1, 2, 3, 4, 5 };
//
//	//char arr1[] = "abcdefghi";
//	//int arr2[] = { 1, 0, 0, 0, 0 };
//	my_memcpy(arr1, arr2, 3 * sizeof(arr2[0]));
//	system("pause");
//	return 0;
//}



//7.实现memmove
//内存拷贝，在memcpy基础上，自身内部可以实现拷贝

//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
//void *my_memmove(void *dest, const void *src, size_t sz)
//{
//	void *ret = (char*)dest;
//	if (dest < src)
//	{
//		//前---->后
//		while (sz--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		//后--->前
//		while (sz--)
//		{
//			*((char*)dest+sz) = *((char*)src+sz);
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	my_memmove(arr, arr+3, 4 * sizeof(arr[0]));
//	system("pause");
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "CommentConvert.h"


void DoNulState(FILE* pfRead, FILE* pfWrite, State* ps)//正常状态
{
	int first = fgetc(pfRead);
	switch (first)
	{
	case '/':
	{
		int second = fgetc(pfRead);
		switch (second)
		{
	case '*':
		{
			*ps = C_STATE;//如果是C注释我们将状态改为C状态，并且将注释开头改为Cpp注释
			fputc('/', pfWrite);
			fputc('/', pfWrite);
		}
		break;
	case '/':
		{
			*ps = CPP_STATE;//如果是Cpp注释我们将状态改为Cpp状态
			fputc(first, pfWrite);
			fputc(second, pfWrite);
		}
		break;
	default://正常语句就直接写入
		fputc(first, pfWrite);
		fputc(second, pfWrite);
		break;
		}
	}
		break;
	case EOF:
		*ps = END_STATE;//注释结束，状态调整
		break;
	default://开始就为正常内容，直接写入
		fputc(first, pfWrite);
		break;
	}
}

void DoCState(FILE *pfRead, FILE *pfWrite, State* ps)//C注释状态
{
	int first = fgetc(pfRead);
	switch (first)
	{
	case '*':
	{
		int second = fgetc(pfRead);
		if (second == '/')//舍弃 */
		{
		int third = fgetc(pfRead);
		*ps = NUL_STATE;
		if (third != '\n')
		{
			fputc('\n', pfWrite);
			ungetc(third, pfRead);//ungetc函数的功能是将已读数据还回缓冲区
		}
		if (third == '\n')
		{
			fputc(third, pfWrite);
		}
		}
		else
		{
			fputc(first, pfWrite);
			ungetc(second, pfRead);//将*之后的内容还回缓冲区
		}
	}
		break;
	case '\n'://如果是换行，那就是连续注释，就将下一行开头加入Cpp注释
	{
		fputc(first, pfWrite);
		fputc('/', pfWrite);
		fputc('/', pfWrite);
	}
		break;
	/*case EOF:
	{
		fputc(first, pfWrite);
		*ps = END_STATE;
	}
		break;*/
	default:
	{
		fputc(first, pfWrite);
	}
		break;
	}
}

void DoCppState(FILE* pfRead, FILE* pfWrite, State* ps)//C++状态
{
	int first = fgetc(pfRead);
	switch (first)
	{
	case '\n'://Cpp注释的换行就是一行注释的结束
	{
		*ps = NUL_STATE;
		fputc(first, pfWrite);
	}
		break;
	case EOF:
	{
		*ps = END_STATE;
	}
		break;
	default:
	{
		fputc(first, pfWrite);
	}
		break;
	}

}

void CommentConvert(FILE* pfRead, FILE *pfWrite)
{
	State state = NUL_STATE;//一开始选择无状态
	while (state != END_STATE)
	{
		switch (state)
		{
		case NUL_STATE:
			DoNulState(pfRead, pfWrite, &state);
			break;
		case C_STATE:
			DoCState(pfRead, pfWrite, &state);
			break;
		case CPP_STATE:
			DoCppState(pfRead, pfWrite, &state);
			break;
		default:
			break;
		}
	}
}

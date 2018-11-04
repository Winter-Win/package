#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "CommentConvert.h"


void DoNulState(FILE* pfRead, FILE* pfWrite, State* ps)//����״̬
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
			*ps = C_STATE;//�����Cע�����ǽ�״̬��ΪC״̬�����ҽ�ע�Ϳ�ͷ��ΪCppע��
			fputc('/', pfWrite);
			fputc('/', pfWrite);
		}
		break;
	case '/':
		{
			*ps = CPP_STATE;//�����Cppע�����ǽ�״̬��ΪCpp״̬
			fputc(first, pfWrite);
			fputc(second, pfWrite);
		}
		break;
	default://��������ֱ��д��
		fputc(first, pfWrite);
		fputc(second, pfWrite);
		break;
		}
	}
		break;
	case EOF:
		*ps = END_STATE;//ע�ͽ�����״̬����
		break;
	default://��ʼ��Ϊ�������ݣ�ֱ��д��
		fputc(first, pfWrite);
		break;
	}
}

void DoCState(FILE *pfRead, FILE *pfWrite, State* ps)//Cע��״̬
{
	int first = fgetc(pfRead);
	switch (first)
	{
	case '*':
	{
		int second = fgetc(pfRead);
		if (second == '/')//���� */
		{
		int third = fgetc(pfRead);
		*ps = NUL_STATE;
		if (third != '\n')
		{
			fputc('\n', pfWrite);
			ungetc(third, pfRead);//ungetc�����Ĺ����ǽ��Ѷ����ݻ��ػ�����
		}
		if (third == '\n')
		{
			fputc(third, pfWrite);
		}
		}
		else
		{
			fputc(first, pfWrite);
			ungetc(second, pfRead);//��*֮������ݻ��ػ�����
		}
	}
		break;
	case '\n'://����ǻ��У��Ǿ�������ע�ͣ��ͽ���һ�п�ͷ����Cppע��
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

void DoCppState(FILE* pfRead, FILE* pfWrite, State* ps)//C++״̬
{
	int first = fgetc(pfRead);
	switch (first)
	{
	case '\n'://Cppע�͵Ļ��о���һ��ע�͵Ľ���
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
	State state = NUL_STATE;//һ��ʼѡ����״̬
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

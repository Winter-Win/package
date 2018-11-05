#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define DEFAULT_SZ 3

#define NAME_MAX 20
#define SEX_MAX 5
#define TELE 12
#define ADDR 30
#define MAX 1000

typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE];
	char addr[ADDR];
}PeoInfo;

//��̬�ļ��汾
typedef struct Contact
{
	PeoInfo *data;//�������
	int sz;//��ǰ������Ϣ�ĸ���
	int capacity;//��ǰ�������
}Contact, *pContact;



void InitContact(pContact pc);
void DestroyContact(pContact pc);

void AddContact(pContact pc);
void ShowContact(pContact pc);
void DelContact(pContact pc);
void SearchContact(pContact pc);
void ModifyContact(pContact pc);
void SortContact(pContact pc);
void EmptyContact(pContact pc);
void SaveContact(pContact pc);
void LoadContact(pContact pc);


#endif  // __CONTACT_H__
#ifndef _TEACHER_H_
#define _TEACHER_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "Teacher.h"
#pragma warning (disable:4996)
typedef struct Teacher {
	char Teacher_id[1024];
	char Teacher_depatment[1024];
	char Teacher_name[1024];
	char Teacher_mail[1024];
	char Password[1024];
}Teacher;
bool Check_mail( char* Teacher_mail ) {
	int status=0,tem1=0,tem2=0,tem3=0;
	while (Teacher_mail[tem1]!='\0')
	{
		tem1++;
	}
	if (tem1>19)
	{
		return false;
	}
	for (int i = 0; i < tem1; i++)
	{
		tem2 = i - 1;
		tem3 = i + 1;
		if (Teacher_mail[i]=='@')
		{
			if (i==0 || i==tem1)
			{
				return false;
			}
			else if (Teacher_mail[tem2]=='.'|| Teacher_mail[tem3] == '.')
			{
				return false;
			}
			else
			{
				status++;
			}
		}
		
			if (Teacher_mail[i] == '.')
			{	
				if (status != 1) return false;
				if (i == (tem1 - 1))
				{
					return false;
				}
				else
				{
					status++;
				}
			}
		}
	if (status != 2)
	{
		return false;
	}
	return true;
}
bool Check_password(Teacher* Teacher) {
	int tem = 0;
	while (Teacher->Password[tem]!='\0')
	{
		tem++;
	}
	if (tem>8 && tem<20)
	{
		return true;
	}
	else {
		return false;
	}
	
}
void PrintOut_teacher_information() {};
char* Edit_teacher_information( Teacher* Teacher ) {
	char tem[1024];
	int tem_number;
	printf("ÊäÈë1ÐÞ¸ÄÓÊÏä£¬ÊäÈë2ÐÞ¸ÄÃÜÂë¡£\n");
	scanf("%s",tem);
	if (isdigit(tem[1]))
	{
		tem_number = atoi(tem);
		if (tem_number==1||tem_number==2)
		{
			if (tem_number==1)
			{
				printf("ÇëÊäÈëÐÂÓÊÏä£º\n");
				scanf("%s",Teacher->Teacher_mail);
				if (Check_mail(Teacher->Teacher_mail))
				{
					return Teacher->Teacher_mail;
				}
				else
				{
					return NULL;
				}
				
			}
			else
			{
				printf("ÇëÊäÈëÐÂÃÜÂë£º\n");
				scanf("%s", Teacher->Password);
				if (Check_password(Teacher))
				{
					return Teacher->Password;
				}
				else
				{
					return NULL;
				}
			}
		}
		else
		{
			printf("Error!");
			Edit_teacher_information(Teacher);
		}
	}
	else
	{
		printf("Error!");
		Edit_teacher_information(Teacher);
	}
	return NULL;
}
#endif // !1



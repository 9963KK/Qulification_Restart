#ifndef _CLASSSECTION_H_
#define _CLASSSECTION_H_
#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
bool StatusClass_ifstart;
char* TransfoCharacter;
char* TransfoDepartment;
char* TransfoTimerange;
char* TransfoLocation;
 struct Week_day {
	int WeekayDay;
	struct Week_day* Week_day;
};
 struct Textbook_introduction
 {
	 char book_name[1024];
	 char specific_information[1024];
 };
 struct TimeRange {
	 int Year_Start;
	 int Year_End;
	 int Semster;
	 int Week_Start;
	 int Week_End;
	 int Range; 
 };
 struct Location
 {
	 int Building_Number;
	 int Room_Number[3];
 };
 struct Student_information{
	 char Student_id[10];
	 char Student_department[1024];
	 char Student_major[1024];
	 char Student_name[1024];
	 char Student_gender[1024];
	 char Student_phone[1024];
	 char Student_mail[1024];
	 struct Student_information* Next;
 };
 struct ClassSection {
	 char Class_id[7];
	 int Class_menmber_now;
	 int Class_member;
	 char Class_name[1024];
	 int Class_department;
	 int Class_score;
	 bool Class_character;
	 char Class_teacher[1024];
	 struct TimeRange Class_time;
	 struct Week_day Week_day;
	 char Class_introduction[1024];
	 struct Textbook_introduction Class_textbook_introduction;
	 struct Location Location;
	 struct ClassSection* Next;
 };

 struct Student_information* CreateList_student_informtion() {
	 struct Student_information* Student_information = (struct Student_information*)malloc(sizeof(struct Student_information));
	 Student_information->Next = NULL;
	 return Student_information;
 };
 void Add_student_information(struct Student_information* Student_information) {
	 Student_information->Next=CreateList_student_informtion();
 }
 struct ClassSection* CreateList_classsection() {
	 struct ClassSection* ClassSection = (struct ClassSection*)malloc(sizeof(struct ClassSection));
	 ClassSection->Next = NULL;
	 return ClassSection;
 };
 void Add_classsection(struct ClassSection* ClassSection) {
	 ClassSection->Next = CreateList_classsection();
 };
 struct Status
 {
	 struct Student_information Student_information;
 };
	int Judge_Class_id(char* arr) {
		int i = 0;
		while (!(arr[i]=='/0'))
		{
			if (isdigit(arr[i])) {
				continue;
			}
			else
			{
				printf("Error!");
				break;
			}
			i++;
		}
		return i;
	}
	bool Judge_Class_member(struct ClassSection* ClassSection){
		if (ClassSection->Class_member==80||ClassSection->Class_member==100)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void ClassDelete(struct ClassSection* ClassSection) {
		struct ClassSection* p = ClassSection;
		while (p->Next != NULL) {
			if (p->Next->Class_member < 30)
			{
				struct ClassSection* tem = p->Next;
				p->Next = p->Next->Next;
				free(tem);
			}
		}
	};
	void ClassAdd(struct ClassSection* ClassSection,struct ClassSection* New_classcection) {
		struct ClassSection* p = ClassSection;
		do
		{
			p->Next = p->Next->Next;
		} while (p->Next!=NULL);
		p->Next = New_classcection;
	}
	char* Transfo_character(struct ClassSection* ClassSection) {
		if (ClassSection->Class_character)
		{
			strcpy(TransfoCharacter,"必修");
		}
		else {
			strcpy(TransfoCharacter, "选修");
		}
		return TransfoCharacter;
	};
	char* Transfo_department(struct ClassSection* ClassSection) {
		switch (ClassSection->Class_department)
		{
		case 0: strcpy(TransfoDepartment, "a院"); break;
		case 1: strcpy(TransfoDepartment, "b院"); break;
		default:
			break;
		}
		return TransfoDepartment;
	};
	char* Transfo_timerange(struct ClassSection* ClassSection) {
		switch (ClassSection->Class_time.Range)
		{
		case 0: strcpy(TransfoTimerange , "8:00-8:50"); break;
		case 1: strcpy(TransfoTimerange , "9:00-9:50"); break;
		case 2: strcpy(TransfoTimerange, "10:00-10:50"); break;
		case 3: strcpy(TransfoTimerange, "11:00-11:50"); break;
		case 4: strcpy(TransfoTimerange, "1:30-2:30"); break;
		case 5: strcpy(TransfoTimerange, "2:30-3:20"); break;
		case 6: strcpy(TransfoTimerange, "3:30-4:20"); break;
		case 7: strcpy(TransfoTimerange, "4:30-5:20"); break;
		case 8: strcpy(TransfoTimerange, "6:30-7:20"); break;
		case 9: strcpy(TransfoTimerange, "7:30-8:20"); break;
		default:
			break;
		}
		return TransfoTimerange;
	};
	char* Transfo_location(struct ClassSection* ClassSection) {
		char Room[1024];
		itoa(ClassSection->Location.Building_Number,Room,1024);
		strcat(Room, "-");
		for (int i = 0; i < 3; i++)
		{
			char tem[1024] ;
			itoa(ClassSection->Location.Room_Number[i], tem, 1024);
			strcat(Room,tem);
		}
		TransfoLocation = Room;
		return TransfoLocation;
	}
	int Member_delete(struct ClassSection* ClaassSection) {
		ClaassSection->Class_menmber_now--;
		int Member_left = ClaassSection->Class_member - ClaassSection->Class_menmber_now;
		return Member_left;
	}
	int Member_add(struct ClassSection* ClassSection) {
		ClassSection->Class_menmber_now++;
		int Member_left = ClassSection->Class_member - ClassSection->Class_menmber_now;
		return Member_left;
	}
	void PrintOut(struct ClassSection* ClassSection) {
		char* Class_character = Transfo_character(ClassSection);
		char* Class_deparment = Transfo_department(ClassSection);
		char* TimeRange = Transfo_timerange(ClassSection);
		FILE* file;
		if ((file = fopen("info.txt", "w+")) == NULL)
			printf("can't open the file! \n");
		else
			fprintf(file, "%-s,     %-5d,     %-5d,     %s,     %s,     %-5d,     %-s,     %-s,     %-s,     %-5d,     %-s,     %-s,     %-s,     %-s ", 
				ClassSection->Class_id, ClassSection->Class_menmber_now,
				ClassSection->Class_member, ClassSection->Class_name, Class_deparment, ClassSection->Class_score, Class_character, ClassSection->Class_teacher, TimeRange,
				ClassSection->Week_day.WeekayDay, ClassSection->Class_introduction,ClassSection->Class_textbook_introduction.book_name ,
				ClassSection->Class_textbook_introduction.specific_information); //将数据格式化输出到文件info.txt中

		//fscanf(file, "%s, %d, %d, %s, %s, %d, %s, %s, %s, %s, %s, %s, %s ", ClassSection->Class_id, ClassSection->Class_menmber_now,
			//ClassSection->Class_member, ClassSection->Class_name, Class_deparment, ClassSection->Class_score, Class_character, ClassSection->Class_teacher, TimeRange,
			//ClassSection->Week_day.WeekayDay, ClassSection->Class_introduction, ClassSection->Class_textbook_introduction); //从文件info.txt中格式化读取数据
		//printf("%d, %s, %c \n", num, name, gender); //格式化输出到屏幕
		fclose(file);
	};
	
	/*void fff(struct ClassSection* ClassSction) {
		FILE* file;
		if ((file=fopen("xxx.txt","r+"))==NULL)
		{
			printf("sdas");
		}
		else
		{
			fprintf(file, "%s", ClassSction->Class_id);
		}
		fscanf(file,"%s",ClassSction->Class_id);
		printf("%s",ClassSction->Class_id);
		fclose(file);
	}*/
	
	/*char Class_id[6];
	int Class_menmber_now;
	int Class_member;
	char Class_name[1024];
	int Class_department;
	int Class_score;
	bool Class_character;
	char Class_teacher[1024];
	struct TimeRange Class_time;
	struct Week_day Week_day;
	char Class_introduction[1024];
	struct Textbook_introduction Class_textbook_introduction;
	struct Location;*/
#endif 

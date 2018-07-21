//#define _CRT_SECURE_NO_WARNINGS
//#include <stddef.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include<conio.h>
//#include<malloc.h>
//#include<string.h>
//#include<math.h>
//
//struct student{
//	char name[100];
//	int *marks;
//};
//
//void storeMarks(student *s, char *buff){
//	int temp = 0, k = 0;
//	for (int i = 0; buff[i] != '\0'; i++){
//		if (buff[i] != ',' && buff[i] != '\n'){
//			temp = temp * 10 + (buff[i] - 48);
//		}
//		else{
//			s->marks[k] = temp;
//			k++;
//			temp = 0;
//
//		}
//	}
//}
//
//void storeSub(char **s, char *buff){
//	int k = 0, j = 0;
//	for (int i = 0; buff[i] != '\0'; i++){
//		if (buff[i] != ','&& buff[i] != '\n'){
//			s[j][k++] = buff[i];
//		}
//		else{
//			s[j][k] = '\0';
//			j++;
//			k = 0;
//		}
//	}
//
//}
//
//
//void storeName(char *s, char *buff){
//	int i;
//	for (i = 0; buff[i] != '\0'&& buff[i] != '\n'; i++){
//		s[i] = buff[i];
//	}
//	s[i] = '\0';
//}
//
//int findIndexStudent(student **st, int *count,char *name){
//	for (int i = 0; i < *count; i++){
//		if (strcmp(st[i]->name, name)==0)
//			return i;
//	}
//	return -1;
//}
//int findIndexSubject(char **sub, int *n, char *subname){
//	for (int i = 0; i < *n; i++){
//		if (strcmp(sub[i], subname)==0)
//			return i;
//	}
//	return -1;
//}
//
//
//int readStudentName(student **st, int *count, int *n, char **sub){
//	char *name = (char*)malloc(sizeof(char) * 100);
//loop:
//	printf("enter student name\n");
//	scanf("%s", name);
//
//	int index = findIndexStudent(st, count, name);
//
//	if (index == -1){
//		printf("Enter valid name\n");
//		goto loop;
//	}
//
//	return index;
//}
//
//int readSubjectName(student **st, int *count, int *n, char **sub){
//	char *name = (char*)malloc(sizeof(char) * 100);
//loop:
//	printf("enter subject name\n");
//	scanf("%s", name);
//	int index = findIndexSubject(sub,n,name);
//	if (index == -1){
//		printf("Enter valid name\n");
//		goto loop;
//	}
//	return index;
//}
//
//void showAll(student **st, int *count, int *n, char **sub){
//	printf("Name\t\t\t");
//	for (int i = 0; i < *n; i++)
//		printf("%s\t", sub[i]);
//	printf("\n");
//	for (int x = 0; x < *count; x++){
//		printf("%s\t\t\t", st[x]->name);
//
//		for (int j = 0; j < *n; j++){
//			printf("%d\t", st[x]->marks[j]);
//		}
//		printf("\n");
//	}
//
//}
//
//void aStudentMarks(student **st, int *count, int *n, char **sub){
//	int index = readStudentName(st, count, n, sub);
//	printf("%s\n", st[index]->name);
//	for (int i = 0; i < *n; i++){
//		printf("%s------", sub[i]);
//		printf("%d\n", st[index]->marks[i]);
//	}
//
//}
//void aSubjectAStudent(student **st, int *count, int *n, char **sub){
//	int index = readStudentName(st, count, n, sub);
//	int indexSub = readSubjectName(st, count, n, sub);
//	
//	printf("%s\n", st[index]->name);
//	printf("%s \t %d\n\n", sub[indexSub], st[index]->marks[indexSub]);
//
//}
//
//void maxStudentMarks(student **st, int *count, int *n, char **sub){
//	int index = readStudentName(st, count, n, sub);
//	int max = 0;
//	int indexMax = -1;
//	for (int i = 0; i < *n; i++){
//		if (st[index]->marks[i] >= max){
//			max = st[index]->marks[i];
//		}
//	}
//	printf("\n%s\n", st[index]->name);
//
//	for (int i = 0; i < *n; i++){
//		if (max == st[index]->marks[i])
//		printf("%s \t %d\n", sub[i], st[index]->marks[i]);
//	}
//	
//}
//void avgStudentMarks(student **st, int *count, int *n, char **sub){
//	int index = readStudentName(st, count, n, sub);
//	int sum = 0;
//	for (int i = 0; i < *n; i++){
//		sum += st[index]->marks[i];
//	}
//	float avg = sum / (*n);
//	printf("%s\n", st[index]->name);
//	printf("avg  =  %f\n", avg);
//}
//
//void aSubjectAllStudents(student **st, int *count, int *n, char **sub){
//	int indexSub = readSubjectName(st, count, n, sub);
//	printf("%s\n", sub[indexSub]);
//	for (int i = 0; i < *count; i++){
//		printf("%s---", st[i]->name);
//		printf("%d\n", st[i]->marks[indexSub]);
//	}
//
//}
//
//char *toStr(int x){
//		char *str = (char*)malloc(sizeof(char) * 20);
//		int len = 0,i;
//		int n = x;
//		while (n != 0){
//			len++;
//			n /= 10;
//		}
//		for ( i = 1; i <= len; i++)
//		{
//			str[len - i] = (x % 10) + '0';
//			x /= 10;
//		}
//	
//		str[i - 1] = '\0';
//		return str;
//}
//void addStudent(student **st, int *count, int *n, char **sub,FILE *fp){
//	char *name = (char*)malloc(sizeof(char) * 100);
//	int *marks = (int*)malloc(sizeof(int) * (*n));
//	char *submarks = (char*)calloc(100,sizeof(char));
//	printf("enter student name\n");
//	scanf("%s", name);
//	fprintf(fp, "%s\n", name);
//	printf("Enter marks:\n");
//	for (int i = 0; i < *n-1; i++){
//		printf("%s ", sub[i]);
//		scanf("%d", &marks[i]);
//		fprintf(fp, "%d,", marks[i]);
//	}
//	printf("%s ", sub[*n-1]);
//	scanf("%d", &marks[(*n)-1]);
//	fprintf(fp, "%d\n", marks[(*n)-1]);
//	
//	
//	(*count) += 1;
//
//	st = (struct student**)realloc(st,(*count + 1)*sizeof(struct student*));
//	st[*count - 1] = (struct student*)malloc(sizeof(struct student));
//	st[*count - 1]->marks = (int *)malloc(sizeof(int)*(*n + 10));
//
//	storeName(st[*count - 1]->name, name);
//	for (int i = 0; i < *n; i++){
//		st[*count - 1]->marks[i] = marks[i];
//	}
//
//
//	fclose(fp);
//
//}
//
//
//void chooseMenu(student **st,int *count,int *n,char **sub,FILE *fp){
//	int choice;
//	do{
//		printf("1)Show List of All students and his marks\n\n2)Get all subject marks for a student");
//		printf("\n\n3)Fetch a particular subject marks for a student\n\n4)Fetch Maximum marks a student got in all subjects");
//		printf("\n\n5)Fetch the Average marks a student got\n\n6)fetch marks of all students,of a particular subject\n\n");
//		printf("7)addition of a student and his subject marks\n\n");
//		printf("8)Quit\n");
//		printf("Enter your choice\n");
//		scanf("%d", &choice);
//
//
//
//		switch (choice){
//		case 1:
//			showAll(st, count, n, sub);
//			break;
//
//		case 2:
//			aStudentMarks(st, count, n, sub);
//			break;
//		case 3:
//			aSubjectAStudent(st, count, n, sub);
//			break;
//		case 4:
//			maxStudentMarks(st, count, n, sub);
//			break;
//		case 5:
//			avgStudentMarks(st, count, n, sub);
//			break;
//		case 6:
//			aSubjectAllStudents(st, count, n, sub);
//			break;
//		case 7:
//			addStudent(st, count, n, sub,fp);
//			break;
//		case 8:
//			exit;
//			break;
//
//		default:
//			printf("enter right choice\n");
//			break;
//		}
//	} while (choice != 8);
//
//
//}
//
//int main(){
//
//	FILE *fp = fopen("SampleFile_StudentsMarksSystem.txt", "r+");
//	int count = 0, n;
//	char * buff = (char*)malloc(sizeof(char) * 255);
//	while ((fgets(buff, 255, (FILE*)fp)) != NULL){
//		count++;
//	}
//	count = (count / 2) - 1;
//
//	fclose(fp);
//	fp = fopen("SampleFile_StudentsMarksSystem.txt", "r+");
//
//	struct  student **st = (struct student**)malloc(sizeof(struct student*)*(count + 1));
//
//	fscanf(fp, "%d", &n);
//
//	printf("%d\n\n", n);
//
//	for (int i = 0; i < (count + 1); i++){
//		st[i] = (struct student*)malloc(sizeof(struct student));
//		st[i]->marks = (int *)malloc(sizeof(int)*(n + 10));
//	}
//
//	char  **sub = (char**)malloc(sizeof(char*)*n);
//	for (int i = 0; i < n; i++){
//		sub[i] = (char*)malloc(sizeof(char) * 100);
//	}
//
//	fgets(buff, 255, (FILE*)fp);
//	fgets(buff, 255, (FILE*)fp);
//	//printf("%s",buff);
//	//strore buff in sub array
//	storeSub(sub, buff);
//
//	for (int i = 0; i < n; i++)
//		printf("%s ", sub[i]);
//	printf("\n\n");
//
//
//	int i = 0;
//	while ((fgets(buff, 255, (FILE*)fp) != NULL)){
//		storeName(st[i]->name, buff);
//		fgets(buff, 255, (FILE*)fp);
//		storeMarks(st[i], buff);
//		i++;
//	}
//
//
//	//Testing whether data is properly stored or not
//	for (int x = 0; x < i; x++){
//		printf("%s ", st[x]->name);
//
//		for (int j = 0; j < n; j++){
//			printf("%d ", st[x]->marks[j]);
//		}
//		printf("\n\n");
//	}
//
//
//	chooseMenu(st, &count, &n, sub,fp);
//	fclose(fp);
//
//	_getch();
//	return 0;
//}
//

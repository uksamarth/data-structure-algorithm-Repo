#include<stdio.h>

struct student
{
    char name[20];
    int rollno;
    double cgpa;
};
void display(FILE *fp)
{
    struct student s;
    while(fscanf(fp,"%d%s%lf",&s.rollno,s.name,&s.cgpa)==3)
    {
        if(s.cgpa>=8.5)
        {
            printf("%d\t%s\t%lf\n",s.rollno,s.name,s.cgpa);
        }
    }
}
int main()
{
    FILE *fp;
    fp=fopen("student.txt","r");
    if(fp==NULL)
    {
        printf("Error");
        return 0;
    }
    display(fp);
    fclose(fp);
    return 0;
}

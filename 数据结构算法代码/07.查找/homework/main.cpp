#include <stdio.h>
#include <stdlib.h>
struct Student
{
    int id;
    char name[100];
    int score;
};
int main()
{
    int i=0,j;
    Student student[4]=
    {
        {1024,"С����",100},
        {1026,"����б��",60},
        {1028,"��ҹ",100},
        {1030,"��;",60}
    };
    printf("������Ҫ��ѯ��ѧ�ţ�");
    scanf("%d",&j);
    while(student[i].id!=j && i<4)
    {
        i++;
    }
    printf("ѧ��Ϊ%d\n",j);
    printf("����Ϊ%s\n",student[i].name);
    printf("�ɼ�Ϊ%d\n",student[i].score);
    return 0;
}


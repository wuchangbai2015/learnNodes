#include <stdio.h>
#include <stdlib.h>
struct Student
{
    int id;
    char name[100];
    int score;
};
int Sq_Srearch(int *a,int n,int key)
{
    int i=n;
    a[0]=key;
    while(a[i]!=key)
    {
        i--;
    }
    return i;
}
int main()
{
    int i,j;
    Student student[4]=
    {
        {1024,"С����",100},
        {1026,"����б��",60},
        {1028,"��ҹ",100},
        {1030,"��;",60}
    };
    printf("������Ҫ��ѯ��ѧ�ţ�");
    scanf("%d",&j);
    i=Sq_Srearch(*student.id,4,int j);
    printf("ѧ��Ϊ%d\n",j);
    printf("����Ϊ%c\n",student.name[i]);
    printf("�ɼ�Ϊ%d\n",student.score[i]);
    return 0;
}

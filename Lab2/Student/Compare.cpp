#include "Compare.h"

int CompareName(Student A,Student B)
{
    int i=0;
    char *nameA,*nameB;
    nameA = A.GetName();
    nameB = B.GetName();
    while(nameA[i] != '\0' && nameB[i] != '\0')
    {
        if(nameA[i] > nameB[i])
            return 1;
        else if(nameA[i] < nameB[i])
            return -1;
        i++;
    }
    if(nameA[i]!='\0') return 1;
    if(nameB[i]!='\0') return -1;
    return 0;
}
int CompareMath(Student A,Student B)
{
    float gradeA, gradeB;
    gradeA = A.GetMathGrade();
    gradeB = B.GetMathGrade();
    if(gradeA > gradeB) return 1;
    if(gradeA < gradeB) return -1;
    return 0;
}
int CompareEnglish(Student A,Student B)
{
    float gradeA, gradeB;
    gradeA = A.GetEnglishGrade();
    gradeB = B.GetEnglishGrade();
    if(gradeA > gradeB) return 1;
    if(gradeA < gradeB) return -1;
    return 0;
}
int CompareHistory(Student A,Student B)
{
    float gradeA, gradeB;
    gradeA = A.GetHistoryGrade();
    gradeB = B.GetHistoryGrade();
    if(gradeA > gradeB) return 1;
    if(gradeA < gradeB) return -1;
    return 0;
}
int CompareAverage(Student A,Student B)
{
    float gradeA, gradeB;
    gradeA = A.AverageGrade();
    gradeB = B.AverageGrade();
    if(gradeA > gradeB) return 1;
    if(gradeA < gradeB) return -1;
    return 0;
}

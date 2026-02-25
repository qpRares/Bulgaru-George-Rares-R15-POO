#include "Student.h"
#include "Compare.h"
#include <stdio.h>
using namespace std;

int main()
{
    Student S,A;
    S.SetName("Armando");
    printf("%s\n",S.GetName());
    S.SetEnglishGrade(5);
    S.SetHistoryGrade(7);
    S.SetMathGrade(10);
    printf("%f\n",S.GetEnglishGrade());
    printf("%f\n",S.GetHistoryGrade());
    printf("%f\n",S.GetMathGrade());
    printf("%f",S.AverageGrade());
    A.SetName("Alejandro");
    printf("\n");
    printf("%s\n",A.GetName());
    A.SetEnglishGrade(10);
    A.SetHistoryGrade(8);
    A.SetMathGrade(7);
    printf("%f\n",A.GetEnglishGrade());
    printf("%f\n",A.GetHistoryGrade());
    printf("%f\n",A.GetMathGrade());
    printf("%f\n",A.AverageGrade());

    printf("%d\n",CompareName(S,A));
    printf("%d\n",CompareEnglish(S,A));
    printf("%d\n",CompareHistory(S,A));
    printf("%d\n",CompareMath(S,A));
    printf("%d\n",CompareAverage(S,A));
    return 0;
}

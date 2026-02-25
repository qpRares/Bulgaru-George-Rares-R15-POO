#include "Student.h"

void Student::SetName(char name[])
{
    int i=0;
    while(name[i] != '\0')
    {
        this->name[i] = name[i];
        i++;
    }
    this->name[i] = '\0';
}
char* Student::GetName()
{
    return name;
}
bool Student::SetMathGrade(float grade)
{
    if(grade < 1 || grade > 10) return false;
    Math = grade;
    return true;
}
float Student::GetMathGrade()
{
    return Math;
}
bool Student::SetEnglishGrade(float grade)
{
    if(grade < 1 || grade > 10) return false;
    English = grade;
    return true;
}
float Student::GetEnglishGrade()
{
    return English;
}
bool Student::SetHistoryGrade(float grade)
{
    if(grade < 1 || grade > 10) return false;
    History = grade;
    return true;
}
float Student::GetHistoryGrade()
{
    return History;
}
float Student::AverageGrade()
{
    return ( GetMathGrade()+GetEnglishGrade()+GetHistoryGrade() ) /3;
}

#pragma once

class Student
{
    char name[300];
    float Math,English,History;
public:
    void SetName(char name[]);
    char* GetName();
    bool SetMathGrade(float grade);
    float GetMathGrade();
    bool SetEnglishGrade(float grade);
    float GetEnglishGrade();
    bool SetHistoryGrade(float grade);
    float GetHistoryGrade();
    float AverageGrade();

};

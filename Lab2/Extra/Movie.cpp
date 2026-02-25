#include "Movie.h"

bool Movie::set_name(char name[])
{
    int i=0;
    while(name[i]!='\0')
        i++;
    if(i>256)
        return false;
    i=0;
    while(name[i]!='\0')
    {
        this->name[i] = name[i];
        i++;
    }
    this->name[i] = '\0';
    return true;
}

char* Movie::get_name()
{
    return name;
}

void Movie::set_year(int year)
{
    this->year = year;
}

int Movie::get_release_year()
{
    return year;
}

bool Movie::set_score(double score)
{
    if( score < 1 || score > 10 ) return false;
    this->score = score;
    return true;
}

double Movie::get_score()
{
    return score;
}

void Movie::set_length(int minutes)
{
    this->length = minutes;
}

int Movie::get_length()
{
    return length;
}

int Movie::PassedYears()
{
    return 2026 - this->get_release_year();
}

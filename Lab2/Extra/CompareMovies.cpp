#include "CompareMovies.h"

int movie_compare_name(Movie A, Movie B)
{
    char *nameA, *nameB;
    nameA = A.get_name();
    nameB = B.get_name();
    int i=0;
    while(nameA[i]!='\0' && nameB[i]!='\0')
    {
        if(nameA[i] > nameB[i])
            return 1;
        if(nameA[i] < nameB[i])
            return -1;
        i++;
    }
    if(nameA[i]!='\0')
        return 1;
    if(nameB[i]!='\0')
        return -1;
    return 0;
}
int movie_compare_year(Movie A, Movie B)
{
    int yearA, yearB;
    yearA = A.get_release_year();
    yearB = B.get_release_year();

    if(yearA > yearB)
     return 1;
    if(yearA < yearB)
     return -1;
    return 0;
}
int movie_compare_score(Movie A, Movie B)
{
    double scoreA, scoreB;
    scoreA = A.get_score();
    scoreB = B.get_score();

    if(scoreA > scoreB)
     return 1;
    if(scoreA < scoreB)
     return -1;
    return 0;
}
int movie_compare_length(Movie A, Movie B)
{
    int lengthA, lengthB;
    lengthA = A.get_length();
    lengthB = B.get_length();

    if(lengthA > lengthB)
     return 1;
    if(lengthA < lengthB)
     return -1;
    return 0;
}
int movie_compare_passed_years(Movie A, Movie B)
{
    int yearA, yearB;
    yearA = A.PassedYears();
    yearB = B.PassedYears();

    if(yearA > yearB)
     return 1;
    if(yearA < yearB)
     return -1;
    return 0;
}

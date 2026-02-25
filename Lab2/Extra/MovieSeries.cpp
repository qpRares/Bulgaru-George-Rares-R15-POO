#include "MovieSeries.h"
#include <stdio.h>

void MovieSeries::init()
{
    count = 0;
}
void MovieSeries::add(Movie *M)
{
    movies[count] = M;
    count++;
}
void MovieSeries::sort()
{
    for(int i=0;i<count;i++)
        for(int j=i;j<count;j++)
            if(movies[i]->get_release_year() > movies[j]->get_release_year())
    {
        Movie* aux;
        aux = movies[i];
        movies[i] = movies[j];
        movies[j] = aux;
    }
}
void MovieSeries::print()
{
    for(int i=0;i<count;i++)
        printf("name: %s | score: %d  | year: %d | length: %d | passed years: %d\n",
               movies[i]->get_name(),
               movies[i]->get_release_year(),
               movies[i]->get_score(),
               movies[i]->get_length(),
               movies[i]->PassedYears());

}

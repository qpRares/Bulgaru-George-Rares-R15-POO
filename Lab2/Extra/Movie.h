#pragma once

class Movie
{
    char name[256];
    int year;
    double score;
    int length;
public:
    bool set_name(char name[]);
    char* get_name();
    void set_year(int year);
    int get_release_year();
    bool set_score(double score);
    double get_score();
    void set_length(int minutes);
    int get_length();
    int PassedYears();
};

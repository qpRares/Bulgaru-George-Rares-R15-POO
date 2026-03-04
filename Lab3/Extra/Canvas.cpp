#include "Canvas.h"
#include <iostream>
#include <cstdarg>
Canvas::Canvas(int lines,int columns)
{
    this->lines = lines;
    this->columns = columns;
    this->canvas = new char*[lines];
    for(int i=0; i<lines; i++)
        canvas[i] = new char[columns];
    this->clear();
}

void Canvas::set_pixel(int x,int y,char value)
{
    this->canvas[x][y] = value;
}

void Canvas::set_pixels(int count, ...)
{
    va_list args;
    va_start(args, count);

    while(count)
    {
        int x = va_arg(args, int);
        int y = va_arg(args, int);
        int value = va_arg(args, int);

        this->set_pixel(x,y,value);
        count --;
    }
    va_end(args);
}
void Canvas::clear()
{
     for(int i=0; i<this->lines; i++)
        for(int j=0; j<this->columns; j++)
            this->canvas[i][j] = ' ';
}

void Canvas::print() const
{
    for(int i=0; i<this->lines; i++,std::cout<<'\n')
        for(int j=0; j<this->columns; j++)
            std::cout<<canvas[i][j]<<' ';
}

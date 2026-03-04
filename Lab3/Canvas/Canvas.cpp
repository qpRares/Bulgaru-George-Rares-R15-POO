#include "Canvas.h"
#include <iostream>
Canvas::Canvas(int width,int height)
{
    this->width = width;
    this->height = height;
    this->canvas = new char*[height];
    for(int i=0; i<height; i++)
        canvas[i] = new char[width];
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            this->canvas[i][j] = ' ';
}

void Canvas::DrawCircle(int x,int y,int ray,char ch)
{
    for(int i=0; i<this->height; i++)
        for(int j=0; j<this->width; j++)
            if( abs((j-x)*(j-x) + (i-y)*(i-y) - ray*ray) <= ray )
                this->canvas[i][j] = ch;
}

void Canvas::FillCircle(int x,int y,int ray,char ch)
{
    for(int i=0; i<this->height; i++)
        for(int j=0; j<this->width; j++)
            if( (j-x)*(j-x) + (i-y)*(i-y) <= ray*ray)
                if(this->canvas[i][j] == ' ')
                    this->canvas[i][j] = ch;
}

void Canvas::DrawRect(int left,int top,int right,int bottom, char ch)
{
    for(int i=0; i<this->height; i++)
        for(int j=0; j<this->width; j++)
            if(j >= left && j <= right && i >= top  && i <= bottom && (i == top || i == bottom || j == left || j == right))
                this->canvas[i][j] = ch;
}

void Canvas::FillRect(int left,int top,int right,int bottom, char ch)
{
    for(int i=0; i<this->height; i++)
        for(int j=0; j<this->width; j++)
            if(j >= left && j <= right && i >= top  && i <= bottom && !(i == top || i == bottom || j == left || j == right))
                this->canvas[i][j] = ch;
}

void Canvas::SetPoint(int x,int y,char ch)
{
    this->canvas[y][x] = ch;
}

void Canvas::DrawLine(int x1,int y1,int x2,int y2,char ch)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx;
    if (x1 < x2)
        sx = 1;
    else
        sx = -1;

    int sy;
    if (y1 < y2)
        sy = 1;
    else
        sy = -1;

    int err = dx - dy;

    while (true)
    {
        if (x1 >= 0 && x1 < width && y1 >= 0 && y1 < height)
            canvas[y1][x1] = ch;

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err = err - dy;
            x1 = x1 + sx;
        }

        if (e2 < dx)
        {
            err = err + dx;
            y1 = y1 + sy;
        }
    }
}
void Canvas::Print()
{
    for(int i=0; i<this->height; i++,std::cout<<'\n')
        for(int j=0; j<this->width; j++)
            std::cout<<this->canvas[i][j]<<' ';
}

void Canvas::Clear()
{
     for(int i=0; i<this->height; i++)
        for(int j=0; j<this->width; j++)
            this->canvas[i][j] = ' ';
}

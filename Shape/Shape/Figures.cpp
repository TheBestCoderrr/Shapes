#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "Figures.h"
#include "String.h"

size_t Square::marker = 0;

void Square::save() const
{
    ofstream fcout("Shapes.txt", ios::app);
    if (!fcout.is_open()) return;
    fcout << "square" << endl;
    fcout << x << ' ' << y << ' ' << a << endl;
    fcout.close();
}

void Square::load(const char* filename)
{
    ifstream fcin(filename);
    if (!fcin.is_open()) return;
    String text;
    for (size_t i = 0; i < marker; i++)
        fcin >> text;
    bool is_finded = 0;
    for (;is_finded == false && !fcin.eof();) {
        fcin >> text;
        if (text == "square") is_finded = 1;
        marker++;
    }
    if (is_finded) {
        fcin >> x >> y >> a;
        marker++;
    }
    fcin.close();
}

size_t Rectangle::marker = 0;

void Rectangle::save() const
{
    ofstream fcout("Shapes.txt", ios::app);
    if (!fcout.is_open()) return;
    fcout << "rectangle" << endl;
    fcout << x << ' ' << y << ' ' << a << ' ' << b <<  endl;
    fcout.close();
}

void Rectangle::load(const char* filename)
{
    ifstream fcin(filename);
    if (!fcin.is_open()) return;
    String text;
    for (size_t i = 0; i < marker; i++)
        fcin >> text;
    bool is_finded = 0;
    for (; is_finded == false && !fcin.eof();) {
        fcin >> text;
        if (text == "rectangle") is_finded = 1;
        marker++;
    }
    if (is_finded) {
        fcin >> x >> y >> a >> b;
        marker++;
    }
    fcin.close();
}

size_t Circle::marker = 0;

void Circle::save() const
{
    ofstream fcout("Shapes.txt", ios::app);
    if (!fcout.is_open()) return;
    fcout << "circle" << endl;
    fcout << x << ' ' << y << ' ' << R << endl;
    fcout.close();
}

void Circle::load(const char* filename)
{
    ifstream fcin(filename);
    if (!fcin.is_open()) return;
    String text;
    for (size_t i = 0; i < marker; i++)
        fcin >> text;
    bool is_finded = 0;
    for (; is_finded == false && !fcin.eof();) {
        fcin >> text;
        if (text == "circle") is_finded = 1;
        marker++;
    }
    if (is_finded) {
        fcin >> x >> y >> R;
        marker++;
    }
    fcin.close();
}

size_t Ellipse::marker = 0;

void Ellipse::save() const
{
    ofstream fcout("Shapes.txt", ios::app);
    if (!fcout.is_open()) return;
    fcout << "ellipse" << endl;
    fcout << x << ' ' << y << ' ' << x2 << ' ' << y2 << endl;
    fcout.close();
}

void Ellipse::load(const char* filename)
{
    ifstream fcin(filename);
    if (!fcin.is_open()) return;
    String text;
    for (size_t i = 0; i < marker; i++)
        fcin >> text;
    bool is_finded = 0;
    for (; is_finded == false && !fcin.eof();) {
        fcin >> text;
        if (text == "ellipse") is_finded = 1;
        marker++;
    }
    if (is_finded) {
        fcin >> x >> y >> x2 >> y2;
        marker++;
    }
    fcin.close();
}




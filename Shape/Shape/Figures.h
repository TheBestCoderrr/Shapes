#pragma once
#include <iostream>
using namespace std;

__interface I2Dfigure {
    void print() const;
    void save() const;
    void load(const char* filename);
};

class Shape : public I2Dfigure {
public:
    void print() const override { cout << "( " << x << "," << y << ")" <<  endl; }
    Shape() : Shape(0, 0) {}
    Shape(int x, int y) : x(x), y(y) {}
protected:
    int x;
    int y;
};

class Square : public Shape {
public:
    void print() const override { cout << "Square: ( " << x << "," << y << ")\ta = " << a << endl; }
    Square() : Shape(), a(0) {}
    Square(int x, int y, double a) : Shape(x, y), a(a) {}
    void save() const override;
    void load(const char* filename) override;
    static size_t marker;
protected:
    double a;
};

class Rectangle : public Square {
public:
    void print() const override { cout << "Rectangle: ( " << x << "," << y << ")\ta = " << a << " b = " << b << endl; }
    Rectangle() : Square(), b(0) {}
    Rectangle(int x, int y, double a, double b) : Square(x, y, a), b(b) {}
    void save() const override;
    void load(const char* filename) override;
protected:
    double b;
static size_t marker;
};

class Circle : public Shape {
public:
    void print() const override { cout << "Circle: ( " << x << "," << y << ")\tR = " << R << endl; }
    Circle() : Shape(0, 0), R(0) {}
    Circle(int x, int y, double R) : Shape(x, y), R(R) {}
    void save() const override;
    void load(const char* filename) override;
private:
    double R;
static size_t marker;
};

class Ellipse : public Shape{
public:
    void print() const override { cout << "Ellipse: ( " << x << "," << y << ")\tx2 = " << x2 << " y2 = " << y2 << endl; }
    Ellipse(int x, int y, double x2, double y2) : Shape(x, y), x2(x2), y2(y2) {}
    void save() const override;
    void load(const char* filename) override;
protected:
    int x2, y2;
static size_t marker;
};


#include "Figures.h"

Shape* CreateShape() {
    int n = rand() % 4 + 1;
    switch (n) {
    case 1:
        return new Square(rand() % 100, rand() % 100, rand() % 100);
        break;
    case 2:
        return new Rectangle(rand() % 100, rand() % 100, rand() % 100, rand() % 100);
        break;
    case 3:
        return new Circle(rand() % 100, rand() % 100, rand() % 100);
        break;
    case 4:
        return new Ellipse(rand() % 100, rand() % 100, rand() % 100, rand() % 100);
        break;
    }
}

int main() {
    srand(time(0));
    size_t n;
    cout << "Enter size: ";
    cin >> n;
    Shape** Shapes = new Shape * [n];
    for (size_t i = 0; i < n; i++) {
        Shapes[i] = CreateShape();
        Shapes[i]->save();
        Shapes[i]->print();
    }
    for (size_t i = 0; i < n; i++)
        delete Shapes[i];
    delete[] Shapes;
    cout << endl;

    Shape** loadShapes = new Shape * [n];
    for (size_t i = 0; i < n; i++) {
        loadShapes[i] = CreateShape();
        loadShapes[i]->load("Shapes.txt");
        loadShapes[i]->print();
    }
    for (size_t i = 0; i < n; i++)
        delete loadShapes[i];
    delete[] loadShapes;
}
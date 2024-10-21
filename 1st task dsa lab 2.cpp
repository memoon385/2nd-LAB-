#include<iostream>
#include<cmath>
using namespace std;
class shape {
public:
    virtual double area() const = 0;
    virtual~shape() {}
};

class Circle :public shape {

private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area()  const override {
        return 3.14 * radius * radius;

    }
};
class Rectangle :public shape {
private:
    double length;
    double width;
public:
    Rectangle(double L, double W) : length(L), width(W) {}
    double area() const override {
        return length * width;
    }
};
int main()
{
    Circle c(10.1);
     cout << "circle area:" << c.area() << endl;

    Rectangle r(5.5, 6.6);
    cout << "rectangle Area:" << r.area() << endl;
    return 0;
}

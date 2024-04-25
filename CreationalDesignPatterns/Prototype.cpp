// Instead of creating new objects from scratch, the Prototype Pattern lets us create new ones by copying an existing prototype. 
// This is especially handy when those objects share a lot of similarities.

#include <iostream>

// abstract class
class Shape
{
    public:
    virtual ~Shape() {}
    virtual void draw() const = 0;
    virtual Shape* clone() const = 0;
};

// Concrete classes
class Circle : public Shape
{
    public:
    Circle(int r) : radius(r) {}
    
    void draw() const override
    {
        std::cout << "Circle class draw method \n";
    }
    
    Shape* clone() const override
    {
        return new Circle(*this);
    }
    
    private:
    int radius;
    
};

class Rectangle : public Shape
{
    public:
    Rectangle(int l, int w) : length(l), width(w) {}
    void draw() const override
    {
        std::cout << "Rectangle class draw method \n";
    }
    Shape* clone() const override
    {
        return new Rectangle(*this);
    }
    
    private:
    int length, width;
    
    
};
int main() {
    
    Circle circlePrototype(5.0);
    Rectangle rectanglePrototype(4.0, 6.0);
    
    Shape* shape1 = circlePrototype.clone();
    Shape* shape2 = rectanglePrototype.clone();
    
    shape1->draw();
    shape2->draw();
    
    delete shape1;
    delete shape2;



    return 0;
}
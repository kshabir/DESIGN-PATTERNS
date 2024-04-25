// Best Comment: It's best suitable if you want to use only one family (only variants of family)
// e.g under logistics you can create logistics related to sea, frieght, air etc.

/*Factory Method Pattern provides an interface for creating objects but leaves the actual object instantiation to derived classes*/

#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;

// Product
class Shape
{
    public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
    public:
    void draw() override
    {
        std::cout<< "You're drawing Circle Class \n" << std::endl;
    }
    
};

class Square : public Shape
{
    public:
    void draw() override
    {
        std::cout<< "You're drawing Square Class" << std::endl;
    }
    
};

class Rect : public Shape
{
    public:
    void draw() override
    {
        std::cout<< "You're drawing Rectangle Class" << std::endl;
    }
    
};

// Abstract Factory creator
class ShapeFactory
{
    public:
    virtual Shape* createShape() = 0;
    virtual ~ShapeFactory() {}
};

// Concreate Creators --> override method
class CircleFactory : public ShapeFactory
{
    public:
    Shape* createShape() override
    {
        return new Circle();
    }
};

class SquareFactory : public ShapeFactory
{
    public:
    Shape* createShape() override
    {
        return new Square();
    }
};

class RectFactory : public ShapeFactory
{
    public:
    Shape* createShape() override
    {
        return new Rect();
    }
};


int main() 
{
    /*
    ShapeFactory* circleFactory = new CircleFactory();
    ShapeFactory* squareFactory = new SquareFactory();
    
    Shape* circle = circleFactory->createShape();
    Shape* square = squareFactory->createShape();
    
    circle->draw();
    square->draw();
    
    delete circleFactory;
    delete squareFactory;
    delete circle;
    delete square;
    */
    
    // Client code based on user input --> get input from user and then draw the asked shape
    string inputShape;
    
    cout << "Input which shape you wanna draw \n";
    cin >> inputShape;
    transform(inputShape.begin(), inputShape.end(), inputShape.begin(), ::tolower);
    ShapeFactory* shapeFactory = nullptr;
    
    if(inputShape == "circle")
    {
        shapeFactory = new CircleFactory();
        
    }
    else if (inputShape == "square")
    {
        shapeFactory = new SquareFactory();
    }
    else if (inputShape == "rect")
    {
        shapeFactory = new RectFactory();
    }
    else{
        cout << "Wrong shape is given!!";
        return 1;
    }
    
    Shape* shape = shapeFactory->createShape();
    shape->draw();
    
    delete shape;
    delete shapeFactory;
    
    return 0;
}
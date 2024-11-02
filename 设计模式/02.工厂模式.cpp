#include <iostream>
#include <map>
#include <memory>
#include <string>

class Shape {
public:
    virtual ~Shape() {}
    virtual std::string draw() const = 0;
};

class Circle : public Shape {
public:
    std::string draw() const override {
        return "Drawing a Circle";
    }
};
class Square : public Shape {
public:
    std::string draw() const override {
        return "Drawing a Square";
    }
};

class ShapeCreator {
public:
    virtual Shape* createShape() const = 0;
};

class CircleCreator : public ShapeCreator {
public:
    Shape* createShape() const override {
        return new Circle();
    }
};

class SquareCreator : public ShapeCreator {
public:
    Shape* createShape() const override {
        return new Square();
    }
};


int main() {
    std::map<std::string, std::unique_ptr<ShapeCreator>> creators;
    creators["C"] = std::make_unique<CircleCreator>();
    creators["S"] = std::make_unique<SquareCreator>();

    std::string shapeType;
    std::cout << "Enter the shape type: C[circle]/S[square]";
    std::cin >> shapeType;

    auto it = creators.find(shapeType);
    if (it != creators.end()) {
        // 创建形状
        std::unique_ptr<Shape> shape = std::unique_ptr<Shape>(it->second->createShape());
        std::cout << shape->draw() << std::endl;
    } else {
        std::cout << "Unknown shape type!" << std::endl;
    }

    return 0;
}

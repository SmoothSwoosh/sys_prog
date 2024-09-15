#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <functional>
#include <sstream>
#include <algorithm>

class Figure {
public:
    virtual double get_square() const = 0;
    virtual std::string to_string() const = 0;
    virtual ~Figure() = default;
};

class Rectangle: public Figure {
    double a, b;
public:
    static Rectangle *make(const std::string &info) {
        Rectangle *res = new Rectangle;
        sscanf(info.c_str(), "%lf %lf", &res->a, &res->b);
        return res;
    }

    std::string to_string() const override {
        char buf[4096];
        sprintf(buf, "%lf %lf", a, b);
        return buf;
    }

    double get_square() const override {
        return a * b;
    }
};

class Square: public Figure {
    double a;
public:
    static Square *make(const std::string &info) {
        Square *res = new Square;
        sscanf(info.c_str(), "%lf", &res->a);
        return res;
    }

    std::string to_string() const override {
        char buf[4096];
        sprintf(buf, "%lf", a);
        return buf;
    }

    virtual double get_square() const override {
        return a * a;
    }
};

class Circle: public Figure {
    double r;
public:
    static Circle *make(const std::string &info) {
        Circle *res = new Circle;
        sscanf(info.c_str(), "%lf", &res->r);
        return res;
    }
    virtual double get_square() const override {
        return M_PI * r * r;
    }

    std::string to_string() const override {
        char buf[4096];
        sprintf(buf, "%lf", r);
        return buf;
    }
};

//Singleton Factory
class Factory {
private:
    Factory(){};
public:
    static Factory &factory_instance() {
        static Factory instance;
        return instance;
    }

    Factory(Factory const &) = delete;
    void operator=(Factory const &) = delete;

    static Figure *make(const std::string &operation, const std::string &numbers) {
        std::map<std::string, std::function<Figure *(const std::string &)>> dict;

        {
            //filling a dict with the make-functions
            dict["R"] = Rectangle::make;
            dict["C"] = Circle::make;
            dict["S"] = Square::make;
        }

        return dict[operation](numbers);
    }
};

int main() {
    std::vector<Figure *> figures;

    std::string input; //for taking lines from the input
    while(std::getline(std::cin, input)) {
        std::string operation, numbers;
        std::stringstream sstream(input); //making a stringstream from the input line

        sstream >> operation; //parsing the input line
        std::getline(sstream, numbers); //getting numbers

        Figure *fig = Factory::factory_instance().make(operation, numbers); //making new figure
        figures.push_back(fig);
    }

    //comparator for figures
    auto cmp = [](Figure *fig1, Figure *fig2) {
        return fig1->get_square() < fig2->get_square();
    };

    //sorting figures by their own squares
    stable_sort(figures.begin(), figures.end(), cmp);

    //printing the result
    for (auto &elem : figures) {
        std::cout << elem->to_string() << std::endl;
    }

    //deallocating the memory
    for (auto &elem : figures) {
        delete elem;
    }

    return 0;
}

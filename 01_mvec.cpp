#include <qc2ga/Mvec.hpp>
#include <iostream>

using namespace qc2ga;

Mvec<double> Io() {
    return (e01<double>() - e02<double>()) ^ e02<double>();
}

Mvec<double> Iinf() {
    return (ei1<double>() - ei2<double>()) ^ ei2<double>();
}

Mvec<double> einf() {
    return 1/2 * (ei1<double>() + ei2<double>());
}

Mvec<double> vector_generator(double x, double y) {
    Mvec<double> p;
    p = 1 + x * e1<double>() + y * e2<double>() + x * x / 2 * ei1<double>() + y * y / 2 * ei2<double>() + x * y * ei3<double>();

    return p;
}

int main() {
    // Empty multivector
    Mvec<double> mv1;
    std::cout << "Empty multivector: " << mv1 << std::endl;
    
    // Initialization and component access
    mv1 = 5 * e1<double>() - 5 * e2<double>();
    std::cout << "Initialized multivector: " << mv1 << std::endl;

    // Component access
    std::cout << mv1[E1] << std::endl;
    
    // Grade
    std::cout << "Grade: " << mv1.grade() << std::endl;

    // Point
    Mvec<double> Io;
    Io = (e01<double>() - e02<double>()) ^ e02<double>();

    Mvec<double> p1, p2;
    p1 = vector_generator(0, 0);
    p2 = vector_generator(2, 0);
    //Mvec<double> p3 = p1 ^ p2 ^ Io;
    Mvec<double> p3 = (p1 ^ p2 ^ einf() ^ Iinf());

    Mvec<double> p4, p5;
    p4 = vector_generator(1, 0);
    p5 = vector_generator(1, 1);
    //Mvec<double> p6 = p4 ^ p5 ^ Io;
    Mvec<double> p6 = (p4 ^ p5 ^ einf() ^ Iinf());

    Mvec<double> inter = (p3.dual() ^ p6.dual()).dual();
    //Mvec<double> inter = p3 ^ p6;
    
    Mvec<double> p;
    p = vector_generator(1, 1);
    
    std::cout << "Point 3: " << p3 << std::endl;
    std::cout << "Point 6: " << p6 << std::endl;
    std::cout << "Intersection: " << inter << std::endl;
    std::cout << "Point: " << p << std::endl;
}


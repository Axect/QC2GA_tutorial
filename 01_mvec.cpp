#include <qc2ga/Mvec.hpp>
#include <iostream>

using namespace qc2ga;

int main() {
    // Empty multivector
    Mvec<double> mv1;
    std::cout << "Empty multivector: " << mv1 << std::endl;
    
    // Initialization and component access
    mv1 = 5 * e1<double>() - 5 * e2<double>();
    std::cout << "Initialized multivector: " << mv1 << std::endl;
}

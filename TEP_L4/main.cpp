#include <iostream>
#include "CError.h"   
#include "CResult.h"
#include "UserInterface.h"

CResult<double, CError> eDivide(double a, double b)
{
    if (b == 0)
        return CResult<double, CError>::cFail(new CError("division by zero"));

    return CResult<double, CError>::cOk(a / b);
}

int main()
{
    /*CResult<double, CError> r = eDivide(10, 0);

    if (r.bIsSuccess())
        std::cout << "Result: " << r.cGetValue() << std::endl;
    else
        std::cout << "Error: " << r.vGetErrors()[0]->strGetMessage() << std::endl;

    std::cout << "Koniec programu. Nacisnij Enter..." << std::endl;
    std::cin.get(); */
    //UI().run();
    char tab[] = { 'h','e','l','l','o',' ','w','o','r','l','d', '\0' };
    CResult<std::string, CError> test = CResult<std::string, CError>::cOk(tab);
    CResult<std::string, CError> test2 = CResult<std::string, CError>::cFail(new CError("b³¹d 123"));
    std::cout << test.cGetValue();
    test2.printErrors();
    return 0;
}
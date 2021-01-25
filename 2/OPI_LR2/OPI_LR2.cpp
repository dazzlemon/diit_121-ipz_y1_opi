
#include <iostream>
#include "funcs.h"
#include "inp_val7.h"

int main() {
    func funcs[3]{func1, func2, func3};
    
    bool exit_ = true;
    int choice;
    do {
        system("cls");
        std::cout << "1) 1/(b(abc+a+c))-(1/(a+1/(b+1/c))):(1/(a+1/b))" << std::endl;
        std::cout << "a - arg1, b - arg2, c - arg3" << std::endl;
        std::cout << "2) (x^(2/m)-9x^(2/n))(x^((1-m)/m)-3x^((1-n)/n))/((x^(1/m)+3x^(1/n))^2-12x^((m+n)/(mn)))" << std::endl;
        std::cout << "x - arg1, m - arg2, n - arg3" << std::endl;
        std::cout << "3) (a^(1/m)-a^(1/n))^2*4a^((m+n)/(mn))/((a^(2/m)-a^(2/n))(a^(m+1)+a^((n+1)/n))^(1/m))" << std::endl;
        std::cout << "a - arg1, m - arg2, n - arg3" << std::endl;

        choice = cinum("choose which function you want to calculate: ", "Wrong input, try again", 1, 1, 1, 3);

        void *arg1 = NULL, *arg2 = NULL, *arg3 = NULL, *result = NULL;//null to avoid error
        TYPE type = chooseType();
        switch (type) {
        case int_: {
            arg1 = new int;
            arg2 = new int;
            arg3 = new int;
            result = new int;
            std::cout << "input arg1 = ";
            std::cin >> *static_cast<int*>(arg1);
            std::cout << "input arg2 = ";
            std::cin >> *static_cast<int*>(arg2);
            std::cout << "input arg3 = ";
            std::cin >> *static_cast<int*>(arg3);
            void* args[5]{ static_cast<void*>(&type), arg1, arg2, arg3, result };
            bool goodbit = funcs[choice - 1](args);
            if (goodbit)
                std::cout << "result = " << *static_cast<int*>(result) << std::endl;
            else
                std::cout << "Bad input" << std::endl;
            break;
        }
        case double_: {
            arg1 = new double;
            arg2 = new double;
            arg3 = new double;
            result = new double;
            std::cout << "input arg1 = ";
            std::cin >> *static_cast<double*>(arg1);
            std::cout << "input arg2 = ";
            std::cin >> *static_cast<double*>(arg2);
            std::cout << "input arg3 = ";
            std::cin >> *static_cast<double*>(arg3);
            void* args[5]{ static_cast<void*>(&type), arg1, arg2, arg3, result };
            bool goodbit = funcs[choice - 1](args);
            if (goodbit)
                std::cout << "result = " << *static_cast<double*>(result) << std::endl;
            else
                std::cout << "Bad input" << std::endl;
            break;
        }
        }
        delete arg1;
        delete arg2;
        delete arg3;
        delete result;
        
        char chExit;
        std::cout << "Do you want to exit the programm?(Y/N): ";
        std::cin >> chExit;
        while ((chExit != 'Y' && chExit != 'y' && chExit != 'N' && chExit != 'n') || (std::cin.peek() != '\n')) {//until correct input
            while (std::cin.get() != '\n');//clear istream
            std::cout << "wrong input, try again." << std::endl;
            std::cout << "Do you want to exit the programm?(Y/N): ";
            std::cin >> chExit;
        }
        if (chExit == 'Y' || chExit == 'y')
            exit_ = true;
        else
            exit_ = false;
        std::cin.get();//enter
    } while (!exit_);

    system("pause");
    return 0;
}
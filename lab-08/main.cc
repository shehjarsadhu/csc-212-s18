#include <iostream>
#include <cassert>
#include "darray.h"

void print(DArray* darr) {
    for (int i = 0; i < darr->size(); i++) {
        std::cout << darr->at(i) << ' ';
    } std::cout << std::endl;
}

int main(int argc, char** argv) {

    if (argc != 2) {

        /* Testing Constructor */
        DArray d1;
        DArray d2(15);
        assert(d1.capacity() == 10);
        assert(d2.capacity() == 15);
        assert(d1.size() == 0 && d2.size() == 0);

        /* Testing Modifiers and Accessors */
        for (int i = 1; i < 51; i++) {
            d1.push_back(i);
            d2.insert(i*i - 1, 0);
        }
        d1.set(100,0);
        assert(d1.pop_back() == 50);
        assert(d2.at(0) == 2499);
        assert(d1.size() == 49);
        assert(d1.at(0) == 100);
        assert(d1.pop_back() == 49);
        assert(d1.back() == 48);
        assert(d1.front() == 100);

    } else {

        DArray d1;
        DArray d2;
        for (int i = 0; i < 5; i++) {
            d1.push_back(i);
        }
        switch(atoi(argv[1])) {
            case 1:
                d1.at(-1);
                std::cout << "Method at() failed to validate" << std::endl;
                break;
            case 2:
                d1.at(5);
                std::cout << "Method at() failed to validate" << std::endl;
                break;
            case 3:
                d2.front();
                std::cout << "Method front() failed to validate" << std::endl;
                break;
            case 4:
                d2.back();
                std::cout << "Method back() failed to validate" << std::endl;
                break;
            case 5:
                d1.erase(-1);
                std::cout << "Method erase() failed to validate" << std::endl;
                break;
            case 6:
                d1.erase(5);
                std::cout << "Method erase() failed to validate" << std::endl;
                break;
            case 7:
                d1.set(0, -1);
                std::cout << "Method set() failed to validate" << std::endl;
                break;
            case 8:
                d1.set(0, 5);
                std::cout << "Method set() failed to validate" << std::endl;
                break;
            case 9:
                d2.pop_back();
                std::cout << "Method pop_back() failed to validate" << std::endl;
                break;
            case 10:
                d1.insert(0, -1);
                std::cout << "Method insert() failed to validate" << std::endl;
                break;
            case 11:
                d1.insert(0, 6);
                std::cout << "Method insert() failed to validate" << std::endl;
                break;
        }
    }


    return 0;
}

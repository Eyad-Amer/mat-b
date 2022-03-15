#include "mat.hpp"
#include <iostream>

using namespace ariel;



int main(){
        cout << mat(13, 5, '@', '-') << endl;
        cout << mat(7, 9, '@', '-') << endl;
        cout << mat(5, 1, '#', '*') << endl;
        cout << mat(1, 5, '#', '*') << endl;
        return 0;
    }
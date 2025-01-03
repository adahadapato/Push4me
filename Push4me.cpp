// Push4me.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "FileService.h"

int main(int argc, char* args[])
{
    try {


        // std::string _name = "C:\\sscean24\\Main_75\\4087525.004";
         //std::cout << "Hello World!\n"<< args[1];
        std::unique_ptr<FileService> _fileService = std::make_unique<FileService>();
        std::string _fileName(args[1]);

        //std::cout << "Hello !\n" << _fileName;
        //std::cin.get();
        _fileService->Action(_fileName);
        //  _fileService->Action(_name);
         //std::cout << "Hello World!\n";
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

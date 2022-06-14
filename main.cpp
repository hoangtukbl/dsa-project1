#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include "algorithm_mode.h"
#include "comparison_mode.h"

using namespace std;

int main(int argc, char *argv[]){
    string temp1 = argv[1];
    if(temp1 == "-a")
        AlgorithmMode( argc ,argv);
    else if(temp1 == "-c")
        ComparisonMode(argc,argv);
    else    
        cout << "wrong input";
        //ll
    return 0;
}   
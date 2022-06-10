#include "algorithm_mode.h"

int output_order(string order){
    if(order == "-time")
        return 0;
    if(order == "-comp")
        return 1;
    if(order == "-both")
        return 2;
    return -1;
}

void cout_output(int order){
    switch (order)
    {
    case 0:{
        cout<<"Running time: "<<endl;
        break;
    }
    case 1:{
        cout<<"Comparisions: "<<endl;
        break;
    }
    case 2:{
        cout<<"Running time: "<<endl;
        cout<<"Comparisions: "<<endl;
        break;
    }
    
    default:{
        cout << "wrong input";
        break;
    }
    }
}

int input_order(string order){
    if(order == "-rand")
        return 0;
    if(order == "-nsorted")
        return 1;
    if(order == "-sorted")
        return 2;
    if(order == "-rev")
        return 3;
    return -1;

}

void cout_input(int order){
    switch (order)
    {
    case 0:{
        cout << "Input order:  Randomized data"<<endl;
        cout <<"---------------------------------"<<endl;
        break;
    }
    case 1:{
        cout << "Input order: Nearly sorted data" <<endl;
        cout <<"---------------------------------"<<endl;
        break;
    }
    case 2:{
        cout << "Input order: Sorted data"<<endl;
        cout <<"---------------------------------"<<endl;
        break;
    }
    case 3:{
        cout << "Input order: Reverse sorted data"<<endl;
        cout <<"---------------------------------"<<endl;
        break;
    }
    default:{
        cout << "Wrong input order";
        break;
        }
    }
}

int al_order(string order){
    if(order == "selection-sort")
        return 0;
    if(order == "insertion-sort")
        return 1;
    if(order == "bubble-sort")
        return 2;
    if(order == "heap-sort")
        return 3;
    if(order == "merge-sort")
        return 4;
    if(order == "quick-sort")
        return 5;
    if(order == "radix-sort")
        return 6;
    if(order == "shaker-sort")
        return 7;
    if(order == "shell-sort")
        return 8;
    if(order == "counting-sort")
        return 9;
    if(order == "flash-sort")
        return 10;
    return -1;
    
}

void cout_al(int order){
    switch (order)
    {
    case 0:{
        cout << "Algorithm: Selection Sort"  << endl;
        break;
    }
    
    case 1:{
        cout << "Algorithm: Insertion Sort"  << endl;
        break;
    }
    case 2:{
        cout << "Algorithm: Bubble Sort"  << endl;
        break;
    }
    case 3:{
        cout << "Algorithm: Heap Sort"  << endl;
        break;
    }
    case 4:{
        cout << "Algorithm: Merge Sort"  << endl;
        break;
    }
    
    case 5:{
        cout << "Algorithm: Quick Sort"  << endl;
        break;
    }
    case 6:{
        cout << "Algorithm: Radix Sort"  << endl;
        break;
    }
    case 7:{
        cout << "Algorithm: Shaker Sort"  << endl;
        break;
    }
    case 8:{
        cout << "Algorithm: Shell Sort"  << endl;
        break;
    }
    case 9:{
        cout << "Algorithm: Counting Sort"  << endl;
        break;
    }
    case 10:{
        cout << "Algorithm: Flash Sort"  << endl;
        break;
    }
    default:
        cout << "Wrong algorithm";
    }
}

void AlgorithmMode(int temp_argc ,char* temp_argv[]){
    
    // //test input
    // for (int i = 0 ; i < temp_argc ; i++)
    //     cout << temp_argv[i] << endl;
    
    cout << "ALGORITHM MODE " << endl ;
    
    int in_size = 0;
    string in_file_name;
    int al_name = al_order(temp_argv[2]);
    cout_al(al_name);
    int in_order = -1;
    int out_order = -1;

    //check command 2
    if(temp_argc == 6){
        in_size = atoi(temp_argv[3]);
        in_order = input_order(temp_argv[4]);
        out_order = output_order(temp_argv[5]);
        cout << "Input size: " << in_size<<endl;
        cout_input(in_order);
        cout_output(out_order);
    }
        
    else{
    
    //check la command3 hay command 1
    if(atoi(temp_argv[3])) //command3
    {
        in_size = atoi(temp_argv[3]);
        out_order = output_order(temp_argv[4]);
        cout << "Input size: "<<in_size<<endl;
        for(int i = 0 ; i < 4 ; i++ ){
            cout<<endl;
            cout_input(i);
            cout_output(out_order);
        }
    }
    else //command1 
    { 
        in_file_name = temp_argv[3];
        out_order = output_order(temp_argv[4]);
        cout << "Input file: "<<in_file_name << endl;
        cout << "Input size: "<<endl;
        cout << "---------------------------------------------"<<endl;
        cout_output(out_order);
    }
    

    }
    //cout << in_size << " " << in_order << " "<< in_file_name << " " << al_name << " " << out_order<<" ";
}
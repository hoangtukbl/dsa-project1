#include "comparison_mode.h"

void cout_2al(int order1 , int order2){
    cout << "Algorithm: ";
    switch (order1)
    {
    case 0:{
        cout << "Selection Sort"  ;
        break;
    }
    case 1:{
        cout << "Insertion Sort"  ;
        break;
    }
    case 2:{
        cout << "Bubble Sort"  ;
        break;
    }
    case 3:{
        cout << "Heap Sort"  ;
        break;
    }
    case 4:{
        cout << "Merge Sort"  ;
        break;
    }
    
    case 5:{
        cout << "Quick Sort"  ;
        break;
    }
    case 6:{
        cout << "Radix Sort"  ;
        break;
    }
    case 7:{
        cout << "Shaker Sort"  ;
        break;
    }
    case 8:{
        cout << "Shell Sort"  ;
        break;
    }
    case 9:{
        cout << "Counting Sort"  ;
        break;
    }
    case 10:{
        cout << "Flash Sort"  ;
        break;
    }
    default:
        cout << "Wrong algorithm";
    }
    cout << "  |  ";
    switch (order2)
    {
    case 0:{
        cout << "Selection Sort"  << endl;
        break;
    }
    case 1:{
        cout << "Insertion Sort"  << endl;
        break;
    }
    case 2:{
        cout << "Bubble Sort"  << endl;
        break;
    }
    case 3:{
        cout << "Heap Sort"  << endl;
        break;
    }
    case 4:{
        cout << "Merge Sort"  << endl;
        break;
    }
    
    case 5:{
        cout << "Quick Sort"  << endl;
        break;
    }
    case 6:{
        cout << "Radix Sort"  << endl;
        break;
    }
    case 7:{
        cout << "Shaker Sort"  << endl;
        break;
    }
    case 8:{
        cout << "Shell Sort"  << endl;
        break;
    }
    case 9:{
        cout << "Counting Sort"  << endl;
        break;
    }
    case 10:{
        cout << "Flash Sort"  << endl;
        break;
    }
    default:
        cout << "Wrong algorithm";
    }
}


void make_input_file(int order ,int size,string name)
{
    int* a = new int[size];

    GenerateData(a,size,order);

    ofstream inp;
    inp.open(name);
    inp << size << endl;
    for (int i = 0 ; i < size ; i++ ){
        inp << a[i] << " ";
    }
    inp.close();
}

void ComparisonMode(int temp_argc , char* temp_argv[]){

    cout << "COMPARE MODE"<<endl;
    int al_name1 = al_order(temp_argv[2]);
    int al_name2 = al_order(temp_argv[3]);
    cout_2al(al_name1,al_name2);

    //check command4 
    if(temp_argc == 5) {
        string file_name = temp_argv[4];
        cout << "Input file: "<<file_name<<endl;

        cout << "---------------------------------------------"<<endl;
        cout_output(2);
    }

    //check command5
    if(temp_argc == 6){
        int in_size = atoi(temp_argv[4]);
        int in_order = input_order(temp_argv[5]);
        cout << "Input size: " << in_size<<endl;
        cout_input(in_order);
        cout_output(2);
        make_input_file(in_order , in_size,"input.txt");

    }
}
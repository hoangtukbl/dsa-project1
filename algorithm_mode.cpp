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

void cout_comp(int al, int size, int * a){

    switch (al)
    {
    case 0:{
        // cout << a;
        SelectionSort_comp(a,size);
        break;
    } 
    case 1:{
        InsertionSort_comp(a, size);
        break;
    }
    case 2:{
        bubbleSort_comp(a, size);
        break;
    }
    case 3:{
        heapSort_comp(a, size);
        break;
    }
    case 4:{
        mergeSort_main_comp(a ,size);
        break;
    }
    case 5:{
        quickSort_comp(a, size);
        break;
    }
    case 6:{
        RadixSort_comp(a,size);
        break;
    }
    case 7:{
        ShakerSort_comp(a,size);
        break;
    }
    case 8:{
        shellSort_comp(a, size);
        break;
    }
    case 9:{
        CountingSort_comp(a,  size);
        break;
    }
    case 10:{
        FlashSort_comp(a, size);
        break;
    }
    default:
        cout << "Wrong algorithm";
    }

}

void cout_time(int al, int size, int * a){

    switch (al)
    {
    case 0:{
        // cout << a;
        SelectionSort_time(a,size);
        break;
    } 
    case 1:{
        InsertionSort_time(a, size);
        break;
    }
    case 2:{
        bubbleSort_time(a, size);
        break;
    }
    case 3:{
        heapSort_time(a, size);
        break;
    }
    case 4:{
        mergeSort_main_time(a ,size);
        break;
    }
    case 5:{
        quickSort_time(a, size);
        break;
    }
    case 6:{
        RadixSort_time(a,size);
        break;
    }
    case 7:{
        ShakerSort_time(a,size);
        break;
    }
    case 8:{
        shellSort_time(a, size);
        break;
    }
    case 9:{
        CountingSort_time(a,  size);
        break;
    }
    case 10:{
        FlashSort_time(a, size);
        break;
    }
    default:
        cout << "Wrong algorithm";
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

void cout_input(int order,int size,string name){
    switch (order)
    {
    case 0:{
        cout << "Input order:  Randomized data"<<endl;
        cout <<"---------------------------------"<<endl;
        int* a = new int[size];

        GenerateData(a,size,order);

        ofstream inp;
        inp.open(name);
        inp << size << endl;
        for (int i = 0 ; i < size ; i++ ){
            inp << a[i] << " ";
        }
        inp.close();

        delete a;
        break;
    }
    case 1:{
        cout << "Input order: Nearly sorted data" <<endl;
        cout <<"---------------------------------"<<endl;
        int* a = new int[size];

        GenerateData(a,size,order);

        ofstream inp;
        inp.open(name);
        inp << size << endl;
        for (int i = 0 ; i < size ; i++ ){
            inp << a[i] << " ";
        }
        inp.close();

        delete a;
        break;
    }
    case 2:{
        cout << "Input order: Sorted data"<<endl;
        cout <<"---------------------------------"<<endl;
        int* a = new int[size];

        GenerateData(a,size,order);

        ofstream inp;
        inp.open(name);
        inp << size << endl;
        for (int i = 0 ; i < size ; i++ ){
            inp << a[i] << " ";
        }
        inp.close();

        delete a;
        break;
    }
    case 3:{
        cout << "Input order: Reverse sorted data"<<endl;
        cout <<"---------------------------------"<<endl;
        int* a = new int[size];

        GenerateData(a,size,order);

        ofstream inp;
        inp.open(name);
        inp << size << endl;
        for (int i = 0 ; i < size ; i++ ){
            inp << a[i] << " ";
        }
        inp.close();

        delete a;
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
        cout << "Selection Sort"  ;
        break;
    }
    
    case 1:{
        cout << "Insertion Sort" ;
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
        cout << "Merge Sort" ;
        break;
    }
    
    case 5:{
        cout << "Quick Sort";
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
}

void AlgorithmMode(int temp_argc ,char* temp_argv[]){
    
    // //test input
    // for (int i = 0 ; i < temp_argc ; i++)
    //     cout << temp_argv[i] << endl;
    
    cout << "ALGORITHM MODE " << endl ;
    
    int in_size = 0;
    string in_file_name;
    int al_name = al_order(temp_argv[2]);
    cout << "Algorithm: ";
    cout_al(al_name);
    cout << endl;
    int in_order = -1;
    int out_order = -1;

    //check command 2
    if(temp_argc == 6){
        in_size = atoi(temp_argv[3]);
        in_order = input_order(temp_argv[4]);
        out_order = output_order(temp_argv[5]);
        cout << "Input size: " << in_size<<endl;
        cout_input(in_order,in_size,"input.txt");

        if(out_order == 0 || out_order == 2){
            int * a;
                a = read_input_file("input.txt");
            cout_time(al_name,in_size,a);

        }
        if(out_order == 1 || out_order == 2){
            int * a;
            a = read_input_file("input.txt");
            cout_comp(al_name,in_size,a);

        }
        
        
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
            string temp_name;
            switch (i)
            {
            case 0:{
                temp_name = "input_1.txt";
                break;
            }
            case 1:{
                temp_name = "input_2.txt";
                break;
            }
            case 2:{
                temp_name = "input_3.txt";
                break;
            }
            case 3:{
                temp_name = "input_4.txt";
                break;
            }
            
            default:
                break;
            }
            cout_input(i,in_size,temp_name);

            if(out_order == 0 || out_order == 2){
                int * a;
                a = read_input_file(temp_name);
            cout_time(al_name,in_size,a);
            }
            if(out_order == 1 || out_order == 2){
                int * a;
                a = read_input_file(temp_name);
                cout_comp(al_name,in_size,a);

            }
        }
    }
    else //command1 
    { 
        in_file_name = temp_argv[3];
        out_order = output_order(temp_argv[4]);

            ifstream inp_file;
            inp_file.open(in_file_name);

            int in_size ;
            inp_file >> in_size;
            inp_file.close();
            


        cout << "Input file: "<<in_file_name << endl;
        cout << "Input size: "<<in_size << endl;
        cout << "---------------------------------------------"<<endl;
        if(out_order == 0 || out_order == 2){int * a;
                a = read_input_file(in_file_name);
            cout_time(al_name,in_size,a);
        }
        if(out_order == 1 || out_order == 2){
            int * a;
            a = read_input_file(in_file_name);
            cout_comp(al_name,in_size,a);
        }
    }
    

    }
    //cout << in_size << " " << in_order << " "<< in_file_name << " " << al_name << " " << out_order<<" ";
}
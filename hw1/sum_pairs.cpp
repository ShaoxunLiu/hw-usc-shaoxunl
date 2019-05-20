#include<fstream>
#include<iostream>

int main(int argc, char* argv[]){
    if(argc < 3){
        std::cout << "Not enough files entered." << std::endl;
        return -1;
    }
    std::ifstream infile;
    infile.open(argv[1]);//open input file
    if(!infile.is_open()){
        std::cout << "Input file not opened." << std::endl;
        return -1;
    }

    std::ofstream outfile;
    outfile.open(argv[2]);//open output file
    if(!outfile.is_open()){
        std::cout << "Output file not opened." << std::endl;
        return -1;       
    }

    int numCount;
    infile >> numCount; // get number of ints
    if(infile.fail()){
        outfile << "0" << std::endl;
        return -1;
    }

    //dynamically allocate ints
    int* numList = new int[numCount];

    //add ints to numList
    for(int i = 0; i < numCount; i++){
        infile >> numList[i];
    }

    //out put numbers
    int nout = numCount / 2;
    for(int i = 0; i < nout; i++){
        outfile << numList[i] + numList[numCount - 1 - i] << std::endl;
    }

    if(numCount%2 == 1){
        outfile << numList[nout] * 2 << std::endl;
    }

    //delete allocated memory
    delete[] numList;

    return 0;

}
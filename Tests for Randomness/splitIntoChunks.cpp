#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

int main(){
    string input_file;
    cout << "Enter the name of the input file(without the extension):\t";
    cin >> input_file;
    int numberOfBins, sizeOfBins;
    cout << "Enter the number of bins and the size of each bin(in MB):\t";
    cin >> numberOfBins >> sizeOfBins;

    ifstream inputF(input_file + ".txt", ios::binary | ios::in);
    inputF.clear(); //Clears error state flag which might have been set due to improper closing of file
    if(inputF.fail()){
        cerr << "Couldn't open input file." << endl;
        return 0;        
    }
    
    long long b = sizeOfBins*(1000000); //NUmber of bits in each file
    int bit = 0;

    for(int i = 0; i < numberOfBins; ++i){
        long long tmp = 0;
        ofstream outputF(input_file + "_" + to_string(i) + "_" + to_string(sizeOfBins) + "MB");
        while(true){
            if(!inputF.eof()){
                bit = inputF.get();
                if(bit == -1) return 0;
                if(tmp == b) break;
                bit -= '0';
                ++tmp;
                outputF << bit;
            }
            else return 0;
        }
        outputF.close();
    }

    inputF.close();
    return 0;
}
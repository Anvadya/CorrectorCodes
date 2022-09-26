#include<iostream>
#include<fstream>
#include<string>

using namespace std;

// const string INPUT_FILE = "test1.txt";
// const string OUTPUT_FILE = "xor.txt";

int main(){
    string input_file, output_file;
    cout << "Enter the name of the input file:\t";
    cin >> input_file;
    cout << "Enter the name of the output file:\t";
    cin >> output_file;


    ifstream inputF(input_file, ios::binary | ios::in);
    inputF.clear(); //Clears error state flag which might have been set due to improper closing of file
    if(inputF.fail()){
        cerr << "Couldn't open input file." << endl;
        return 0;        
    }
    ofstream outputF(output_file);
    
    int bit1 = 0, bit2 = 0, res = 0;
    
    while(true){
        if(!inputF.eof()){ //inputF >> bit1;
            bit1 = inputF.get(); 
            if(bit1 == -1) break;
            bit1 -= '0';
        }
        else break;
        if(!inputF.eof()){ //inputF >> bit2;
            bit2 = inputF.get();
            if(bit2 == -1) break;
            bit2 -= '0';
        //    cout << "Bit2:\t" << (int)bit2 << endl;
        }
        else break;
        res = bit1 ^ bit2;
        // outputF << (res1);
        outputF << res;
    }

    inputF.close();
    outputF.close();
    return 0;
}
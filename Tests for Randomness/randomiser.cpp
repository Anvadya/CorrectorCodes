#include<iostream>
#include<fstream>
#include<string>

using namespace std;

// int random[16] = {12, 13, 7, 5, 4, 11, 0, 8, 6, 10, 9, 2, 3, 14, 15, 1};
int random[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};


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

    bool loop = true;
    int bits[16] = {0}, res = 0;
    int tmp = 0;

    while(loop){
        for(int i = 0; i < 16; ++i){
            if(!inputF.eof()){
                tmp = inputF.get();
                if(tmp == -1) goto out_of_loop;
                tmp -= '0';
                bits[i] = tmp;
            }
            else goto out_of_loop;
        }
        for(int i = 0; i < 16; ++i){
            res = bits[random[i]];
            outputF << res;
        }
    }

    out_of_loop:
    inputF.close();
    outputF.close();
    return 0;
}
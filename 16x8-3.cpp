#include<iostream>
#include<fstream>
#include<string>

using namespace std;

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
        for(int i = 0; i < 8; ++i){
            res = bits[i] ^ bits[(i+1)%8] ^ bits[(i+2)%7] ^ bits[(i+4)%8] ^bits[i+8];
            outputF << res;
        }
    }

    out_of_loop:
    inputF.close();
    outputF.close();
    return 0;
}
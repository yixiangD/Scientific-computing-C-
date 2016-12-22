#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#define MAX 100
using namespace std;

unsigned factorial(unsigned n)
{
    unsigned res = 1;
    for (int i = 1; i <= n; ++i)
    {
        res *= i;
    }
    return res;
}

int Multiply(int x,int num[], int num_size) {
    int digit = 0,times;
    for (int i = 0; i < num_size; i++) {
        times = num[i]*x + digit;
        num[i] = times % 10;
        digit = times/10;
    }
    while(digit != 0) {
        num[num_size] = digit % 10;
        digit = digit / 10;
        num_size++;
    }
    return num_size;      
}

void Factorial(int n) {
    int num[MAX] = {1},num_size = 1 ;
    for (int i = 2; i <= n; i++) {
        num_size = Multiply(i,num,num_size);
    }
    cout << n << "! = ";
    for (int i = num_size - 1; i >= 0; i--)
        cout << num[i];
    cout << endl;
}

int numFlag(string ele) {
    char arr[256], num0to9[10] = {'0','1','2','3','4','5','6','7','8','9'};
    strcpy(arr, ele.c_str());
    bool insFlag;
    int nFlag = 1;
    for (int i = 0; i < ele.length(); i++){
        insFlag = false;
        for (int j = 0; j < 10; j++){
            if (arr[i] == num0to9[j]){
                insFlag = true;
            }
        }
        if (insFlag == true)
            nFlag *= 1;
        else
            nFlag *= 0;
    }
    return nFlag;
}

int main()
{
    string input;
    getline(cin,input);
    string buf; 
    stringstream ss(input); 
    vector<string> tokens; 

    while (ss >> buf)
        tokens.push_back(buf);
    for (int i = 0;i < tokens.size(); i++){
        string ele = tokens[i];
        int nFlag = numFlag(ele);
        if (nFlag == 1) {
            unsigned n = stoi(ele);
            cout << n << "! = " << factorial(n) << endl;
            Factorial(n);
        }
        else {
            cout << "Warning: invalid input: " << ele << endl;
        }

    }

    return 0;
}

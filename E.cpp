#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<iostream>
#include<fstream>
#include<string>
#include <string.h>
#include <iomanip>
#include <ctime>


using namespace std;

typedef unsigned long long int mytype;

unsigned long long base = 1000000000000;

void setData(long long arrSize, mytype *arr, long long number){

    memset(arr,0,arrSize*sizeof(mytype));
    arr[0]=number;

}

void div(long long arrSize,mytype *arr, long long devider){


    mytype carry = 0;
    mytype cur;
    for (long long i=0;i<arrSize;i++){
        cur = (arr[i] + carry)/devider;
        carry = (arr[i] +carry) % devider * base;
        arr[i] = cur;
    }
}

void add(long long arrSize, mytype *arr1, mytype *arr2){
    for (long long i=arrSize-1;i>-1;i--){
        arr1[i] += arr2[i];
        if (arr1[i]>(base-1)){
            arr1[i-1] += arr1[i]/base;
            arr1[i] = arr1[i]%base;
        }
    }
}

bool isZero(long long arrSize, mytype *arr){
    for (long long i=0;i<arrSize;i++){
        if (arr[i]!=0){
            return false;
        }
    }
    return true;
}

int main()
{
    mytype arrSize,precision;
    cout<<"Enter the precision:"<<endl;
    cin>>precision;

    arrSize = precision/log10(base) + 2;

    mytype *e = new mytype[arrSize];
    mytype *uk = new mytype[arrSize];

    setData(arrSize,e,1);
    setData(arrSize,uk,1);

    long long k=1;
    while (!isZero(arrSize,uk)){
        div(arrSize,uk,k);
        add(arrSize,e,uk);
        k++;
    }


    ofstream myfile ("output.txt");
    if (myfile.is_open()) {
        myfile<<e[0]<<'.';
        for (long long i =1; i<arrSize-1;i++){
            myfile << setfill('0') << setw(12)<<e[i];
        }
        myfile.close();
    }

    return 0;
}




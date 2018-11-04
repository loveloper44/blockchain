#include<iostream>
#include<cmath>

using namespace std;


int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int getPub(int totient){
    int num = 2;
    while(num<totient && gcd(num,totient)!=1){
        num++;
    }
    return num;
}

int getPriv(int pub,int totient){
    int num = 1;
    
    while((num*pub)%totient!=1 || pub == num){
        num++;
    }
    
    return num;
}

int cal(int num, int index,int max){
    int result = num;
    while(--index){
        result = (result*num)%max;
    }
    return result;
}

void encrypt(int *arr, int length,int pub,int N){
    for(int i =0; i < length; i++){
        arr[i] = cal(arr[i],pub,N);
    }
}

void decrypt(int *arr, int length,int priv,int N){
    for(int i =0; i < length; i++){
        arr[i] = cal(arr[i],priv,N);
    }
}

void print(string title,int *arr,int length){
    cout <<title<<" ";
    for(int i =0; i < length; i++){
        cout << arr[i] <<" ";
    }
    cout <<endl;
}

void run(){
    int a= 13,b=11;
    int N = a*b;
    int totient = (a-1)*(b-1);
    
    int pub = getPub(totient);
    int priv = getPriv(pub,totient);
    
    int arr[] = {'C','L','O','U','D'};
    int LENGTH = 5;
    
    print("before : ", arr, LENGTH);
    encrypt(arr, LENGTH, pub, N);
    
    print("encrypt : ", arr, LENGTH);
    decrypt(arr, LENGTH, priv, N);
    
    print("decrypt : ", arr, LENGTH);
    
}


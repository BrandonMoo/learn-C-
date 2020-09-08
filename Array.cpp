#include<iostream>

using namespace std;

class Array{
public:
    Array(int len = 0);
    ~Array();
    int & operator[](int  i);
    const int & operator[](int  i)const;
    void display() const;
    int length() const;
private:
    int m_len;
    int * pa;
};

Array::Array(int len):m_len(len){
    if(len==0){
        pa = NULL;
    } else {
        pa = new int[len];
    }
}

Array::~Array(){
    delete[] pa;
}

int & Array::operator[](int i){
    return *(pa+i);
}

const int & Array::operator[](int i) const{
    return pa[i];
}

void Array::display()const{
    for(int i = 0; i < m_len; i++){
        cout<<pa[i]<<" ";
    }
    cout<<endl;
}

int Array::length()const{
    return m_len;
}

int main(){
    int n;
    cin>>n;
    Array A(n);
    for(int i = 0, len = A.length(); i < len; i++){
        A[i] = i * 5;
    }
    A.display();

    const Array B(n);
    int  j = n-1;
    cout<<B[j]<<endl;  //访问最后一个元素

    return 0;
}

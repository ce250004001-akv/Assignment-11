#include <iostream>
using namespace std;
struct Student{
    int age;
    string name, gender, branch;
};
int main(){
    Student *arr=new Student[100];
    cout<<"enter name , age , gender and branch for 2 student "<<endl;
    for(int i=0;i<2;i++){
        cin>>arr[i].name>>arr[i].age>>arr[i].gender>>arr[i].branch;
    }
    Student *temp=new Student[200];
    // cpy old data
    for (int i = 0; i < 100; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr=temp;
    for(int i=0;i<200;i++){
        cout<<arr[i].name<<" "<<arr[i].age<<" "<<arr[i].gender<<" "<<arr[i].branch<<endl;
    }
    delete[] arr;
}

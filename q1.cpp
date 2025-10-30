//Create an array of size 100 to store data elements conforming to  the sales figures of a grocery store. Resize the array subsequently to store 200 data elements.
#include <iostream>
#include <stdlib.h>
using namespace std;
int main(){
    int *ptr=(int*)malloc(100*sizeof(int));
    for(int i=0;i<100;i++){
        ptr[i]=i;
        /*    *ptr=i;
 You are modifying the pointer itself (ptr++), so by the end of the loop, ptr no longer points to the start of the array — it points past the end!Use a separate loop index, don’t increment ptr directly:*/   }
    ptr=(int*)realloc(ptr,200*sizeof(int));
    for(int i=100;i<200;i++){
        ptr[i]=i;
    }
    for(int i=0;i<200;i++){
        cout<<ptr[i]<<" ";
    }
    free(ptr);
}
#include <iostream>
using namespace std;
int main( )
{
    int num[4]={1,3,4,6};
    int *p1, *p2, *p3;

    p1=&num[1]; //p1 points at 3 (index 1)  &num[1]
    p2=num; // p2 points 1 (index 0)        &num[0]
    p3=p1; // p3 also points at 3 (index 1) &num[1]
    p1++; // p1 now points at 4 (index 2)   &num[2]

    cout<<"p1= "<<*p1<<" p2 = "<<*p2<<" p3 = "<<*p3<<endl;

    *p2=44; // value of index 0 changed to 44
    *(p1+1)=89; //value of index 3 changed to 89

    cout<<"p1 = "<<*p1<<" p2 = "<<*p2<<" p3 = "<<*p3<<endl;

    for (int count=0; count < 4; count++)
        cout<<"num["<<count<<"] = "<<num[count]<<endl;

    return 0;
}
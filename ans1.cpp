/*
1) Given a list of N elements, which follows no particular arrangement, you are required to search an
element x in the list. The list is stored using array data structure. If the search is successful, the output
should be the index at which the element occurs, otherwise returns -1 to indicate that the element is
not present in the list. Assume that the elements of the list are all distinct. Write a program to perform
the desired task.
*/

#include <iostream>
using namespace std;

int main()
{ 
    int n;
    cout<<"\nEnter the Size of Array: \n";
    cin>>n;
    int arr[n];
    cout<<"\nEnter values for array: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout<<"\nThe Values Entered for array are: \n";
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i]<<"  ";
    }
    int x;
    cout<<"\nEnter the element you want to search: \n";
    cin>>x;
    bool flag=false;
    for(int i ; i<n ; i++)
    {
        if(arr[i]==x)
        {
            flag=true;
            cout<<"\nElement found at "<< i <<" index. \n";
            break;
        }
    }
    if(flag==false)
        cout<<-1<<endl;


    return 0;
}

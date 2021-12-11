/*
2) Given a list of N elements, which is sorted in ascending order, you are required to search an element x
in the list. The list is stored using array data structure. If the search is successful, the output should be
the index at which the element occurs, otherwise returns -1 to indicate that the element is not present
in the list. Assume that the elements of the list are all distinct. Write a program to perform the desired
task.
*/

#include <iostream>
using namespace std;

int binary_search(int arr[], int left, int right, int number)
{
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(arr[mid]==number)
        {
            return mid;
        }
        else if(number>arr[mid])
        {
            left = mid +1;
        }
        else
        {
            right = mid -1;
        }
    
    }
    return -1;
}
int main()
{
    int size,search,pos;
    cout<<"\nEnter the size of array: \n";
    cin>>size;
    int arr[size];
    cout<<"\nEnter elements of array: \n";
    for(int i = 0; i<size; i++)
    {
        cin>>arr[i];
    }
    cout<<"\nThe Values Entered for array are: \n";
    for (int i = 0; i < size; i++)
    {
        cout<< arr[i]<<"  ";
    }
    cout<<"\nEnter the integer to be searched: ";
	cin>>search;
	pos= binary_search(arr, 0, size-1, search);
	cout<<"\nThe searched element ia at index: "<<pos<<endl;
}

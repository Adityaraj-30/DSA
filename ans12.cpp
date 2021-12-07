#include<iostream>
using namespace std;
void selection_sort(int ar[],int size)
{
for(int i=0;i<size;i++)
{
	for(int j=i+1;j<size;j++)
	{
		if(ar[j]<ar[i])
		{
			int temp=ar[i];
			ar[i]=ar[j];
			ar[j]=temp;
		}
	}
}
for(int i=0;i<size;i++)
{
	cout<<ar[i]<<"  ";
}
}

void bubble_sort(int ar[],int size)
{

    int counter =1;
    while(counter<size)
	{
		for(int i=0;i<size-counter;i++)
		{
			if(ar[i]>ar[i+1])
			{
				int temp=ar[i];
				ar[i]=ar[i+1];
				ar[i+1]=temp;
			}
		}
        counter++;
	}
	for(int i=0;i<size;i++)
    {
	cout<<ar[i]<<"  ";
    }
}

void insertion_sort(int ar[],int size)
{
	for(int i=1;i<size;i++)
	{
        int current = ar[i];
        int j = i-1;
        while (ar[j]>current && j>=0)
        {
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = current;
        
	}
	for(int i=0;i<size;i++)
    {
	cout<<ar[i]<<"  ";
    }

}
int main()
{
	int size;
	char ch;	
	cout<<"\nEnter the size of an array:\n";
	cin>>size;
	int ar[size];
	cout<<"\nEnter the elements of an array :\n";
	for (int i = 0; i < size; ++i)
	{
		cin>>ar[i];
	}
	cout<<"\nThe input array is: ";
	for (int i = 0; i < size; ++i)
	{
		cout<<ar[i]<<"  ";
	}
	do

	{
		int choice,data;
		cout<<"\n1.Bubble Sort\n2.Insertion Sort\n3.Selection Sort\n\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
			bubble_sort(ar,size);
			break;
			case 2:
			insertion_sort(ar,size);
			break;
			case 3:
			selection_sort(ar,size);
			break;
			default:
			cout<<"\nInvalid Choice";
			break;


		}
		cout<<"\nDo you want to continue(y/n) ";
		cin>>ch;
}while(ch=='y'||ch=='Y');
}
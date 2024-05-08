// #include<iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cout<<"How many numbers:";
//     cin>>n;
//     int A[n];
//     for(int i=0;i<n;i++)
//     {
//         cout<<"Enter "<<i+1<<" number:";
//         cin>>A[i];
//     }
//     int min=0,minindex=0;
    
//     cout<<"\nSorted Array:";
//     for(int i=0;i<n-1;i++)
//     {
//         min=A[i];
//         minindex=i;
//         for(int j=i+1;j<n;j++)
//         {
//             if(A[j]<min)
//             {   
//                 min=A[j];
//                 minindex=j;
//             }
//         }

//         if(min!=i)
//         {
//             int temp=A[minindex];
//             A[minindex]=A[i];
//             A[i]=temp;
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         cout<<A[i]<<" ";
//     }
// }

#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter Total number:";
    cin>>n;
    int A[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter "<<i+1<<" number:";
        cin>>A[i];
    }

    int min=0,index=0;
    for(int i=0;i<n-1;i++)
    {
        min=A[i];
        index=i;
        for(int j=i+1;j<n;j++)
        {
            if(A[j]<min)
            {
                index=j;
                min=A[j];
            }
        }

        if(min!=i)
        {
            int temp=A[index];
            A[index]=A[i];
            A[i]=temp;
        }
    }

    cout<<"Sorted array:";
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}
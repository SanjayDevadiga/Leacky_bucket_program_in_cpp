#include<iostream>
using namespace std;
int ptime[20],psize[20];
int bucket_size,time_interval,out_rate,num_packets;
int interval,filled=0,free_space=0;
int main()
{

    cin>>bucket_size>>time_interval>>out_rate>>num_packets;
    for(int i=0;i<num_packets;i++)
        cin>>ptime[i]>>psize[i];
    interval=time_interval;
    cout<<"Operation\tTime \tFilled \tFree-Space";
    cout<<"\n________________________________________";
    for(int i=0;i<num_packets;i++)
    {
        while(ptime[i]>=interval)
        {
            filled=filled-out_rate;
            if(filled<0)filled=0;
            free_space=bucket_size-filled;
            cout<<"\nDeletion\t"<<interval<<"\t"<<filled<<"\t"<<free_space;
            if(interval>ptime[i])
                break;
            else
                interval=interval+time_interval;
        }
        if((filled+psize[i])>bucket_size)
        {
            cout<<"\nInsertion\t"<<ptime[i]<<"\tOverflow";
        }
        else
        {
            filled=filled+psize[i];
            free_space=bucket_size-filled;
            cout<<"\nInsertion\t"<<ptime[i]<<"\t"<<filled<<"\t"<<free_space;
        }
    }
    while(filled!=0)
    {
        filled=filled-out_rate;
        if(filled<0)filled=0;
        free_space=bucket_size-filled;
        cout<<"\nDeletion\t"<<interval<<"\t"<<filled<<"\t"<<free_space;
    }
}

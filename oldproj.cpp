#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str[20][20], t[20];
	int i, j,n;
	cout<<"enter list no:";
	cin>>n;
	cout<<"\nEnter any strings (name) :";
	for(i=0; i<n; i++)
	{
		cin>>str[i];
	}
	//encoding strings
	for(i=0;i<n;i++)
	{
	    int l=0;
	    char a[50]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	    char b[50]={"RWQOJMVAHBSGZXNTCIEKUPDYFL"};
	    while(str[i][l]!='\0')
	    {
	    for(int k=0;k<26;k++)
	    {
	        if(str[i][l]==b[k])
	        {
	            str[i][l]=a[k];
	            break;

	        }
	    }
	    l++;
	    }
	}

for(i=1; i<n; i++)
	{
		for(j=1; j<n; j++)
		{
			if(strcmp(str[j-1], str[j])>0)
			{
				strcpy(t, str[j-1]);
				strcpy(str[j-1], str[j]);
				strcpy(str[j], t);
			}
		}
	}
	for(i=0;i<n;i++)
	{
	    int l=0;
	    char a[50]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	    char b[50]={"RWQOJMVAHBSGZXNTCIEKUPDYFL"};
	    while(str[i][l]!='\0')
	    {
	    for(int k=0;k<26;k++)
	    {
	        if(str[i][l]==a[k])
	        {
	            str[i][l]=b[k];
	            break;

	        }
	    }
	    l++;
	    }
	}
cout<<"Strings (Names) in alphabetical order : \n";
	for(i=0; i<n; i++)
	{
		cout<<str[i]<<"\n";
	}
	return 0;
}

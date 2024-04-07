#include<bits/stdc++.h>
using namespace std;

int a[10][10]={0};

void print() //��X�ѵ�
{
    cout << "======================\n";
    for(int i=1;i<=9;i++)
    {
        cout << "|";
        for(int j=1;j<=9;j++)
        {
            cout << a[i][j];
            if(j%3==0) cout << "||";
            else cout << "|";
        }
        cout << "\n";
        if(i%3==0) cout << "======================\n";
        else cout << "----------------------\n";
    }
    cout <<"\n\n\n";
    return;
}

bool check(int x,int y,int k) //�ˬd�O�_�ŦX�W�h
{
    for(int i=1;i<=9;i++)
    {
        if(a[x][i]==k) return 0;
        if(a[i][y]==k) return 0; //��C�O�_����
    }
    for(int i=((x-1)/3*3)+1;i<=(x-1)/3*3+3;i++)
    {
        for(int j=((y-1)/3*3)+1;j<=(y-1)/3*3+3;j++)
        {
            if(a[i][j]==k) return 0; //�E�c�椺�O�_����
        }
    }
}

void f(int x, int y) //dfs
{
    if(x==10) //�O�_�w�F���Y
    {
        print();
        return;
    }
    if(y==10) f(x+1,1);
    else
    {
        if(a[x][y]) f(x,y+1);
        else
        {
            for(int i=1;i<=9;i++)
            {
                if(check(x,y,i))
                {
                    a[x][y]=i;
                    f(x,y+1);
                    a[x][y]=0;
                }
            }
        }
    }
}

int main()
{
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++) cin>>a[i][j];
    }
    f(1,1);
    return 0;
}

#include<iostream>
#include<vector>

using namespace std;

struct interval
{
  vector<int> vals;
};

interval createInterval()
{
  interval C;
  cout << "To create an interval" << endl << "Enter start value: ";
  int x = 0,y=0;
  cin >> x;
  cout << "Now enter end value: ";
  cin >> y;
  cout << "Creating Interval" << endl;
  if(y>=x)
  {
    for(int i=x;i<y;i++)
    {
      C.vals.push_back(i);
    }
  }
  else
  {
    for(int i=x;i>y;i--)
    {
      C.vals.push_back(i);
    }
  }
  cout << "Created Interval" <<endl;
  return C;
}

bool check(interval I,vector<interval> A)
{
  int Ilen = I.vals.size();
  int Alen = A.size();
  for(int i=0;i<Alen;i++)
  {
    if(Ilen == A[i].vals.size())
    {
      int res = true;
      for(int j=0;j<Ilen;j++)
      {
        res = res & (I.vals[j]==A[i].vals[j]);
        cout << res << " "<<I.vals[j]<<"--"<<A[i].vals[j]<<endl;
      }
      if(res)
        return true;
    }
  }
  return false;
}


int main()
{
  vector<interval> A;
  interval I = createInterval();
  cout << "Enter new intervals" << endl;
  int cnt=0;
  char c='y';
  while(c!='n')
  {
    cout<< "interval A" << cnt << endl;
    interval B = createInterval();
    A.push_back(B);
    cout<<"Do you want to add more intervals?y/n: ";
    cin >> c;
    cnt++;
  }
  cout << "finished entering data" << endl << "A is:" << endl;
  for(int i=0;i<A.size();i++)
  {
    for(int j=0;j<A[i].vals.size();j++)
    {
      cout<<A[i].vals[j]<<" ";
    }
    cout<<endl;
  }
  cout << "Checking if I exists"<<endl;
  bool res = check(I,A);
  if(res==true)
    cout << "I exists in A";
  else
    cout << "I does not exist in A";
}

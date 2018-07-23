#include<iostream>
#include<vector>

using namespace std;

struct interval
{
  vector<int> vals;
};

interval createInterval(interval Intvl)
{
  cout << "To create an interval" << endl << "Enter start value: ";
  int x = 0,y=0;
  cin >> x;
  cout << "Now enter end value: ";
  cin >> y;
  cout << "Creating Interval" << endl;
  for(int i=x;i<y;i++)
  {
    Intvl.vals.push_back(i);
  }
  cout << "Created Interval: ";
  cout << endl;
  return Intvl;
}

bool check(interval I,vector<interval> A)
{
  int Ilen = I.vals.size();
  int Alen = A.size();
  for(int i=0;i<Alen;i++)
  {
    int res = true;
    for(int j=0;j<Ilen;j++)
    {
      res = res & (I.vals[j]==A[i].vals[j]);
    }
    if(res==true)
      return res;
  }
  return false;
}


int main()
{
  interval I,B;
  vector<interval> A;
  I = createInterval(I);
  cout << "Enter new intervals" << endl;
  int cnt=0;
  char c='y';
  while(c!='n')
  {
    cout<< "interval A" << cnt << endl;
    B = createInterval(B);
    A.push_back(B);
    cout<<"Do you want to add more intervals?y/n: ";
    cin >> c;
    cnt++;
  }
  cout << "finished entering data" << endl << "Checking if I exists" << endl;
  bool res = check(I,A);
  if(res==true)
    cout << "I exists in A";
  else
    cout << "I does not exist in A";
}

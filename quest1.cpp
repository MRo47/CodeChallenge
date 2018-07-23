#include<iostream>
#include<vector>

using namespace std;

struct interval //structure named interval
{
  vector<int> vals;  //values of the structure,  vector used since undefined array size
};

interval createInterval() //create vector function returns an interval
{
  interval C;
  cout << "To create an interval" << endl << "Enter start value: ";
  int x = 0,y=0;
  cin >> x;
  cout << "Now enter end value: ";
  cin >> y;
  cout << "Creating Interval" << endl;
  if(y>=x) //push back values entered
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

bool check(interval I,vector<interval> A) //check function checks if the interval I is in A, returns boolean
{
  int Ilen = I.vals.size();
  int Alen = A.size();
  for(int i=0;i<Alen;i++)
  {
    if(Ilen == A[i].vals.size()) //I exists only if lengths of Ai and I are equal
    {
      int res = true;
      for(int j=0;j<Ilen;j++)
      {
        res = res & (I.vals[j]==A[i].vals[j]); //AND the results in case if values are matching
        cout << res << " "<<I.vals[j]<<"--"<<A[i].vals[j]<<endl; //display matched values
      }
      if(res) //if all match return true
        return true;
    }
  }
  return false; //else return false
}


int main()
{
  vector<interval> A; //vector of intervals since A can take undefined number of structures
  interval I = createInterval(); //create I interval
  cout << "Enter new intervals" << endl;
  int cnt=0; //keep track of number of A's
  char c='y';
  while(c!='n') //till ans is no keep adding intervals
  {
    cout<< "interval A" << cnt << endl;
    interval B = createInterval(); //create new interval
    A.push_back(B);  //push the interval in vector
    cout<<"Do you want to add more intervals?y/n: ";
    cin >> c;
    cnt++;
  }
  cout << "finished entering data" << endl;
  cout << "Checking if I exists"<<endl;
  bool res = check(I,A); //check if I exists and display results
  if(res)
    cout << "I exists in A";
  else
    cout << "I does not exist in A";
}

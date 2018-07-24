#include<iostream>
#include<list>
using namespace std;

class collection
{
  private:
    list<int> nums;

  public:
    void Insert(int x)
    {
      nums.push_front(x);
      cout << "Element inserted: "<<x<<endl;
    }

    void Erase(int from,int to)
    {
      if(from==to)
      {
        nums.remove(from);
        cout << "Removed: "<<to<<endl;
      }
      else
      {
        for (list<int>::iterator itr=nums.begin(); itr != nums.end(); ++itr)
        {
          if(((from<to)&&(*itr>from)&&(*itr<to))||((from>to)&&(*itr<from)&&(*itr>to)))
          {
            int val = *itr;
            nums.remove(val);
            cout<<"Removed: "<<val<<endl;
          }
        }
      }
    }

    void Count(int from,int to)
    {
      int count=0;
      for (list<int>::iterator itr=nums.begin(); itr != nums.end(); ++itr)
      {
        if(((from<to)&&(*itr>from)&&(*itr<to))||((from>to)&&(*itr<from)&&(*itr>to)))
          count++;
      }
      cout<<"found "<<count<<" elements"<<endl;
    }

    void Show()
    {
      cout<<"Current List:"<<endl;
      for (list<int>::iterator itr=nums.begin(); itr != nums.end(); ++itr)
      {
        cout<<*itr<<" ";
      }
      cout<<endl;
    }
};

int main()
{
  collection intList;
  while(1)
  {
    intList.Show();
    cout<<"Below are the possible operations:"<<endl;
    cout<<"1.Insert element"<<endl;
    cout<<"2.Remove single element"<<endl;
    cout<<"3.Remove range of elements"<<endl;
    cout<<"4.Count elements in a given range"<<endl;
    cout<<"Type number and press enter to operate: "<<endl;
    int id = 0;
    cin>>id;
    switch (id)
    {
      case 1:
      {
        cout<<"Enter the element you want to insert: ";
        int xval = 0;
        cin>>xval;
        intList.Insert(xval);
        break;
      }
      case 2:
      {
        cout<<"Enter the element to be removed: ";
        int xval = 0;
        cin>>xval;
        intList.Erase(xval,xval);
        break;
      }
      case 3:
      {
        cout<<"Enter the range of numbers you want to erase:"<<endl<<"Start Val: ";
        int fromVal=0;
        int toVal=0;
        cin>>fromVal;
        cout<<endl<<"To Val: ";
        cin>>toVal;
        intList.Erase(fromVal,toVal);
        break;
      }
      case 4:
      {
        cout<<"Enter the range of numbers you want to count in the collection:"<<endl<<"Start Val: ";
        int fromVal=0;
        int toVal=0;
        cin>>fromVal;
        cout<<endl<<"To Val: ";
        cin>>toVal;
        intList.Count(fromVal,toVal);
        break;
      }
    }
  }
  return 0;
}

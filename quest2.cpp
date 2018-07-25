#include<iostream>
#include<list>
using namespace std;

class collection
{
  private:
    list<int> nums; //collection of numbers empty on construction

  public:
    void Insert(int x) //adding numbers to collection
    {
      nums.push_front(x); //keep pushing new numbers in front
      cout << "Element inserted: "<<x<<endl;
    }

    void Erase(int from,int to) //rease single number or a range of numbers
    {
      if(from==to) //remove single number if from to is equal
      {
        nums.remove(from);
        cout << "Removed: "<<to<<endl;
      }
      else
      {
        for (list<int>::iterator itr=nums.begin(); itr != nums.end(); ) //else iterate through the list and erase those that dont fall in range
        {
          if(((from<to)&&(*itr>=from)&&(*itr<=to))||((from>to)&&(*itr<=from)&&(*itr>=to))) //the erase function is applied inclusively from 'from' to 'to'
          {
            int val = *itr;
            itr = nums.erase(itr); //erase number and get the current iterator
            cout<<"Removed: "<<val<<endl;
          }
          else
            ++itr; //point to next element by increasing iterator
        }
      }
    }

    void Count(int from,int to) //counts numbers that fall in given range
    {
      int count=0;
      for (list<int>::iterator itr=nums.begin(); itr != nums.end(); ++itr) //iterate
      {
        if(((from<to)&&(*itr>=from)&&(*itr=<to))||((from>to)&&(*itr=<from)&&(*itr>=to))) //counts negative range also AND inclusive of both limits
          count++; //increment if true
      }
      cout<<"found "<<count<<" elements"<<endl;
    }

    void Show() //displays current list
    {
      cout<<"Current List: ";
      for (list<int>::iterator itr=nums.begin(); itr != nums.end(); ++itr)
      {
        cout<<*itr<<" ";
      }
      cout<<endl;
    }
};

int main()
{
  collection intList; //make an object intlist of collection class
  while(1) //loop the code
  {
    intList.Show(); //shw the current list
    cout<<"Below are the possible operations:"<<endl; // display menu
    cout<<"1.Insert element"<<endl;
    cout<<"2.Remove single element"<<endl;
    cout<<"3.Remove range of elements"<<endl;
    cout<<"4.Count elements in a given range"<<endl;
    cout<<"Type number and press enter to operate: ";
    int id = 0;
    cin>>id; //get id of operation
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
        intList.Erase(xval,xval); //pass same value to erase if single value deletion is needed
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
        intList.Erase(fromVal,toVal); //pass 'to' an 'from' if multiple value deletion is needed
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

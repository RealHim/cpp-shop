#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

class items
{
    public:
    int totitems=0,prodId[8],prodId2,qty[8],cost[8],totcost[8];
    string prodname[8];
    
    string custname,custaddress,custphone;
    int n=0,custage,day,month,year,prodIds[8],qtypurchased[8]={0};


    void get();
    void deletion();
    void sortingqty();
    void sortingID();
    void update();
    void display();
    
    void custdetails();
    void proddetails();
    void billgen();
    
    void printstatus();
};


class menu: public items
{
    public:
    items i1;
    
    void manage();
    void sortmenu();
    void billmenu();
    void reportmenu();
    void mainmenu();
};

void welcome()
    {
        char val;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<setw(140)<<"                                     |...................................|                                  "<<endl;
        cout<<setw(140)<<"                                     |              Welcome!             |                                  "<<endl;
        cout<<setw(140)<<"                                     |                 to                |                                  "<<endl;
        cout<<setw(140)<<"                                     |       Shop Management System      |                                  "<<endl;
        cout<<setw(140)<<"                                     |...................................|                                  "<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<setw(140)<<"A simple and quick way to manage all of the stocks for your shop.                    "<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"Press any key to continue..."<<endl;
        cin>>val;
    }

void theEnd()
    {
        char val2;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<setw(130)<<"                                     *********************                                  "<<endl;
        cout<<setw(130)<<"                                     *    Thank  You!    *                                  "<<endl;
        cout<<setw(130)<<"                                     *       Have        *                                  "<<endl;
        cout<<setw(130)<<"                                     *         A         *                                  "<<endl;
        cout<<setw(130)<<"                                     *       Great       *                                  "<<endl;
        cout<<setw(130)<<"                                     *        Day!       *                                  "<<endl;
        cout<<setw(130)<<"                                     *********************                                  "<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"Press any key to continue..."<<endl;
        cin>>val2;
    }

void items::get()
{
    int i,n;
    char option;
    cout<<setw(100)<<"                     //Add Stocks//                     "<<endl;
    if(totitems==0)
    {
    cout<<"\nEnter number of products you want to add: ";
    cin>>totitems;
    for(i=0;i<totitems;i++)
    {
        cout<<"Enter product"<<i+1<<" name: "<<endl;
        cin>>prodname[i];
        cout<<"Enter product id: "<<endl;
        cin>>prodId[i];
        cout<<"Enter quantity of product: "<<endl;
        cin>>qty[i];
        cout<<"Enter cost of single product: "<<endl;
        cin>>cost[i];
        totcost[i]=cost[i]*qty[i];
    }
    }
    else
    {
    t:cout<<"Do you want to add more products(y/n)?"<<endl;
    cin>>option;
    switch(option)
    {
    case 'y':
    cout<<"How many?"<<endl;
    cin>>n;
    for(int j=totitems;j<(totitems+n);j++)
    {
        cout<<"Enter product"<<j+1<<" name: "<<endl;
        cin>>prodname[j];
        cout<<"Enter product id: "<<endl;
        cin>>prodId[j];
        cout<<"Enter quantity of product: "<<endl;
        cin>>qty[j];
        cout<<"Enter cost of single product: "<<endl;
        cin>>cost[j];  
        totcost[j]=cost[j]*qty[j]; 
    }
    totitems=totitems+n;
    case 'n':
      break;
    default:
    cout<<"Please enter valid input."<<endl;
    goto t;
    }
    }
}

void items::deletion()
{
    int j,k,flag=0;
    cout<<setw(100)<<"                     //Delete Stocks//                     "<<endl;
    
    cout<<"\nEnter Id of the product you want to delete: "<<endl;
    cin>>prodId2;
    for(int i=0;i<totitems;i++)
    {
    if(prodId[i]==prodId2)
    {
        for(j=i; j<(totitems-1); j++)
        {
        prodId[j] = prodId[j+1];
        prodname[j] = prodname[j+1];
        qty[j] = qty[j+1];
        cost[j] = cost[j+1];
        totcost[j] = totcost[j+1];
        }
        
        totitems--;
        flag=1;
    }
    }
    if(flag==0)
    {
        cout<<"\nProduct not found."<<endl;
        cout<<"Check whether entered product ID is correct or not."<<endl;
    }
    else
    {
        cout<<"\nProduct deleted successfully."<<endl;
    }
}

void items::sortingqty()
{
    if(totitems==0)
    {
        cout<<endl;
        cout<<endl;
        cout<<setw(100)<<"Please add stocks before doing sorting operation."<<endl;
        cout<<endl;
        cout<<endl;
    }
    else
    {
    pair<int, string> pair1[totitems];
    pair<int, int> pair2[totitems];
  
    
    for (int i = 0; i < totitems; i++) 
    {
        pair1[i].first = qty[i];
        pair1[i].second = prodname[i];
    }

    for (int i = 0; i < totitems; i++) 
    {
        pair2[i].first = qty[i];
        pair2[i].second = prodId[i];
    }
  
    
    sort(pair1, pair1 + totitems);
    sort(pair2, pair2 + totitems);
      
   cout<<endl;
   cout<<endl;    
   cout<<"Sorted products according to quantity: "<<endl;
   cout<<endl;
   cout<<endl;
   cout<<setw(10)<<left<<right<<"Product"<<setw(10)<<"Id"<<setw(18)<<"Quantity"<<setw(21)<<endl;
   cout<<setw(10)<<left<<right<<"-------"<<setw(10)<<"--"<<setw(18)<<"--------"<<setw(21)<<endl;
   for(int i=0;i<totitems;i++)
   {
     cout<<setw(10)<<left<<right<<pair1[i].second<<setw(10)<<pair2[i].second<<setw(14)<<pair1[i].first<<endl;
   }
   cout<<endl;
   cout<<endl;
   }
}

void items::sortingID()
{
    if(totitems==0)
    {
        cout<<endl;
        cout<<endl;
        cout<<setw(100)<<"Please add stocks before doing sorting operation."<<endl;
        cout<<endl;
        cout<<endl;
    
    }
    else
    {
    pair<int, string> pair3[totitems];
    pair<int, int> pair4[totitems];
    for (int i = 0; i < totitems; i++) 
    {
        pair3[i].first = prodId[i];
        pair3[i].second = prodname[i];
    }

    for (int i = 0; i < totitems; i++) 
    {
        pair4[i].first = prodId[i];
        pair4[i].second = qty[i];
    }
  
    sort(pair3, pair3 + totitems);
    sort(pair4, pair4 + totitems);

   cout<<endl;
   cout<<endl;   
   cout<<"Sorted products according to ID: "<<endl;
   cout<<endl;
   cout<<endl;
   cout<<setw(10)<<left<<right<<"Product"<<setw(10)<<"Id"<<setw(18)<<"Quantity"<<setw(21)<<endl;
   cout<<setw(10)<<left<<right<<"-------"<<setw(10)<<"--"<<setw(18)<<"--------"<<setw(21)<<endl;
   for(int i=0;i<totitems;i++)
   {
     cout<<setw(10)<<left<<right<<pair3[i].second<<setw(10)<<pair3[i].first<<setw(14)<<pair4[i].second<<endl;
   }
   cout<<endl;
   cout<<endl;
   }
}


void items::update()
{
    int i,temp=0;
    cout<<setw(100)<<"                     //Update Stocks//                     "<<endl;
    cout<<"\nEnter productID to replace: "<<endl;
    cin>>prodId2;
    for(int i=0;i<totitems;i++)
    {
    if(prodId2==prodId[i])
    {
        cout<<"Product found."<<endl;
        cout<<"Enter new product name: "<<endl;
        cin>>prodname[i];
        cout<<"Enter new product id: "<<endl;
        cin>>prodId[i];
        cout<<"Enter quantity of product: "<<endl;
        cin>>qty[i];
        cout<<"Enter cost of single product: "<<endl;
        cin>>cost[i];
        totcost[i]=cost[i]*qty[i];
        temp=1;
        
    }
   
    }
        if(temp==0)
        {
        cout<<"Product not found."<<endl;
        }
        
      
}

void items::display()
{
    int i;
    cout<<setw(113)<<"                 ------------------------                 "<<endl;
    cout<<setw(113)<<"                 Current Available Stocks                 "<<endl;
    cout<<setw(113)<<"                 ------------------------                 "<<endl;

    if(totitems==0)
    {
    cout<<endl;
    cout<<setw(101)<<"There are zero stocks right now."<<endl;
    }
    else
    {
    cout<<"\n"<<endl;
    cout<<setw(55)<<left<<right<<"Product"<<setw(10)<<"Id"<<setw(18)<<"Quantity"<<setw(21)<<"Cost per item"<<setw(15)<<"Total cost"<<endl;
    cout<<setw(55)<<left<<right<<"-------"<<setw(10)<<"--"<<setw(18)<<"--------"<<setw(21)<<"-------------"<<setw(15)<<"----------"<<endl;
    cout<<endl;
    for(i=0;i<totitems;i++)
    {
        cout<<setw(55)<<left<<right<<prodname[i]<<setw(10)<<prodId[i]<<setw(14)<<(qty[i]-qtypurchased[i])<<setw(19)<<cost[i]<<setw(17)<<(cost[i]*(qty[i]-qtypurchased[i]))<<endl;
    }
    }
    
}

void items::custdetails()
{
    cout<<setw(90)<<"                 ----------------                 "<<endl;
    cout<<setw(90)<<"                 Customer Details                 "<<endl;
    cout<<setw(90)<<"                 ----------------                 "<<endl;
    cout<<"\nEnter name of the customer: "<<endl;
    cin.ignore();
    getline(cin,custname);
    cout<<"Enter age: "<<endl;
    cin>>custage;
    cout<<"Enter residence area: "<<endl;
    cin.ignore();
    getline(cin,custaddress);
    cout<<"Enter contact number: "<<endl;
    cin>>custphone;
}

void items::proddetails()
{
    cout<<setw(90)<<"                 ---------------                 "<<endl;
    cout<<setw(90)<<"                 Product Details                 "<<endl;
    cout<<setw(90)<<"                 ---------------                 "<<endl;
    if(totitems==0)
    {
        cout<<endl;
        cout<<setw(78)<<"Please add stocks first."<<endl;
    }
    else
    {
    cout<<"\nHow many items were purchased?"<<endl;
    cin>>n;
    if(n==0)
    {
        return; 
    }
    else
    {
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Product"<<i+1<<" Id: "<<endl;
        cin>>prodIds[i];
       q:cout<<"Enter quantity bought: "<<endl;
        cin>>qtypurchased[i];
        if(qtypurchased[i]>qty[i])
        {
            cout<<"We're sorry but requested quantity of this product is not available."<<endl;
            cout<<"Available quantity for this product is "<<qty[i]<<endl;
            goto q;
        }
    }
    cout<<"Enter Billing Day: "<<endl;
    cin>>day;
    cout<<"Enter Billing Month: "<<endl;
    cin>>month;
    cout<<"Enter Billing Year: "<<endl;
    cin>>year;
    }
    }
}

void items::billgen()
{
    int i,j,sum=0;
    if(prodIds[0]==0)
    {
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<setw(99)<<"There are currently no products added to bill."<<endl;
        cout<<setw(90)<<"Add product details to generate bill."<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
    }
    else
    {
    cout<<setw(99)<<"                 ------------                 "<<endl;
    cout<<setw(99)<<"               * Bill Receipt *               "<<endl;
    cout<<setw(99)<<"                 ------------                 "<<endl;
    cout<<"Billed to"<<endl;
    cout<<"---------"<<endl;
    cout<<"\nCustomer Name: "<<custname<<endl;;
    cout<<"Age: "<<custage<<endl;
    cout<<"Address: "<<custaddress<<endl;
    cout<<"Contact: "<<custphone<<endl;
    cout<<endl;
    cout<<endl;
    cout<<setw(55)<<left<<right<<"Product Purchased"<<setw(18)<<"Quantity"<<setw(21)<<"Cost per item"<<setw(15)<<"Total cost"<<endl;
    cout<<setw(55)<<left<<right<<"-----------------"<<setw(18)<<"--------"<<setw(21)<<"-------------"<<setw(15)<<"----------"<<endl;
    for(j=0;j<n;j++)
    {
    for(i=0;i<totitems;i++)
    {
    if(prodIds[j]==prodId[i])
    {
        cout<<setw(48)<<left<<right<<prodname[i]<<setw(21)<<qtypurchased[i]<<setw(19)<<cost[i]<<setw(17)<<(cost[i]*qtypurchased[j])<<endl;
        sum=sum+(cost[i]*qtypurchased[j]);
    }
    }
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<setw(115)<<"Billing Date: "<<day<<"."<<month<<"."<<year<<endl;
    cout<<setw(126)<<"Final Amount to be paid: "<<sum<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    }
}

void items::printstatus()
{
    int temp[8];
    cout<<setw(98)<<"                 ------                 "<<endl;
    cout<<setw(98)<<"                 Status                 "<<endl;
    cout<<setw(98)<<"                 ------                 "<<endl;
    if(totitems==0)
    {
        cout<<endl;
        cout<<endl;
        cout<<setw(91)<<"There are currently no products."<<endl;
        cout<<setw(98)<<"Please add any stock to get the status."<<endl;
    }
    else if(n==0)
    {
        cout<<endl;
        cout<<endl;
        cout<<setw(104)<<"Please generate bill before Reporting Current Status."<<endl;
    }
    else
    {
    cout<<"\n"<<custname<<" purchased "<<endl;
    cout<<endl;
    cout<<setw(8)<<left<<right<<"Product"<<setw(20)<<"How many?"<<endl;
    for(int j=0;j<n;j++)
    {
    for(int i=0;i<totitems;i++)
    {
    if(prodIds[j]==prodId[i])
    {
        cout<<setw(8)<<left<<right<<prodname[i]<<setw(16)<<qtypurchased[j]<<endl;
    }
    }
    }
    cout<<setw(94)<<"     ** Remaining Stocks **     "<<endl;
    cout<<endl;

    cout<<setw(68)<<left<<right<<"Product"<<setw(10)<<"Id"<<setw(18)<<"Quantity"<<endl;
    cout<<setw(68)<<left<<right<<"-------"<<setw(10)<<"--"<<setw(18)<<"--------"<<endl;
    
    for(int k=0;k<totitems;k++)
    {
    for(int l=0;l<n;l++)
    {
        if(prodIds[l]==prodId[k])
        {
        cout<<setw(68)<<left<<right<<prodname[k]<<setw(10)<<prodId[k]<<setw(14)<<qty[k]-qtypurchased[l]<<endl;
        temp[l]=1;
        } 
    }
    if(temp[k]!=1)
    {
    cout<<setw(68)<<left<<right<<prodname[k]<<setw(10)<<prodId[k]<<setw(14)<<qty[k]<<endl;
    }
    }
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    
}


void menu::manage(){
    int c,key;
    while(1)
    {
      p:cout<<setw(115)<<"                | Stock Management |              "<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"1. Add Stocks                                     "<<endl;
        cout<<"2. Delete Stocks                                  "<<endl;
        cout<<"3. Sort Stocks                                    "<<endl;
        cout<<"4. Update Stocks                                  "<<endl;
        cout<<"5. View Current Stocks                            "<<endl;
        cout<<"6. Main Menu                                      "<<endl;
        cout<<endl;
        cout<<endl;
  loop2:cout<<"Enter your choice: ";
        cin>>c;

        if(c==1)
        {
            system("cls");
            i1.get();
            system("cls");
            goto p;
            

        }
        
        else if(c==2)
        {
            system("cls");
            i1.deletion();
            cout<<endl;
      loop5:cout<<"Press 1 to go back"<<endl;
            cin>>key;
            if(key==1)
            {
                system("cls");
                goto p;
            }
            else{
                cout<<"Kindly enter valid input."<<endl;
                goto loop5;
            }
        }
        else if(c==3)
        {
            system("cls");
            sortmenu();
           loop6:cout<<"Press 1 to go back"<<endl;
            cin>>key;
            if(key==1)
            {
                system("cls");
                goto p;
            }
            else{
                cout<<"Kindly enter valid input."<<endl;
                goto loop6;
            }
        }
        else if(c==4)
        {
            system("cls");
            i1.update();
            cout<<endl;
      loop4:cout<<"Press 1 to go back"<<endl;
            cin>>key;
            if(key==1)
            {
                system("cls");
                goto p;
            }
            else{
                cout<<"Kindly enter valid input."<<endl;
                goto loop4;
            }

        }
        else if(c==5)
        {
            system("cls");
            i1.display();
            cout<<endl;
      loop3:cout<<"Press 1 to go back"<<endl;
            cin>>key;
            if(key==1)
            {
                system("cls");
                goto p;
            }
            else{
                cout<<"Kindly enter valid input."<<endl;
                goto loop3;
            }
        }
        else if(c==6)
        { 
            system("cls");
            mainmenu();
        }
        else
        {
            cout<<"Kindly enter valid input."<<endl;
            goto loop2;
        }
        
    }
}

void menu::sortmenu()
{
    int sch,key2;
    while(1)
    {
    h:cout<<setw(115)<<"                    || Sorting ||                       "<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"\n1. Sort on the basis of Quantity?                                    "<<endl;
    cout<<"2. Sort on the basis of Product Id?                                  "<<endl;
    cout<<"3. Go Back                                                           "<<endl;
    cout<<endl;
    cout<<endl;
    loop3:cout<<"\nEnter your choice: "<<endl;
    cin>>sch;
    if(sch==1)
    {
        system("cls");
        i1.sortingqty();
        cout<<endl;
      loop1:cout<<"Press 1 to go back"<<endl;
            cin>>key2;
            if(key2==1)
            {
                system("cls");
                goto h;
            }
            else{
                cout<<"Kindly enter valid input."<<endl;
                goto loop1;
            }
    }
    else if(sch==2)
    {
        system("cls");
        i1.sortingID();
        cout<<endl;
      loop2:cout<<"Press 1 to go back"<<endl;
            cin>>key2;
            if(key2==1)
            {
                system("cls");
                goto h;
            }
            else{
                cout<<"Kindly enter valid input."<<endl;
                goto loop2;
            }
    }
    else if(sch==3)
    {
        system("cls");
        manage();
    }
     else
        {
            cout<<"Kindly enter valid input."<<endl;
            goto loop3;
        }
    }
}

void menu::billmenu()
{
    int d,key;
    while(1)
    {
      p:cout<<setw(115)<<"                | Bill Generation |               "<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"1. Customer Details                               "<<endl;
        cout<<"2. Product Details                                "<<endl;
        cout<<"3. Generate Bill                                  "<<endl;
        cout<<"4. Main Menu                                      "<<endl;
        cout<<endl;
        cout<<endl;
  loop2:cout<<"Enter your choice: ";
        cin>>d;

        if(d==1)
        {
            system("cls");
            i1.custdetails();
            system("cls");
            goto p;
            

        }
        
        else if(d==2)
        {
            system("cls");
            i1.proddetails();
            cout<<endl;
      loop5:cout<<"Press 1 to go back"<<endl;
            cin>>key;
            if(key==1)
            {
                system("cls");
                goto p;
            }
            else{
                cout<<"Kindly enter valid input."<<endl;
                goto loop5;
            }
        }
        else if(d==3)
        {
            system("cls");
            i1.billgen();
            cout<<endl;
      loop6:cout<<"Press 1 to go back"<<endl;
            cin>>key;
            if(key==1)
            {
                system("cls");
                goto p;
            }
            else{
                cout<<"Kindly enter valid input."<<endl;
                goto loop6;
            }
            
        }
        
        else if(d==4)
        { 
            system("cls");
            mainmenu();
            break;
        }
        else
        {
            cout<<"Kindly enter valid input."<<endl;
            goto loop2;
        }
        
    }
}

void menu::reportmenu()
{
    int e,key;
    while(1)
    {
      p:cout<<setw(115)<<"                | Report Section |                  "<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"1. Current Status                                 "<<endl;
        cout<<"2. Main Menu                                      "<<endl;
        cout<<endl;
        cout<<endl;
  loop8:cout<<"Enter your choice: ";
        cin>>e;

        if(e==1)
        {
            system("cls");
            i1.printstatus();
            cout<<endl;
      loop7:cout<<"Press 1 to go back"<<endl;
            cin>>key;
            if(key==1)
            {
                system("cls");
                goto p;
            }
            else{
                cout<<"Kindly enter valid input."<<endl;
                goto loop7;
            }
        }
        else if(e==2)
        { 
            system("cls");
            mainmenu();
            break;
        }
        else
        {
            cout<<"Kindly enter valid input."<<endl;
            goto loop8;
        }
        
    }
}



void menu::mainmenu()
{

    system("cls");
    int ch;
    while(1)
    {
    cout<<setw(117)<<"              << Shop Management System >>               "<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"1. Manage Stocks                                      "<<endl;
    cout<<"2. Generate Bill                                      "<<endl;
    cout<<"3. Report                                             "<<endl;
    cout<<"4. Exit                                               "<<endl;
    cout<<endl;
    cout<<endl;
    loop: cout<<"\n Enter your choice: ";
    cin>>ch;

    switch(ch)
    {
        case 1:
            system("cls");
            manage();
            break;
        case 2:
            system("cls");
            billmenu();
            break;
        case 3:
            system("cls");
            reportmenu();
            break;
        case 4:
            system("cls");
            theEnd();
            exit(0);
            break;
        default:
            cout<<"Kindly enter valid input."<<endl;
            goto loop;
    }
    }
    
}

int main()
{
    system("cls");
    welcome();
    system("cls");
    menu m1;
    m1.mainmenu();
    return 0;
}

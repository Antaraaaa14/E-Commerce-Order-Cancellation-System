#include<iostream>
#include<stack>
#include<string>
#include<cstdlib>
#include<ctime>
#include<thread>
#include<chrono>

using namespace std;

#define RESET "\033[0m"
#define CYAN "\033[1;36m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define PURPLE "\033[1;35m"
#define BLUE "\033[1;34m"

struct Action
{
    string type;
    string value;
};

stack<Action> history;

string product="None";
string coupon="None";
string address="Not Set";

int quantity=1;

bool confirmed=false;

int totalAction=0;
int totalUndo=0;

int orderID=1000+rand()%9000;

void line()
{
    cout<<CYAN<<"===================================================="<<RESET<<endl;
}

void banner()
{
    cout<<CYAN;

    cout<<"  _____ __  __    _    ____ _____ "<<endl;
    cout<<" / ____|  \\/  |  / \\  |  _ \\_   _|"<<endl;
    cout<<"| (___ | |\\/| | / _ \\ | |_) || |  "<<endl;
    cout<<" \\___ \\| |  | |/ ___ \\|  _ < | |  "<<endl;
    cout<<" ____) | |  | /_/   \\_\\_| \\_\\|_|  "<<endl;
    cout<<"|_____/|_|  |_|                 "<<endl;

    cout<<RESET;

    cout<<GREEN<<"\n        SMART CART UNDO SYSTEM\n"<<RESET;

    line();

    cout<<"Order ID      : SC-"<<orderID<<endl;
    cout<<"Order Status  : "<<(confirmed?"CONFIRMED":"ACTIVE")<<endl;
    cout<<"Stack Size    : "<<history.size()<<endl;

    line();
}

void loading()
{
    cout<<YELLOW<<"Processing";

    for(int i=0;i<5;i++)
    {
        cout<<".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(300));
    }

    cout<<RESET<<endl;
}

void currentOrder()
{
    line();

    cout<<PURPLE<<"CURRENT ORDER\n"<<RESET;

    cout<<"Product   : "<<product<<endl;
    cout<<"Quantity  : "<<quantity<<endl;
    cout<<"Coupon    : "<<coupon<<endl;
    cout<<"Address   : "<<address<<endl;

    line();
}

void showStack()
{
    if(history.empty())
    {
        cout<<RED<<"Stack Empty\n"<<RESET;
        return;
    }

    stack<Action> temp=history;

    cout<<BLUE<<"\nSTACK VIEW (TOP)\n"<<RESET;

    while(!temp.empty())
    {
        cout<<"| "<<temp.top().type<<" |"<<endl;
        temp.pop();
    }

    line();
}

int main()
{

srand(time(0));

int choice;

do
{

banner();

cout<<"\n1 Add Product"<<endl;
cout<<"2 Update Quantity"<<endl;
cout<<"3 Apply Coupon"<<endl;
cout<<"4 Change Address"<<endl;
cout<<"5 Peek Last Action"<<endl;
cout<<"6 Undo"<<endl;
cout<<"7 Action History"<<endl;
cout<<"8 View Order"<<endl;
cout<<"9 Confirm Order"<<endl;
cout<<"0 Exit"<<endl;

line();

cout<<"Enter Choice : ";
cin>>choice;

cin.ignore();

if(confirmed && choice!=8 && choice!=0)
{
    cout<<RED<<"\nOrder Already Confirmed.\n"<<RESET;
    continue;
}

switch(choice)
{

case 1:

cout<<"Product Name : ";
getline(cin,product);

history.push({"Add Product",product});

totalAction++;

cout<<GREEN<<"\nProduct Added Successfully.\n"<<RESET;

break;

case 2:

cout<<"Quantity : ";
cin>>quantity;

history.push({"Update Quantity",to_string(quantity)});

totalAction++;

cout<<GREEN<<"\nQuantity Updated.\n"<<RESET;

break;

case 3:

cout<<"Coupon Code : ";

getline(cin>>ws,coupon);

history.push({"Apply Coupon",coupon});

totalAction++;

cout<<GREEN<<"\nCoupon Applied.\n"<<RESET;

break;

case 4:

cout<<"Delivery Address : ";

getline(cin,address);

history.push({"Change Address",address});

totalAction++;

cout<<GREEN<<"\nAddress Updated.\n"<<RESET;

break;

case 5:

if(history.empty())
cout<<RED<<"\nNothing To Peek\n"<<RESET;

else
{

cout<<YELLOW<<"\nLAST ACTION\n"<<RESET;

cout<<history.top().type<<" -> "<<history.top().value<<endl;

}

break;
case 6:

if(history.empty())
{
    cout<<RED<<"\nNothing To Undo\n"<<RESET;
}

else
{
    Action last=history.top();

    history.pop();

    totalUndo++;

    if(last.type=="Add Product")
        product="None";

    else if(last.type=="Update Quantity")
        quantity=1;

    else if(last.type=="Apply Coupon")
        coupon="None";

    else if(last.type=="Change Address")
        address="Not Set";

    cout<<YELLOW<<"\nUndo Successful\n"<<RESET;
    cout<<"Removed : "<<last.type<<endl;
}

break;

case 7:

showStack();

break;

case 8:

currentOrder();

break;

case 9:

loading();

confirmed=true;

cout<<GREEN;

line();

cout<<"        ORDER CONFIRMED SUCCESSFULLY\n";

line();

cout<<RESET;

break;

case 0:

cout<<PURPLE;

line();

cout<<"              ORDER SUMMARY\n";

line();

cout<<RESET;

cout<<"Order ID       : SC-"<<orderID<<endl;
cout<<"Product        : "<<product<<endl;
cout<<"Quantity       : "<<quantity<<endl;
cout<<"Coupon         : "<<coupon<<endl;
cout<<"Address        : "<<address<<endl;

line();

cout<<"Total Actions  : "<<totalAction<<endl;
cout<<"Undo Count     : "<<totalUndo<<endl;
cout<<"Remaining Stack: "<<history.size()<<endl;

line();

cout<<GREEN<<"Thank You For Using Smart Cart!"<<RESET<<endl;

break;

default:

cout<<RED<<"\nInvalid Choice!\n"<<RESET;

}

cout<<"\nPress Enter To Continue...";
cin.get();

#ifdef _WIN32
system("cls");
#else
system("clear");
#endif

}
while(choice!=0);

return 0;

}
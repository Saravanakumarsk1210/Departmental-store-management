#include <iostream>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
#include<iomanip>
char a=' ';
using namespace std;

class billing
{
    private:
        char name[20];
        int qty;
        float price, net;
    public:
        void getdata();
        void modify(billing *o, int no);
        void Remove(billing *o, int no);
        void Display() ;
};

void billing :: getdata()
{
    cout<<"\n Enter Item Name : ";
    cin>>name;
    cout<<" Enter Item Quantity (in kg): ";
    cin>>qty;
    cout<<" Enter Item Price (in Rs) : ";
    cin>>price;
    net = price * qty;
}

void billing :: modify(billing *o, int no)
{
    char key[15];
    int i,j;
    cout<<"\n Enter the Item Name to modify: ";
    cin>>key;
    for(i=0;i<=no;i++)
    {
        if(strcmp(o[i].name, key) == 0)
        {
            cout<<"\n Enter Item Name : ";
            cin>>o[i].name;
            cout<<"\n Enter Item Price : ";
            cin>>o[i].price;
            cout<<"\n Enter Item Quantity : ";
            cin>>o[i].qty;
            o[i].net = o[i].price * o[i].qty;
            cout<<"\n\t#################### RECORD MODIFIED SUCCESSFULLY !############################# ";
            break;
        }
        else if(strcmp(o[i].name, key) != 0)
            cout<<"\n\t#################### ITEM DOES NOT MATCH!!############################# ";
    }
}

void billing :: Remove(billing *o, int no)
{
    char key[15];
    int i,j,flag;
    cout<<"\n Enter the Item Name to Remove: ";
    cin>>key;
    for( i=0; i<=no; i++)
    {
        if(strcmp(o[i].name, key) == 0)
        {
            for(j=i; j<=no; j++)
                o[j] = o[j+1];
            no--;
            cout<<"\n\t#################### RECORD REMOVED SUCCESSFULLY !############################# ";
            break;
        }
        else if(strcmp(o[i].name, key) != 0)
            cout<<"\n\t#################### ITEM DOES NOT MATCH!!############################# ";
    }
}

void billing :: Display()
{
    cout<<"\n\t Item Name: "<<name;
    cout<<"\n\t Item Price: "<<price;
    cout<<"\n\t Item Quantity: "<<qty;
    cout<<"\n\t Net Price: "<<net;
}

class passwordset
{
    private :
        int i,length,count=0,ct=0,cnt=0;
        int flag1=1,flag2,flag3,flag4,flag5;
        char ps[15];
        int ch=1;
    public:
        passwordset()
        {
            count=0,ct=0,cnt=0;
        }
        string newpasswordy();
};

string passwordset::newpasswordy()
{
    while(flag1!=0||flag2!=0||flag3!=0||flag4!=0||flag5!=0)
    {
        cout<<"\nENTER NEW PASSWORD : ";
        cin>>ps;
        length=strlen(ps);
        count=0;cnt=0;ct=0;
        if(strlen(ps)<8)
        {
            cout<<"YOUR PASSWORD SHOULD BE ATLEAST 8 CHARACTERS LONG";
        }
        else
            flag1=0;
        for(i=0;i<length;i++)
        {
            if(ps[i]==' ')
            {
                cout<<"YOUR PS SHOULD NOT CONTAIN BLANK SPACE\n";
            }
            else
                flag2=0;
            if(ps[i]!='&'&&ps[i]!='*'&&ps[i]!='$'&&ps[i]!='#'&&ps[i]!='@')
            {
                count++;
                if(count==length)
                    cout<<"\nYOUR PASSWORD SHOULD CONTAIN ATLEAST ONE SPECIAL CHARACTER\n";
            }
            else
                flag3=0;
            if(isupper(ps[i])==0)
            {
                ct++;
                if(ct==length)
                    cout<<"YOUR PASSWORD SHOULD CONTAIN ATLEAST ONE UPPER CASE CHARACTER\n";
            }
            else
                flag4=0;
            if(isdigit(ps[i])==0)
            {
                cnt++;
                if(cnt==length)
                {
                    cout<<"YOUR PASSWORD MUST CONTAIN ATLEAST ONE NUMBER\n";
                }
                else
                    flag5=0;
            }
        }
    }
    if(flag1==0&&flag2==0&&flag3==0&&flag4==0&&flag5==0)
    {
        cout<<"\n*STRONG PASSWORD*";
        cout<<"\t\t.PASSWORD SET SUCCESSFULLY.\n\n";
    }
    return ps;
}

class passlogin :protected passwordset
{
    public:
        void password(string r)
        {
            string opass=r,epass;
            cout<<endl;
            cout<<"\t\t\tWLCOME TO SECURED GROCERRY SHOP STACK MANAGEMENT SYSTEM \n";
            cout<<"\t\t\t___________________\n";
            cout<<"\n\n ENTER YOUR PASSWORD TO LOGIN : " ;
            cin>>epass;
            if(epass==opass)
            {
                cout<<" \t\t PASSWORD IS CORRECT \n ";
            }
            else
            {
                cout<<"\n\t\t OOPS !! ENTERED PASSSWORD IS WRONG ! TRY AGAIN !\n\n";
                password(r);
            }
        }
};

int main()
{
    billing b[20], bl;
    passwordset p;
    passlogin p2;
    int ch1, item_no = -1,i;
    string r="hello";
    char ch2;
    p2.password(r);
    while(1)
    {
        cout<<endl;
        cout<<setw(30);
        cout<<"\n\n\t\t\t GROCERRY SHOP\n";
        cout<<"\t\t\t_______________________\n";
        cout<<"\n\t\t\t1. Get Item Details.";
        cout<<"\n\t\t\t2. Display Items.";
        cout<<"\n\t\t\t3. modify an Item.";
        cout<<"\n\t\t\t4. Remove an Item.";
        cout<<"\n\t\t\t5. Set new password.";
        cout<<"\n\t\t\t6. Exit. \n";
        cout<<"\t\t\t______________________\n";
        cout<<"\n Enter your choice: ";
        cin>>ch1;
        switch(ch1){
            case 1:
                while(1)
                {
                    item_no++;
                    cout<<"\n Entry of Purchased Items.";
                    cout<<"\n ------------------------";
                    cout<<endl;
                    cout<<"\n Item No. "<<item_no+1;
                    b[item_no].getdata();
                    cout<<"\n Do you want to add more(y/n): ";
                    cin>>ch2;
                    if(ch2 == 'n')
                        break;
                }
                break;
            case 2:
                cout<<"\n\n Purchase order Details.";
                cout<<"\n ------------------------";
                for(int i=0; i<=item_no; i++)
                {
                    cout<<"\n\n Item No.: "<<i+1;
                    b[i].Display();
                }
                break;
            case 3:
                bl.modify(b, item_no);
                break;
            case 4:
                bl.Remove(b, item_no);
                break;
            case 5:
                r= p.newpasswordy();
                p2.password(r);
                break;
            default:
                exit(1);
        }
    }
}

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class shooping
{
    private:
        int pcode;
        float price;
        float dis;
        string pname;

    public:
        void menu();
        void administractor();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
};

void shooping :: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t___________________________________"<<endl;
    cout<<"\t\t\t\t                                   "<<endl;
    cout<<"\t\t\t\t                                   "<<endl;
    cout<<"\t\t\t\t        Supermarket Main Menu      "<<endl;
    cout<<"\t\t\t\t                                   "<<endl;
    cout<<"\t\t\t\t___________________________________"<<endl;
    cout<<"\t\t\t\t                                   "<<endl;
    cout<<"\t\t\t\t|    1) Administractor"<<endl;
    cout<<"\t\t\t\t|                     "<<endl;
    cout<<"\t\t\t\t|    2) Buyer"<<endl;
    cout<<"\t\t\t\t|                     "<<endl;
    cout<<"\t\t\t\t|    3) Exit"<<endl;
    cout<<"\t\t\t Please Select !";
    cin>>choice;

    switch(choice){
        case 1:
            cout<<"\t\t\t Please Login"<<endl;
            cout<<"\t\t\t Enter Email:"<<endl;
            cin>>email;
            cout<<"\t\t\t Enter Password:"<<endl;
            cin>>password;

            if(email == "thanzawaou@mail.com" && password == "12345"){
                administractor();
            }else{
                cout<<"Invalid Email and Password !";
            }
            break;
        case 2:
            buyer();
        case 3:
            exit(0);
        default :
            cout<<"Please select given options!";
    }  
    goto m; 
}

void shooping :: administractor()
{
    b:
    int choice;
    cout << "\n\n\n\t\t\t Administractor menu";
    cout << "\n\t\t\t|___1) Add the product_____|";
    cout << "\n\t\t\t|                          |";
    cout << "\n\t\t\t|___2) Modify the product__|";
    cout << "\n\t\t\t|                          |";
    cout << "\n\t\t\t|___3) Delete the product__|";
    cout << "\n\t\t\t|                          |";
    cout << "\n\t\t\t|___4) Back to Main Menu___|";

    cout<<"\n\n\t Please Enter your choice:";
    cin >> choice;

    switch (choice)
    {   
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;

        default:
            cout<<"\n\n\t\t You don't choice anything.";
    }
  goto b;  
}
void shooping::buyer()
{
    m:
    int choice;
    cout << "\t\t\t Buyer " << endl;
    cout << "__________________" << endl;
    cout << "                  " << endl;
    cout << "\t\t1) Buy Product" << endl;
    cout << "                  " << endl;
    cout << "\t\t2) Go Back    " << endl;

    cout << "\t\t\tEnter your Choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;
    default:
        cout << "Invalid Choice!";
        break;
    }
    goto m;
}
void shooping::add()
{
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t Add new product";
    cout << "\n\n\t Product code of the product ";
    cin >> pcode;
    cout<<"\n\n\t Price of the product";
    cin >> price;
    cout << "\n\n\t Discount on the product";
    cin >> dis;

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    
        if (token == 1) {
            goto m;
        }
        else {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
            data.close();
        }
    }
    cout << "\n\n\t\t Record Inserted!";
}
void shooping::edit()
{
    fstream data,data1;
    int c;
    int pkey;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t Modify the record";
    cout << "\n\t\t\t Product Code";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n File doesn't exit";
    }
    else {
        data1.open("database1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> dis;

        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t Product the new Code : ";
                cin >> c;
                cout << "\n\t\t The Name of the Product :";
                cin >> n;
                cout << "\n\t\t Price : ";
                cin >> p;
                cout << "\n\t\t Discount : ";
                cin >> d;
                
                data1 << " " << c << " " << n << " " << p << " " << d << endl;
                cout << "\n\n\t\t Record Edited! ";
                token++;
            }
            else {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << endl;
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        remove("database1.txt");

        if (token == 0)
        {
            cout << "\n\n\t\tSorry! Record not Found!";
        }
    }
}

void shooping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t Delete Product";
    cout << "\n\n\t Product Code";

    cin >> pkey;

    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "\n\n\t File Doesn't Exit!";
    }
    else {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;

        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t Product delete successfully";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << endl;
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        remove("database1.txt");

        if (token == 0)
        {
            cout << "\n\n Record not Found!";
        }
    }
}
void shooping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|_____________________________________________________________________________________|";
    cout << "ProNo\t\tName\t\tPrice" << endl;
    cout << "\n\n|_____________________________________________________________________________________|";
    data >> pcode >> pname >> price >> dis;

    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\t\t" << endl;
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}
void shooping::receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float dis = 0;
    float amount = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\tEmpty Data";
    }
    else
    {
        data.close();
        list();
        cout << "\n_____________________________________" << endl;
        cout << "|                                      |" << endl;
        cout << "|      Please place the oder           |" << endl;
        cout << "|                                      |" << endl;
        cout << "\n_____________________________________" << endl;

        do
        {
            m:
            cout << "\n\nEnter the product : ";
            cin >> arrc[c];
            cout << "\nEnter the product quantity";
            cin >> arrq[c];

            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\nDuplicate product code. Please Try Again!";
                    goto m;
                }
            }
            c++;
            cout << "\n\nDo you want to buy another product? if yes then press y else no";
            cin >> choice;
        } while (choice == 'y');
        cout << "\n\n\t\t\t____________________RECEPT_______________________" << endl;
        cout << "\nProduct No\t Product Name\tProduct Quantity\tprice\tAmount\tAmount with discout" << endl;

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t"<<dis;
                }
                data << pcode << pname << price << dis;
            }
        }
        data.close();
    }

    cout << "\n\n_____________________________________________";
    cout << "\n Total Amount : " << total;
}

int main()
{
    shooping s;
    s.menu();

    return 0;
}

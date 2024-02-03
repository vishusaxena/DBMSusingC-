#include <bits/stdc++.h>
#include<windows.h>
using namespace std;
void insertinFile();
void deleteinFile();
void displayFile();
void updateFile();
int main()
{
    int choice, id;
    string name;
    cout << "================================Menu====================================" << endl;
    cout << " 1. Enter the data in the File" << endl;
    cout << " 2. Dispaly the data in the File" << endl;
    cout << " 3. Update the data in the File" << endl;
    cout << " 4. Delete the data in the file" << endl;
    cout << " 5. Exit from the Application" << endl;

    cout << " Enter the operation you want to perform " << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        insertinFile();
        break;
    case 4:
        deleteinFile();
        break;
    case 2:
        displayFile();
        break;
    case 3:
        updateFile();
        break;
    default:
        cout << "Choose from above option" << endl;
        main();
        break;
    }
}
void insertinFile()
{
    int id;
    string name;
    cout << "Enter the Id  :";
    cin >> id;
    cout << "Enter the name:";
    cin >> name;
    ofstream file;
    file.open("data.txt", ios::app);
    file << id << "-->" << name << endl;
    file.close();
    cout << "Insertion successfull!" << endl;
    system("cls");
    main();
}
void deleteinFile()
{
    int id;
    string name;
    int del_id;
    string del_name;
    cout << "enter the  id :";
    cin >> del_id;
    cout << "enter the name :";
    cin >> del_name;
    ifstream file;
    file.open("data.txt");
    ofstream temp;
    temp.open("temp.txt");
    while (file >> id >> name)
    {
        if (id != del_id && name != del_name)
        {
            temp << id <<  name << endl;
        }
    }
    file.close();
    temp.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");
    cout << "Deletion successfull!" << endl;
    system("cls");
    main();
}
void displayFile(){
    string name;
    int id;
    ifstream file;
    file.open("data.txt");
    while (file >> id >> name)
    {
        cout<< id  << name << endl;
        
    }
     file.close();
     main();
}
void updateFile(){
    int mid ,id;
    string name,newname,mname;
     cout << "enter the  id :";
    cin >> mid;
    cout << "enter the  old name:";
    cin >> name;
    cout << "enter the  new name :";
    cin >> newname;
    ifstream file;
    file.open("data.txt");
    ofstream temp;
    temp.open("temp.txt");
    while (file >> id>>name )
    {if(id!=mid&&name!=mname){
        temp<<id<<name<<endl;;
    }
    }
 file.close();
    temp<<mid<<"-->"<<newname;
     file.close();
    temp.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");
    cout<<"Updation Successfull!"<<endl;
    main();

}
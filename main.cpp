#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<stdio.h>

using namespace std;

int stoi(string s);


void addRecord(){

    int pubyear, unqcode;

    string name, author, isbn;

    fstream fout;

    fout.open("bookRecord.csv", ios::out | ios::app);

    cout << "Book Name: ";
    cin.ignore(1000, '\n');
    getline(cin, name);

    cout << "ISBN-13: ";
    getline(cin, isbn);

    cout << "Author: ";
    getline(cin, author);

    cout << "Published Year: ";
    cin >> pubyear;

    cout << "Book's Unique Code: ";
    cin >> unqcode;



    fout << "bookName " << name << ","
         << isbn << ","
         << author << ","
         << pubyear << ","
         << unqcode << "\n";

    fout.close();

}

void viewRecords(){

    fstream fin;

    fin.open("bookRecord.csv", ios::in);
    int count =0 ;

    vector<string> row;
    string line, word, temp;

    while(fin >> temp){
        row.clear();

        getline(fin, line);

        stringstream s(line);

        while(getline(s, word, ',')){
            row.push_back(word);

        }
        count = 1;

        cout << "\nBook Name: " << row[0] << endl;
        cout << "ISBN-13: " << row[1] << endl;
        cout << "Author: " << row [2] << endl;
        cout << "Publish Year: " << row[3] << endl;
        cout << "Book's Unique Code: " << row[4] << endl;
        cout << "-----------------------------" << endl;
    }
    if(count == 0){
        cout << "No Records Found\n";
    }


}

void updateRecord(){

    fstream fin, fout;

    fin.open("bookRecord.csv", ios::in);

    fout.open("bookRecordnew.csv", ios::out);

    int index, unqcode, usrcode, count=0;

    string valu;

    char option;

    string line, word;

    vector<string> row;

    cout << "\nEnter The Book's Unique Code"
         << "To Update Details: ";
    cin >> usrcode;

    Opt:
    cout << "\nEnter Letter Of The Details To Be Updated"
         << "\n"
         << "(Book Name(N)/ISBN-13(I)/Author(A)/Published Year(P)): ";
    cin >> option ;

    if(option == 'n' || option == 'N'){
        index = 0;

        cout << "Enter Book Name: ";
        cin.ignore(1000, '\n');
        getline(cin, valu);
        valu = "data "+valu;

    }else if(option == 'i' || option == 'I'){
        index = 1;

        cout << "Enter ISBN-13: ";
        cin.ignore(1000, '\n');
        getline(cin, valu);

    }else if(option == 'a' || option == 'A'){
        index = 2;

        cout << "Enter Author Name: ";
        cin.ignore(1000, '\n');
        getline(cin, valu);

    }else if(option == 'p' || option == 'P'){
        index =3;

        cout << "Enter Published Year: ";
        cin.ignore(1000, '\n');
        getline(cin, valu);

    }else{
        cout << "\nEnter A Valid Option!\n";
        goto Opt;
    }

    while(!fin.eof()){
        row.clear();

        getline(fin, line);
        stringstream s(line);

        while(getline(s, word, ',')){
            row.push_back(word);
        }

        unqcode = stoi(row[4]);

        int row_size = row.size();

        if(unqcode == usrcode){
            count = 1;

            row[index] = valu;

        if(!fin.eof()){
                for(int i =0; i<row_size - 1; i++){
                    fout << row[i] << ",";
                }
                fout << row[row_size - 1] << "\n";
            }

        }else{
            if(!fin.eof()){
                for(int i = 0; i<row_size - 1; i++){
                    fout << row[i] << ",";
                }
                fout << row[row_size -1] << "\n";
            }

            }
          if(fin.eof()){
                break;

        }

        }
        if(count==0){
            cout << "Record Not Found \n";


    }
    fin.close();
    fout.close();
    remove("bookRecord.csv");
    rename("bookRecordnew.csv","bookRecord.csv");




}

void deleteRecord(){
    fstream fin, fout;

    fin.open("bookRecord.csv", ios::in);

    fout.open("bookRecordnew.csv", ios::out);

    int index, usrcode, unqcode, count = 0;
    string line, word;
    vector<string> row;

    cout << "Enter The Book's Unique Code" << "\n"
         << "To Delete a record: ";
    cin >> usrcode;

    while(!fin.eof()){

        row.clear();
        getline(fin, line);
        stringstream s(line);

        while(getline(s, word, ',')){
            row.push_back(word);
        }
        int row_size = row.size();

        unqcode = stoi(row[4]);

        if(usrcode != unqcode){
            if(!fin.eof()){
                for(int i = 0; i < row_size -1 ; i++){
                    fout << row[i] << ",";
                }
                fout << row[row_size - 1] << "\n";
            }
        }else{
            count = 1;
        }
        if(fin.eof()){
            break;
        }
    }
    if(count == 1){
        cout << "\nRecord Is Deleted\n";
    }else if(count>1){
        cout << "\n" << count << "Records Are Deleted\n";
    }else{
        cout << "\nRecord Not Found\n";
    }
    fin.close();
    fout.close();

    remove("bookRecord.csv");
    rename("bookRecordnew.csv","bookRecord.csv");



}

int main()
{
    int option = 0;
    int i;

    loop:do{
        system("cls");
        cout << "------------------------" << endl;
        cout << "<<Library Management>>" << endl;
        cout << "------------------------" << endl;
        cout << "------------------------" << endl;
        cout << "Created By Abdul Mannan Siddiquei" << endl;
        cout << "------------------------" << endl;

        cout << "1] Add New Book Record." << endl;
        cout << "2] View All Book Records." << endl;
        cout << "3] Update Book Record." << endl;
        cout << "4] Delete Book Record." << endl;
        cout << "\n" << "Enter Your Choice: ";
        cin >> option ;

        switch(option){
            case 1:
                {
                    addRecord();
                    break;
                }
            case 2:
                {
                    viewRecords();
                    break;
                }
            case 3:
                {
                    updateRecord();
                    break;
                }
            case 4:
                {
                    deleteRecord();
                    break;
                }
            default:
                {
                    exit(EXIT_SUCCESS);
                    break;
                }
        }
         cout << "Do You Want To Continue(Y/N): ";
         char choice;
         cin >> choice;

         if(choice == 'y' || choice  == 'Y'){
             goto loop;
         }else{
             exit(EXIT_SUCCESS);
         }
    } while(i<100);
return 0;

}
int stoi(string s)
{
    stringstream ss(s);

    int num;
    ss>>num;
    return num;
}

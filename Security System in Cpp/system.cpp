/*Single user security system with password encryption,storing,decryption and displaying.
Encryption key is that all the password letters are changed to their respective letters present 2 step forward.i.e. a is converted to c, z is converted to b and so on.
Proper encryption and decryption of data works on only password string.
it uses the fstream library for storing and retriving data.*/

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;
int main(){
    int a,i=0;
    string text,old,pass,pass0,pass1,pass2,cepass,oldp,name,roll,user,word,word1;
    string creds[2],cp[2];

    cout<<"******KIIT SECURITY SYSTEM******"<<endl;
    cout<<"________________________________"<<endl;
    cout<<"|         1. Register          |"<<endl;
    cout<<"|          2. Login            |"<<endl;
    cout<<"|     3. Change Password       |"<<endl;
    cout<<"|           4. Exit            |"<<endl;
    cout<<"|____END KIIT SECURITY MENU____|"<<endl;
    do{
        cout<<endl<<endl;
        cout<<"Enter your choice: ";
        cin>>a;
        switch(a){
            case 1:{
                cout<<"________________________________"<<endl;
                cout<<"|_________REGISTER FORM________|"<<endl<<endl;
                cout<<"Please enter your username:- ";
                cin>>name;
                cout<<"Please enter your password:- ";
                cin>>pass0;
                for(auto j=0;j<pass0.size();j++){
                    char c=((pass0[j]-'a'+2)%26)+'a';
                    pass0[j]=c;
                }
                cout<<"Please enter your roll number:- ";
                cin>>roll;

                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open()){
                    of1<<name<<"\n";
                    of1<<pass0;
                    cout<<"Registration Successfull!"<<endl;
                }
                break;
            }
            case 2:{
                i=0;
                cout<<"_________________________________"<<endl;
                cout<<"|___________LOGIN FORM__________|"<<endl<<endl;

                ifstream of2;
                of2.open("file.txt");
                cout<<"Please enter your username:- ";
                cin>>user;
                cout<<"Please enter your password:- ";
                cin>>pass;
                for(auto j=0;j<pass.size();j++){
                    char c=((pass[j]-'a'+2)%26)+'a';
                    pass[j]=c;
                }
                if(of2.is_open()){
                    while(!of2.eof()){
                        while(getline(of2,text)){
                            istringstream iss(text);
                            iss>>word;
                            creds[i]=word;
                            i++;
                        }
                        if(user==creds[0]&&pass==creds[1]){
                            for(auto j=0;j<pass.size();j++){
                                char c=((pass[j]-'a'+24)%26)+'a';
                                pass[j]=c;
                            }
                            cout<<"---LOGIN SUCESSFULL---"<<endl;
                            cout<<"DETAILS"<<endl;
                            cout<<"Username: "+ name<<endl;
                            cout<<"Password: "+ pass<<endl;
                            cout<<"Roll Number: "+ roll<<endl;
                        }
                        else{
                            cout<<"______INCORRECT CREDENTIALS_____"<<endl;
                            cout<<"|          2. Login            |"<<endl;
                            cout<<"|     3. Change Password       |"<<endl;
                            cout<<"|______________________________|"<<endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 3:{
                i=0;
                cout<<"________________________________"<<endl;
                cout<<"|________CHANGE PASSWORD_______|"<<endl<<endl;
                ifstream of0;
                of0.open("file.txt");
                cout<<"Enter the old password:- ";
                cin>>old;
                for(auto j=0;j<old.size();j++){
                    char c=((old[j]-'a'+2)%26)+'a';
                    old[j]=c;
                }
                if(of0.is_open()){
                    while(!of0.eof()){
                        while(getline(of0,text)){
                            istringstream iss(text);
                            iss>>word1;
                            cp[i]=word1;
                            i++; 
                        }
                        if(old==cp[1]){
                            of0.close();
                            ofstream of1;
                            of1.open("file.txt");
                            if(of1.is_open()){
                                cout<<"Enter your new password: ";
                                cin>>pass1;
                                cout<<"Enter your password again: ";
                                cin>>pass2;
                                if(pass1==pass2){
                                    of1<<cp[0]<<endl;
                                    for(auto j=0;j<pass1.size();j++){
                                        char c=((pass1[j]-'a'+2)%26)+'a';
                                        pass1[j]=c;
                                    }
                                    of1<<pass1;
                                    cout<<"Password changed successfully"<<endl;
                                }
                                else{
                                    of1<<cp[0]<<endl;
                                    of1<<old;
                                    cout<<"Password do not match."<<endl;
                                }
                            }
                        }
                        else{
                            cout<<"Please enter a valid password."<<endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 4:{
                cout<<"______Thank You!______"<<endl;
                break;
            }
            default:
            cout<<"Please enter a valid choice."<<endl;
        }
    }
    while(a!=4);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main() {
    string val;
    int key=1,ch,question,del_key,edit_key;
    map<int,string>myTask;
    map<int,int>mymap;
    start:
    cout<< "\n TO-DO LIST"<<endl;
    cout<< "1.Add Task"<<endl;
    cout<< "2.View Task"<<endl;
    cout<< "3.Remove Task"<<endl;
    cout<< "4.Mark Task as Completed"<<endl;
    cout<< "5.Exit"<<endl;
    cout<< "\nSelect your choice : ";
    cin>>ch;
    switch (ch) {
        case 1:
            cout<<endl;
            do{
                cin.ignore();
                cout<<"Enter Your Task Details : ";
                getline(cin,val);
                myTask.insert({key,val});
                mymap.insert({key,0});
                key++;
                cout<< "Do you want to add more Task? (1=Yes / 0=No) : ";
                cin>>question;
            }while(question);
            goto start;
            break;
        case 2:
            cout<<endl;
            for(auto it:myTask){
                if(mymap.at(it.first)==1){
                    cout << "Task-"<<it.first<<" : "<<it.second<<endl;
                }
                else{
                    cout << "Task-"<<it.first<<" : "<<it.second<<endl;
                }
            }
            goto start;
            break;
        case 3:
            cout<<"\nEnter the task number which one you want to remove/delete : ";
            cin>>del_key;
            myTask.erase(del_key);
            mymap.erase(del_key);
            cout<<"\nTask-"<<del_key<<" deleted/removed successfully!"<<endl;
            goto start;
            break;
        case 4:
            cout<<"\nEnter the task number which one you want to mark as completed : ";
            cin >> edit_key;
            try{
                myTask[edit_key]=myTask.at(edit_key);
                mymap[edit_key]=1;
                cout<<"\nTask-"<<edit_key <<" marked as completed successfully!"<<endl;
            }
            catch(const out_of_range &e){  
                cout<<endl<<"Invalid Task Number!"<<endl;  
            } 
            goto start;
            break;
        case 5:
            cout << "\nThank you for using My To-Do List Application!"<<endl;
            exit(0);
            break;
        default:
            cout<<"Invalid choice try again"<<endl;
            goto start;
            break;
    }
    return 0;
}

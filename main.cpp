//Alperen Yasar
//06-06-2020
//I hope this ridiculous application will work for you one day :)

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//node structure of all linked list elements
class Node{
public:
    string name;
    string surname;
    string number0;
    string number1;
    string number2;
    string adress;
    string mail0;
    string mail1;
    Node* next;
};

void addFucntion(Node** head_ref, bool isNew){
    //new node
    Node* newNode = new Node();
    Node* lastNode = *head_ref;

    //Datas
    string name;
    string surname;
    string number0;
    string number1;
    string number2;
    string adress;
    string mail0;
    string mail1;

    //inputs in UI
    string input;
    if(isNew) {
        cout << "Enter the Name: " << endl;
        cin >> name;
        cout << "Enter the Surname: " << endl;
        cin >> surname;
        cout << "Enter the 1. Number: " << endl;
        cin >> number0;
        cout << "Enter the 2 Number (press 0 for skip): " << endl;
        cin >> input;
        if (input == "0") {
            number1 = "";
            number2 = "";
        } else {
            number1 = input;
            cout << "Enter the 3. Number  (press 0 for skip): " << endl;
            cin >> input;
            if (input == "0") {
                number2 = "";
            } else {
                number2 = input;
            }
        }
        cout << "Enter the Adress: " << endl;
        cin.ignore();
        getline(cin, adress);
        cout << "Enter the Email: " << endl;
        //cin.ignore();
        getline(cin, mail0);
        cout << "Enter the 2. Email (press 0 for skip): " << endl;
        //cin.ignore();
        getline(cin, input);
        if (input == "0") {
            mail1 = "";
        } else {
            mail1 = input;
        }
    }

    //inserting the datas to node
    newNode->name = name;
    newNode->surname = surname;
    newNode->number0 = number0;
    newNode->number1 = number1;
    newNode->number2 = number2;
    newNode->adress = adress;
    newNode->mail0 = mail0;
    newNode->mail1 = mail1;

    //This gonne be the last node. therefore it's link will be null.
    newNode->next = NULL;

    //If it's first node, it will be the HEAD node
    if (*head_ref == NULL){
        *head_ref = newNode;
        return;
    }
    //linking
    while (lastNode->next != NULL)
        lastNode = lastNode->next;

    lastNode->next = newNode;

    return;
}

void addImportFunction(Node** head_ref, string name, string surname, string number0, string number1, string number2, string adress, string mail0, string mail1)
{
    //new node
    Node* newNode = new Node();
    Node* lastNode = *head_ref;

    //inserting the datas to node
    newNode->name = name;
    newNode->surname = surname;
    newNode->number0 = number0;
    newNode->number1 = number1;
    newNode->number2 = number2;
    newNode->adress = adress;
    newNode->mail0 = mail0;
    newNode->mail1 = mail1;

    //This gonne be the last node. therefore it's link will be null.
    newNode->next = NULL;

    //If it's first node, it will be the HEAD node
    if (*head_ref == NULL){
        *head_ref = newNode;
        return;
    }

    //linking
    while (lastNode->next != NULL)
        lastNode = lastNode->next;

    lastNode->next = newNode;
}

void editData(Node* head){
    Node* pNode = head;
    string input;
    char response;

    cout << "Which parameter do you want to change: 0 = skip\n 1 = name\n 2 =surname\n 3 = number\n 4 = number 2 \n 5 = number 3 \n 6 = adress \n 7 = main \n 8 = mail 2"<< endl;
    cin >> response;
    if (response == '1') {
        cout << "Enter the Name : " << endl;
        cin >> input;

        pNode->name = input;
    }

    if (response == '2') {
        cout << "Enter the Surname : " << endl;
        cin >> input;

        pNode->surname = input;
    }

    if (response == '3') {
        cout << "Enter the 1. Number : " << endl;
        cin >> input;

        pNode->number0 = input;
    }

    if (response == '4') {
        cout << "Enter the 2 Number : " << endl;
        cin >> input;

        pNode->number1 = input;
    }

    if (response == '5') {
        cout << "Enter the 3. Number : " << endl;
        cin >> input;

        pNode->number2 = input;
    }

    if (response == '6') {
        cout << "Enter the Adress: " << endl;
        cin.clear();
        getline(cin, input);

        pNode->adress = input;
    }

    if (response == '7') {
        cout << "Enter the Email: " << endl;
        cin.clear();
        getline(cin, input);

        pNode->mail0 = input;
    }

    if (response == '8') {
        cout << "Enter the 2. Email: " << endl;
        cin.ignore();
        getline(cin, input);

        pNode->mail1 = input;
    }

    if (response == '0') {
        return;
    }
}



//Listing Function
void showList(Node* node, bool isTrue){
    //if all nodes are empty
    if(node == NULL){
        cout << "There is no person";
    }
    if (isTrue) {
        cout << "Name: " << node->name << " ";
        cout << "Surname: " << node->surname << " ";
        cout << "Number: " << node->number0 << " ";
        cout << "Number 2: " << node->number1 << " ";
        cout << "Number 3: " << node->number2 << " ";
        cout << "Adress: " << node->adress << " ";
        cout << "Email: " << node->mail0 << " ";
        cout << "Email 2:" << node->mail1 << endl;
    }
        //if there are many nodes
    else{
        while (node != NULL){
            cout << "Name: "    << node->name   <<"\n";
            cout << "Surname: " << node->surname<<"\n";
            cout << "Number: "  << node->number0<<"\n";
            cout << "Number 2: "<< node->number1<<"\n";
            cout << "Number 3: "<< node->number2<<"\n";
            cout << "Adress: "  << node->adress <<"\n";
            cout << "Email: "   << node->mail0  <<"\n";
            cout << "Email 2:"   << node->mail1 << endl;
            node = node->next;
            cout << "\n";
        }
    }
}

void exportData(Node* node){
    while (node != NULL){
        ofstream fout;
        fout.open("db.txt", ios::app);
        fout <<"Name:"<< node->name << ">=";
        fout <<"Surn:"<< node->surname << ">=";
        fout <<"Nbr0:"<< node->number0 << ">=";

        if(!node->number1.empty()){
            fout <<"Nbr1:";
        }
        fout<< node->number1 << ">=";

        if(!node->number2.empty()){
            fout <<"Nbr2:";
        }
        fout << node->number2 << ">=";
        fout <<"Adrs:"<< node->adress << ">=";
        fout <<"Ema1:"<< node->mail0 << ">=";
        if(!node->mail1.empty()){
            fout <<"Nbr2:";
        }
        fout<<node->mail1 << ">=" << endl;
        node = node->next;
    }
    cout << "Mission Accomplished" << endl;
}

void importData(Node** node){
    string name;
    string surname;
    string number0;
    string number1;
    string number2;
    string adress;
    string mail0;
    string mail1;

    string line;
    string delimiter = ">=";
    size_t pos = 0;

    ifstream fin;
    fin.open("db.txt");

    while (getline(fin, line)){

        pos = line.find(delimiter);
        name = line.substr( 5, pos-5);

        line.erase(0, pos + delimiter.length());
        pos = line.find(delimiter);
        surname = line.substr(5, pos-5);

        line.erase(0, pos + delimiter.length());
        pos = line.find(delimiter);
        number0 = line.substr( 5, pos-5);

        line.erase(0, pos + delimiter.length());
        pos = line.find(delimiter);
        if(line.substr(0, pos).length() > 4){
            number1 = line.substr(5, pos-5);
        } else number1 = line.substr(0, pos);

        line.erase(0, pos + delimiter.length());
        pos = line.find(delimiter);
        if(line.substr(0, pos).length() > 4){
            number2 = line.substr( 5, pos-5);
        }else number2 = line.substr( 0, pos);

        line.erase(0, pos + delimiter.length());
        pos = line.find(delimiter);
        adress = line.substr( 5, pos-5);

        line.erase(0, pos + delimiter.length());
        pos = line.find(delimiter);
        mail0 = line.substr(5, pos-5);

        line.erase(0, pos + delimiter.length());
        pos = line.find(delimiter);
        if(line.substr(0, pos).length() > 4) {
            mail1 = line.substr(5, pos-5);
        }else mail1 = line.substr(0, pos);

        line.erase(0, pos + delimiter.length());
        addImportFunction(&*node, name, surname, number0, number1, number2, adress, mail0, mail1);
    }
}

void deleteFunction(Node** head_ref, Node* former){
    Node* pNode = *head_ref;
    Node* tempNode;
    if (former == NULL){
        pNode->name = pNode->next->name;
        pNode->surname = pNode->next->surname;
        pNode->number0 = pNode->next->number0;
        pNode->number1 = pNode->next->number1;
        pNode->number2 = pNode->next->number2;
        pNode->adress = pNode->next->adress;
        pNode->mail0 = pNode->next->mail0;
        pNode->mail1 = pNode->next->mail1;
        tempNode = pNode->next;
        pNode->next = pNode->next->next;
        free(tempNode);
        cout << "\n" << endl;
        cout << "Mission Accomplished" << endl;

        return;
    }
    former ->next = pNode->next;
    free(pNode);
    cout << "\n" << endl;
    cout << "Record is deleted!" << endl;

}

void searchFunction(Node* head){
    Node* prev = NULL;
    bool isSearch = false;
    string check;
    Node* current = head; // Initialize current
    string searchData;
    cout << "Enter a number or name to search: " << endl;
    cin >> searchData;
    while (current != NULL){
        string checkname = current->name;
        if ((checkname.find(searchData)) != string::npos){
            showList(current, true);
            isSearch = true;
            cout << "1- Edit   2- Delete  3- Main Menu" << endl;
            cin >> check;
            if (check == "2"){
                deleteFunction(&current, prev);
                return;
            }
            if (check == "1"){
                editData(current);
                return;
            }
        }

        if (current->number0 == searchData){
            showList(current, true);
            isSearch = true;
            cout << "1- Edit   2- Delete    3- Main Menu" << endl;
            cin >> check;
            if (check == "2"){
                deleteFunction(&current, prev);
                return;
            }
            if (check == "1"){
                editData(current);
                return;
            }
        }
        if (current->number1 == searchData){
            showList(current, true);
            isSearch = true;
            cout << "1- Edit   2- Delete    3- Main Menu" << endl;
            cin >> check;
            if (check == "2"){
                deleteFunction(&current, prev);
                return;
            }
            if (check == "1"){
                editData(current);
                return;
            }
        }
        if (current->number2 == searchData){
            showList(current, true);
            isSearch = true;
            cout << "1- Edit   2- Delete    3- Main Menu" << endl;
            cin >> check;
            if (check == "2"){
                deleteFunction(&current, prev);
                return;
            }
            if (check == "1"){
                editData(current);
                return;
            }
        }
        prev = current;
        current = current->next;
    }
    if (isSearch == false){
        cout << "The number does not exist" << endl;
    }
}

//Simple UI
void Beginning() {
    char response;
    cout << "Add(A) - List(L) - Search(S) - Export(E) - Import(I) - Quit(Q)\nWhat do you want to do(Input a Char): "; // Type a number and press enter

}


int main()
{
    Node* head = NULL;

    //response value
    char response; //Note it is a char, not int or whatever
    cout << "Welcome to PhoneBook app! \n\n";
    //This loop healp to show Beginning function
    LOOP:Beginning();

    cin >> response;
    if (response == 'A')
    {
        cout << "You are in the Add Screen\n" << endl;
        addFucntion(&head, true);
        cout << "Record is saved!" << endl;
        goto LOOP;
    }
    else if (response == 'S')
    {
        cout << "Enter a name or number: "<<endl;
        searchFunction(head);
        goto LOOP;
    }
    else if (response == 'L'){

        cout << "All record(s): "<<endl;
        showList(head, false);
        goto LOOP;
    }

    else if (response == 'E'){
        exportData(head);
        goto LOOP;
    }

    else if (response == 'I'){
        importData(&head);
        goto LOOP;
    }

    //quiter
    else if (response == 'Q'){
        return 0;
    }
    else goto LOOP;
}

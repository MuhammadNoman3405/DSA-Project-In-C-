#include<iostream>
#include <fstream>
using namespace std;
bool ascendingOrder = true;
class node {
public:
    int id;
    string name;
    string phone;
    string email;
    string destination1;
    string destination2;
    string brand;
    string Class;
    string status;
    int price;
    int choice;
    string date;
    node* next;
    node* prev;

    node(int val, const string& nam, const string& phon,
         const string& emai,const string& bran,const string& clas, const string& dest1, const string& dest2, const string& dat,const string& stat, int pric) {
        id = val;
        name = nam;
        phone = phon;
        email = emai;
        destination1 = dest1;
        destination2 = dest2;
        brand = bran;
        Class = clas;
        status = stat;
        price = pric;
        date = dat;
        next = NULL;
        prev = NULL;
        choice = 0;
    }
};

node* head = NULL;  // Declare head outside the class

void insertAtTail(int val, const string& nam, const string& phon,
                  const string& emai, const string& bran,const string& clas, const string& dest1, const string& dest2,
				   const string& dat,const string& stat,int pric) {
    node* nNode = new node(val, nam, phon, emai,bran,clas, dest1, dest2, dat,stat,pric);
    if (head == NULL) {
        head = nNode;
        return;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nNode;
    nNode->prev = temp;
}

void insertAtHead(int val, const string& nam, const string& phon,
                  const string& emai,const string& bran,const string& clas, const string& dest1, const string& dest2, const string& dat,const string& stat,int pric) {
    node* nNode = new node(val, nam, phon, emai,bran,clas ,dest1, dest2, dat,stat,pric);
    nNode->next = head;
    if (head != NULL) {
        head->prev = nNode;
    }
    head = nNode;
}

void deletionAtHead() {
    if (head == NULL) {
        cout << "No value to delete" << endl;
        return;
    }
    node* toDelete = head;
    if (head->next != NULL) {
        head = head->next;
        head->prev = NULL;
    } else {
        head = NULL;
    }
    delete toDelete;
}


void deletion(int val) {
    if (head == NULL) {
        cout << "No value to delete" << endl;
        return;
    }
    if (head->id == val) {
        deletionAtHead();
        return;
    }
    node* temp = head;
    while (temp != NULL && temp->id != val) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Value not found in the list" << endl;
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    delete temp;
}

void display() {
	if(head == NULL){
		cout<<"No Users to Display!";
		return;
	}
	cout<<"\nHere, the User's data Fetched ! "<<endl;
    node* temp = head;
    while (temp != NULL) {
    	cout<<endl;
        cout << "ID: " << temp->id << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Email: " << temp->email << endl;
        cout << "Phone: " << temp->phone << endl;
        cout<< "Flying Service : "<< temp->brand<<endl;
        cout<< "Choose Class : "<< temp->Class<<endl;
        cout << "Traveling: " << temp->destination1 << " -> " << temp->destination2 << endl;
        cout << "Date: " << temp->date << endl;
        cout<<"Status : "<<temp->status<<endl;
        cout<<"Price : "<<temp->price<<endl;
        cout << endl;
        temp = temp->next;
    }
}
void DsiplaySingleUser(node* temp){
	 cout << "ID: " << temp->id << endl;
    cout << "Name: " << temp->name << endl;
    cout << "Email: " << temp->email << endl;
    cout << "Phone: " << temp->phone << endl;
    cout << "Flying Service : " << temp->brand << endl;
    cout << "Choose Class : " << temp->Class << endl;
    cout << "Traveling: " << temp->destination1 << " -> " << temp->destination2 << endl;
    cout << "Date: " << temp->date << endl;
    cout << "Status : " << temp->status << endl;
    cout << "Price : " << temp->price << endl;
}
void displayeditDetails(int val) {
    node* temp = head;
    while (temp->id != val) {
        temp = temp->next;
    }
    if(temp != NULL){
    cout<<endl;	
   DsiplaySingleUser(temp);

    if (temp->status == "Purchased (Discounted)") {
        cout << "Already Purchased!" << endl;
    } else {
        do {
            cout << "Enter 1 to Purchase Now!" << endl;
            cin >> temp->choice;
            if (temp->choice == 1) {
                cout << "You Purchased ticket Successfully!";
                temp->status = "Purchased";
            } else {
                cout << "Invalid Choice, Choose Again!" << endl;
            }
        } while (temp->choice != 1);
    }

    cout << endl;
}else{
	cout<<"Invalid User"<<endl;
}
}

void reverse() {
    node* temp = NULL;
    node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }

    ascendingOrder = !ascendingOrder;  // Toggle the order

    if (!ascendingOrder) {
        cout << "Bookings Order is Updated to Descending!" << endl;
    } else {
        cout << "Bookings Order is Updated to Ascending!" << endl;
    }
}
void modifyUserInfo(int val) {
    node* temp = head;
    while (temp->id != val) {
        temp = temp->next;
    }
    if (temp != NULL && temp->status != "Purchased (Discounted)" || "Booked Only(Purchased Now)") {
        cout << "\nEnter updated information for User ID " << val << ":" << endl;
        cout << "New Name: ";
        cin.ignore();
        getline(cin, temp->name);
        cout << "New Phone: ";
        cin >> temp->phone;
        cout << "New Email: ";
        cin >> temp->email;
        cout << "User information updated successfully!" << endl;
    } else {
        cout << "Invalid User ID or cannot modify purchased ticket information." << endl;
    }
}

void displaySummary() {
    if (head == NULL) {
        cout << "No Users to Display!" << endl;
        return;
    }

    int totalRevenue = 0;
    cout << "\nSummary of Purchased Tickets:" << endl;
    node* temp = head;
    while (temp != NULL) {
        if (temp->status == "Purchased (Discounted)" || "Purchased") {
            totalRevenue += temp->price;
            cout << "ID: " << temp->id << " - " << temp->name << " - " << temp->brand << " - " << temp->price << endl;
        }
        temp = temp->next;
    }
    cout << "\nTotal Revenue: " << totalRevenue << endl;
}
void SearchById(int val){
	if(head == NULL){
		cout<<"No Values To Search!"<<endl;
		return;
	}
	node* temp = head;
	while(temp->id != val){
		temp=temp->next;
	}
	if(temp == NULL){
		cout<<"No user Founded With this Key!"<<endl;
		return;
	}else{
		cout<<"User Founded, Here's the details below : "<<endl;
		DsiplaySingleUser(temp);
	}
}
node* reverseRecursive(node* current) {
    if (current == NULL) {
        return head;
    }
     
    node* temp = current->next;
    current->next = current->prev;
    current->prev = temp;

    return reverseRecursive(temp);
}


void writeToFile() {
    ofstream outFile("Summary.docs"); // Create or overwrite the summary file

    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    int totalRevenue = 0;
    node* temp = head;
    while (temp != NULL) {
        if (temp->status == "Purchased (Discounted)" || temp->status == "Purchased") {
            totalRevenue += temp->price;
            outFile << "Welcome To Faisal's Travels Agency : \n" << endl;
            outFile << "ID: " << temp->id << " - " << temp->name << " - " << temp->brand << " - " << temp->price << endl;
        }
        temp = temp->next;
    }
    outFile << "\nTotal Revenue: " << totalRevenue << endl;

    cout << "Summary has been written to 'Summary.docs'." << endl;

    outFile.close();
}
int main() {
	int choice,idCount = 1;
	 int price;
	string name,phone,email,from,to,date,brand,clas,status;
	cout<<"__________Welcome to Faisal's Travel Agency!__________"<<endl<<endl;
	do{ 
	  cout<<"Etner Your Choice :- "<<endl;
    cout << "1. Book/Buy a Seat" << endl;
    cout << "2. Display the Bookings" << endl;
    cout << "3. Buy Already Booked ticket" << endl;
    cout << "4. Cancel Ticket" << endl;
    cout << "5. Change Bookings in Reverse Order" << endl;
    cout << "6. Search User" << endl;
    cout << "7. To Modify info"<<endl;
    cout << "8. To Display Summary"<<endl;
    cout << "9. To DownLoad Summary"<<endl;
    cout << "10. Exit" << endl;
		cin>>choice;
		switch(choice){
			case 1:		
		cout<<"\nBook a ticket, Choose your Destination and Class :) "<<endl<<endl;
		cout<<"Your Name : ";
		cin.ignore();
		cin>>name;
		cout<<"Mobile No : ";
//		cin.ignore();
		cin>>phone;
		cout<<"Email : ";
//		cin.ignore();
		cin>>email;
			cout<<"Choose Your Flying Service (Only in Integers) :- \n1. PIA\n2. Fly Emirates"<<endl;
//			cin.ignore();
				do{
		cin>>choice;
		if(choice == 1){
			brand = "PIA";
			cout<<brand<<"(Selected)"<<endl;
		}else if(choice == 2){
			brand = "Fly Emirates";
			cout<<brand<<"(Selected)"<<endl;
		}else {
			cout<<"Invalid Choice. Choose Again! (Only in Integers) "<<endl;
		}
	}while(choice > 2);
		cout<<"Choose Your Class (Only in Integers):- \n1. Bussines Class\n2. Economy Class"<<endl;
//		cin.ignore();
		do{
			cin>>choice;
				if(choice == 1){
			clas = "Bussines Class";
			cout<<clas<<"(Selected)"<<endl;
			 price = 500;
		}else if(choice == 2){
			clas = "Economy Class";
			cout<<clas<<"(Selected)"<<endl;
		  price = 350;
		}else {
		cout<<"Invalid Choice. Choose Again!"<<endl;
		}
		}while(choice > 2);
		cout<<"Travelling From : ";
//		cin.ignore();
		cin>>from;
		cout<<"Travelling To : ";
//		cin.ignore();
		cin>>to;
		cout<<"Date (DD-MM-YYYY): ";
//		cin.ignore();
		cin>>date;
		cout<<"If You Purchased Now You will get 10% discount \n1.Purchase Now \n2.Book Only"<<endl;
//		cin.ignore();
		do{
		cin>>choice;
		if(choice == 1){
			status = "Purchased (Discounted)";
		 price = (price/100)*90;
		 cout<<"Purchased SuccesFully"<<endl;
		}else if(choice == 2){
			status = "Booked Only(Purchased Now)";
			cout<<"Booked SuccesFully"<<endl;
		}else{
			cout<<"Invalid Choice. Choose Again!"<<endl;
		}
	}while(choice > 2);
		insertAtTail(idCount, name, phone, email,brand,clas, from, to, date, status, price);
		idCount++;
		break;
		case 2:
			display();
			break;
			case 3:
				cout<<"Enter ID of the User : ";
//				cin.ignore();
				cin>>choice;
//				idCount = choice;
				displayeditDetails(choice);
				break;
				case 4:
					cout<<"Enter the ID of the User to Cancel the Ticket : "<<endl;
//					cin>>idCount;
                    cin>>choice;
					deletion(choice);
					cout<<"Canceled SuccessFully!";
					break;
					case 5:
					reverse();
					cout<<"Bookings Order is Updated!";
		break;
		case 6:
		cout<<"Enter the Id to Search : ";
//		cin.ignore();
		cin>>choice;
		SearchById(choice);
		break;
		case 7:
        cout << "Enter the ID of the User to Modify Information: ";
//        cin.ignore();
//        cin >> idCount;
          cin>>choice;
        modifyUserInfo(choice);
        break;
        case 8:
        displaySummary();
        break;
        case 9:
		writeToFile();
		cout<<"Downloded SuccessFully.";
		break;
        case 10:
		cout<<"Existing...";
		break;			
		default:
			cout<<"Inavlid Input ";
		}
		cout<<endl<<endl;
	}while(choice != 10);
        
}


#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;
	
string cars[5];
string services[5];

int main() {
	
	string line;
	fstream inFile;
	
	
//		--------------------------- READING CARS FILE ---------------------------------
	
	inFile.open("cars.csv", ios::in);
	
	if(inFile.is_open()) {
		
		int i = 0;
	
		while (!inFile.eof()) {
			i = i+1;
			
			if(getline(inFile, line)) {
				
				if (i == 1) {
					continue;
				} else {
					string istr;
					stringstream ss;
					ss << i-1;
					ss >> istr;
					cars[i-1] = istr + "," + line;
				}
				
			} else {
				cout << "Failed to read line" << endl;
			}
			
			if(i == 5){
				break;
			}
		}
		
		inFile.close();
		
	} else {
		cout << "CARS FILE NOT OPENED";
	}
		
//		--------------------------- READING SERVICES FILE ---------------------------------
		
		inFile.open("services.csv", ios::in);
	
		if(inFile.is_open()) {
			
			int i = 0;
		
			while (!inFile.eof()) {		
				i = i+1;
				
				if(getline(inFile, line)) {
					if (i == 1) {
						continue;
					} else {
						string istr;
						stringstream ss;
						ss << i-1;
						ss >> istr;
						services[i-1] = istr+","+line;
					}
					
				} else {
					cout << "Failed to read line" << endl;
				}
				
				if(i == 5) {
					break;
				}
			}
			
			inFile.close();
			
			
		} else {
			cout<<"Failed to open file"<<endl;
		}

//		--------------------------- MAIN ---------------------------------

string fName;
string lName;
string address;
int shopAgain = 3;
bool shopBool = true;

int choice = 0;

cout << "                            -------------------WELCOME TO OUR SHOW ROOM-------------------------\nPlease enter your first name:\n";

cin>>fName;

cout << "\nPlease enter your last name:\n";
cin >> lName;

cout << "\nEnter your address:\n";
cin >> address;

while(shopBool){
	
	while (choice !=1 || choice != 2){
		
		cout<<"\n\n";
	
		if(shopAgain == 1) {
			cout<< "WELCOME BACK! ";
		}
	
		cout << "WHAT WOULD YOU LIKE TO DO?(Input a number)\n\n  1) Shop for a new car\n  2) Look for our services\n";
		
		cin>>choice;
		
		if(choice == 1 || choice == 2){
			break;
			} else {
			cout<<"Please enter a valid choice";
			}
		
		}
		
		
		if (choice == 1 ) {
			int carChoice = 0;
			
			while (carChoice < 1 || carChoice > 4){
				cout<<endl<<endl;
				cout<<"The cars currently available in our show room are(select by serial no.):\n\n\n";
				
				cout << "--------------------------------------------------------------------------------------------------\n\n";
				std::cout << std::left << std::setw(18) << "SR. NO";
				std::cout << std::left << std::setw(18) << "CAR MAKE";
				std::cout << std::left << std::setw(18) << "MODEL";
				std::cout << std::left << std::setw(18) << "YEAR";
				std::cout << std::left << std::setw(18) << "COLOR";
				std::cout << std::left << std::setw(18) << "PRICE";
				cout<<endl;
				cout << "--------------------------------------------------------------------------------------------------\n";
				
				for (int i = 0; i <= 4; i++){
					string line = cars[i];
				
					stringstream ss(line);
					
					while (ss.good()) {
			        string substr;
			        getline(ss, substr , ',');
			        std::cout << std::left << std::setw(18) << substr;
					}
					cout<<endl;
				}
				
				cout << "\n\nEnter your choice:";
				cin >> carChoice;
				
				if(carChoice < 1 || carChoice > 4){
					cout << "\n\n\n\n\n\n!!!!!!!!!!!!!!!!!!!!!!!!!! PLEASE ENTER A VALID CHOICE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n\n\n\n";
				}
				
			}
			
			stringstream ss(cars[carChoice]);
			string substr;
			getline(ss, substr, ',');
			getline(ss, substr, ',');
			string boughtCarName = substr;		
			getline(ss, substr, ',');
			string boughtCarModel = substr;	
			getline(ss, substr, ',');
			string boughtCarYear = substr;	
			getline(ss, substr, ',');
			string boughtCarColor = substr;	
			getline(ss, substr, ',');
			string boughtCarPrice = substr;
			cout << "\n\nFirst Name:\n    " << fName << "\nLast Name:\n    " << lName << "\nAddress:\n    " << address << "\nBought Car Name:\n    " << boughtCarName << "\nBought Car Model:\n    " << boughtCarModel << "\nYear of Manufacturing:\n    " << boughtCarYear << "\nBought Car Color:\n    "<< boughtCarColor << "\nPrice:\n    " << boughtCarPrice;
			
		}
		
		else if (choice == 2 ) {
			
			int serviceChoice = 0;
			
			while (serviceChoice < 1 || serviceChoice > 4 ){
				
				cout<<endl<<endl;
				cout<<"The services we are currently providing are(select by serial no.):\n\n\n";
			
				cout << "-----------------------------------------------------------\n\n";
				std::cout << std::left << std::setw(25) << "SR. NO";
				std::cout << std::left << std::setw(25) << "SERVICE NAME";
				std::cout << std::left << std::setw(25) << "COST";
				cout<<endl<<endl;
				cout << "-----------------------------------------------------------\n";
				
				for (int i = 0; i <= 4; i++){
					string line = services[i];
				
					stringstream ss(line);
					
					while (ss.good()) {
			        string substr;
			        getline(ss, substr , ',');
			        std::cout << std::left << std::setw(25) << substr;
					}
					
					cout<<endl;
				}
				
				cout << "\n\nEnter your choice:";
				cin >> serviceChoice;
				
				if(serviceChoice < 1 || serviceChoice > 4 ) {
					cout << "\n\n\n\n\n\n!!!!!!!!!!!!!!!!!!!!!!!!!! PLEASE ENTER A VALID CHOICE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n\n\n\n";
				}
				
			}
			
			stringstream ss(services[serviceChoice]);
			string substr;
			getline(ss, substr, ',');
			getline(ss, substr, ',');
			string boughtServiceName = substr;		
			getline(ss, substr, ',');
			string boughtServicePrice = substr;
			cout << "\n\nFirst Name:\n    " << fName << "\nLast Name:\n    " << lName << "\nAddress:\n    " << address << "\nBought Car Name:\n    " << boughtServiceName << "\nPrice:\n    " << boughtServicePrice;
		}
		
		while(shopAgain != 0 && shopAgain !=1){
		
			cout << "\n\n\nWould you like to shop again? (Enter 0 for no and 1 for yes):\n";
			cin >> shopAgain;
			
			if(shopAgain == 0){
				shopBool = false;
				cout << "\n\n\n\n-------------------THANKS FOR SHOPPING HERE! HAVE A NICE DAY-------------------\n\n\n\n";
			}
			else if(shopAgain == 1){
				shopBool = true;
			}
			else {
				cout << "\n\nPlease enter a valid choice!";
			}
		}
		
	}
}

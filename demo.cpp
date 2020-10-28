#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Student{
	string ime;
	string prezime;
	int jmbag;
	float ocjena;
};

int brr=0; //pomocni counter za indexe studenta u svim funkcijama
Student studs[100]; //array lista tipa strukture Student - puni se kroz getAll()


void funcList(){
	cout<<"<<---dobrodosli--->>"<<endl;
	cout<<"1. unos studenta// create()"<<endl;
	cout<<"2. pretraga po jmbag // read()"<<endl;
	cout<<"3. pretraga po rasponu ocjena // filter_grade() "<<endl;
	cout<<"4. pretraga po pocetnom slovu // filter_name()"<<endl;
	cout<<"5. kraj"<<endl;
}


void create(string ime,string prezime,int jmbag,float ocjena){
	fstream baza("students.csv",fstream::out | fstream::app); //appendmode 
		
	
	baza<<jmbag<<","<<ime<<","<<prezime<<","<<ocjena<<endl;
		
	cout<<"Student uspjesno kreiran!"<<endl;
	
}

void getAll(){  
	
	string imeI, prezimeI, ocjenaI, jmbagI; //varijable iz .csv
	vector<string>ime_I;  //vektori s podacima
	vector<string>prezime_I;
	vector<float>ocjena_I;
	vector<int>jmbag_I;
	int jmbagg; //za stringstream u int/float
	float ocjenaa;
	
	brr=0; //counter studenta (global)
	ifstream baza("students.csv"); 
	if (baza.is_open()) 
	{
		while (!baza.eof()) 
		{	
			getline(baza, jmbagI, ','); 
			istringstream(jmbagI)>>jmbagg; //convert iz string u int
			jmbag_I.push_back(jmbagg);
			
			getline(baza, imeI, ',');
			ime_I.push_back(imeI);
			
			getline(baza, prezimeI, ',');
			prezime_I.push_back(prezimeI);
			
			getline(baza, ocjenaI, '\n');
			istringstream(ocjenaI)>>ocjenaa;
			ocjena_I.push_back(ocjenaa);
			
			brr=brr+1; 
		}
		baza.close(); 
		
		for(int i=0;i<brr-1;i++){	
			studs[i].ime=ime_I[i];
			studs[i].prezime=prezime_I[i];
			studs[i].ocjena=ocjena_I[i];
			studs[i].jmbag=jmbag_I[i];
			
			/* //ispis ucitanih studenta
			cout<<"Student: "<<i+1<<"."<<endl;
			cout<<studs[i].ime<<endl;
			cout<<studs[i].prezime<<endl;
			cout<<studs[i].ocjena<<endl;
			cout<<studs[i].jmbag<<endl<<endl<<endl;
			*/  	
		}
				
	}
	else {
		cout<<"Ne mogu ucitati bazu"<<endl; 
	}
	
}

void read(int jmbag){
	
	for(int i=0;i<brr-1;i++){	
		if(studs[i].jmbag==jmbag){
			cout<<"jmbag: "<<studs[i].jmbag<<", ";
			cout<<"ime: "<<studs[i].ime<<", ";
			cout<<"prezime: "<<studs[i].prezime<<", ";
			cout<<"ocjena: "<<studs[i].ocjena<<endl;
		}
	}	
}

void filter_grade(char lge[1],float ocjena){	
	//equal
	if(lge[0]=='e'){
		for(int i=0;i<brr-1;i++){
			if(studs[i].ocjena==ocjena){
				cout<<"jmbag: "<<studs[i].jmbag<<", ";
				cout<<"ime: "<<studs[i].ime<<", ";
				cout<<"prezime: "<<studs[i].prezime<<", ";
				cout<<"ocjena: "<<studs[i].ocjena<<endl;
			}
		}	
	}
	//lower than
	if(lge[0]=='l'){
		for(int i=0;i<brr-1;i++){
			if(studs[i].ocjena<ocjena){
				cout<<"jmbag: "<<studs[i].jmbag<<", ";
				cout<<"ime: "<<studs[i].ime<<", ";
				cout<<"prezime: "<<studs[i].prezime<<", ";
				cout<<"ocjena: "<<studs[i].ocjena<<endl;
			}
		}
	}
	//greater than
	if(lge[0]=='g'){
		for(int i=0;i<brr-1;i++){
			if(studs[i].ocjena>ocjena){
			cout<<"jmbag: "<<studs[i].jmbag<<", ";
			cout<<"ime: "<<studs[i].ime<<", ";
			cout<<"prezime: "<<studs[i].prezime<<", ";
			cout<<"ocjena: "<<studs[i].ocjena<<endl;
			}
		}
	}	
}

void filter_name(string ime,char opc[]=0){
	
	//opcionalni argument false
	if(!opc){
		for(int i=0;i<brr-1;i++){	
			if(studs[i].ime.at(0)==ime.at(0)){
			cout<<studs[i].ime<<endl;
			cout<<studs[i].prezime<<endl;
			}
		}
		return;
	}
	
	if(opc[0]=='u'){
		for(int i=0;i<brr-1;i++){
		
			if(studs[i].ime.at(0)==ime.at(0)){
			transform(studs[i].ime.begin(), studs[i].ime.end(),studs[i].ime.begin(), ::toupper);
			transform(studs[i].prezime.begin(), studs[i].prezime.end(),studs[i].prezime.begin(), ::toupper);
			cout<<studs[i].ime<<endl;
			cout<<studs[i].prezime<<endl;
			}
		}
	}
	if(opc[0]=='l'){
		for(int i=0;i<brr-1;i++){
		
			if(studs[i].ime.at(0)==ime.at(0)){
			transform(studs[i].ime.begin(), studs[i].ime.end(),studs[i].ime.begin(), ::tolower);
			transform(studs[i].prezime.begin(), studs[i].prezime.end(),studs[i].prezime.begin(), ::tolower);
			cout<<studs[i].ime<<endl;
			cout<<studs[i].prezime<<endl;
			}
		}
	}
}


int main(){
	int izbor; //za switchcase
	string uIme,uPrezime; //zad 4.1 
	string pIme; //zad 4.4
	getAll(); //ucitavanje podataka iz .csv i sprmanje u memoriju
	cout<<"studenti uspjesno ucitani!"<<endl;
	
	
	pocetak:
	getAll(); //ucitavanje podataka iz .csv i sprmanje u memoriju
	system("pause");
	system("cls");
	
	
	funcList(); //izbornik
	cout<<"unesi broj za funkciju : ";
	cin>>izbor;
	
	switch(izbor){
		case 1:
			//zadatak 4.1
			
			float uOcjena;
			float uJmbag;
			
			cout<<"unesi ime: ";
			cin>>uIme;
			cout<<"unesi prezime: ";
			cin>>uPrezime;
			cout<<"unesi ocjena: ";
			cin>>uOcjena;
			cout<<"unesi jmbag: ";
			cin>>uJmbag;
			
			create(uIme,uPrezime,uJmbag,uOcjena);
						
			//hardkodirano dodavajne
			/*
			create("marko","maric",23427324,3.5);
			create("ivan","ivic",234,2.5);
			create("ana","anic",23427314,3.9);
			create("pero","peric",23427324,4.7);
			create("mirko","miric",23427324,4.2);
			*/
			goto pocetak;
		case 2:
			//zadatak 4.2
			int pJmbag;
			cout<<"upisi jmbag: ";
			cin>>pJmbag;
			read(pJmbag);
	 		goto pocetak;
 		case 3:
 			//zadatak 4.3
			char lge[1]; //lower,greater,equal
			float pOcjena; 
			cout<<"unesi ocjenu: ";
			cin>>pOcjena;
			cout<<"unesi usporedbu ocjene --> manje(l) vece(g) jednako(e): ";
			cin>>lge;
			while(lge[0]!='l' and lge[0]!='g' and lge[0]!='e'){
				cout<<"pogresan unos! unesi manje(l) vece(g) jednako(e)";
				cin>>lge;
			}
			filter_grade(lge,pOcjena);
			goto pocetak;
			
		case 4:
			//zadatak 4.4
			char opc[1]; //opcinalan unos
			char izb[1]; //izbor za opcionalno
			cout<<"Unesi pocetno slovo: ";
			cin>>pIme;
			cout<<"Ispis velikim ili malim slovima? --> (d/n) : ";
			cin>>izb;
			while(izb[0]!='d' and izb[0]!='n'){
				cin>>izb;
			}
			if(izb[0]=='d'){
				cout<<"Veliko ili malo slovo --> (u/l) : ";
				cin>>opc;
				while(opc[0]!='u' and opc[0]!='l'){
				cin>>opc;
				}
				filter_name(pIme,opc);
			}
			else{				
				filter_name(pIme,0);
				goto pocetak;		
			}
			
			
			
			goto pocetak;
		case 5:
		 	goto kraj;
		  	
		
		
		
	}
	
	kraj:
	system("pause");
	return 0;
	
};

#include <fstream> //for file I/O
#include <iostream>
#include <string> 
#include <limits>

using namespace std;

class Users {
public:
	int i;
 string onoma;
 string eponimo;
 int  AFM;
 int Miles; 
 int BankBalance;
 
 
 Users(){
  onoma="N/A";
  eponimo="N/A";
  AFM=00000;
  Miles=0000;
  BankBalance=0000;	
 	
 }
 
 Users(string onoma,string eponimo,int AFM,int Miles,int BankBalance){
     cout << "File updated with entry " << onoma << endl ;
 	 ofstream outfile("fdata.txt",std::fstream::app); //create ofstream object	
 	 outfile << onoma << " " << eponimo << " " << AFM << " " << Miles << " " << BankBalance << " " << endl; //display the data\	

}

void AddClient(){
	cout << "Dwste Onoma: \n";
	cin >> onoma;
    cout << "Dwste Eponimo: \n";
    cin >> eponimo;
    cout << "Dwste AFM: \n";
    cin >> AFM;
    cout << "Dwste Milia: \n";
    cin >> Miles;   
    cout << "Dwste BankBalance: \n";
	cin >> BankBalance;
	Users(onoma,eponimo,AFM,Miles,BankBalance);
}

 	
void Deletedata(){
    int x=0; 
    int tempAFM;
    ifstream infile("fdata.txt");
    ofstream temp("temp.txt"); // temp file for input of every student except the one user wants to delete
	
    cout << " Eisagete to AFM pou thelete na svisete apo tin Vasi " << endl;
    cin >> tempAFM;

    while(infile >> onoma >>  eponimo >>  AFM  >> Miles >>  BankBalance)
    {
        if(tempAFM!=AFM){ // if there are students with different name, input their data into temp file
            temp << onoma << " " << eponimo << " " << AFM << " " << Miles << " " << BankBalance << " " << endl;
        }
        if(tempAFM==AFM){ // if user entered correct name, x=1 for later output message that the user data has been deleted
            x=1;
        }
    }
    infile.clear(); // clear eof and fail bits
    infile.seekg(0, ios::beg);
    infile.close();
    temp.close();
    remove("fdata.txt"); 
    rename("temp.txt","fdata.txt");
    if(x==0){ // x was set to 0 at start, so if it didn't change, it means user entered the wrong name
        cout << "Den iparxei pelatis me to sigkekrimeno AFM" << endl;
    }
    else{ // x is not 0, it means user entered the correct name, print message that students data has been deleted
        cout << "O pelatis diagrafike." << endl;
    }
  }
  
 
 void ShowUsers() {
	cout << "----------------------------\n\n\n\n";
	cout << "------- Xristes ------\n";
 	ifstream infile("fdata.txt"); //create ifstream object
   while (infile >> onoma >> eponimo >> AFM >> Miles >> BankBalance)
    {
 	
 	cout << "Stoixeia: " << onoma << " " << eponimo << " " << AFM << " " << Miles << " " << BankBalance << " " << endl; //display the data\	
  	}
  	 cout << "----------------------------\n";
 }
 


}
};

class Diadromes{
public:
	string Anaxorisi;
 	string Afiksi;
	double kostos;
 	double MileDiadromi;
	

Diadromes(){
  Anaxorisi="N/A";
  Afiksi="N/A";
  kostos=00000;
  MileDiadromi=0000;	
 }

Diadromes(string Anaxorisi,string Afiksi,double kostos,double MileDiadromi)
{
	cout << "I vasi ananeothike me tin diadromi  " << Anaxorisi << "-" << Afiksi << endl;
	ofstream outfile("Diadromes.txt",std::fstream::app); //create ofstream object	
 	outfile << Anaxorisi << " " << Afiksi << " " << kostos << " " << MileDiadromi << endl; //display the data\	
	
}

void adddiadromes(){
	cout << "Dwste poli anaxorisis: \n";
	cin >> Anaxorisi;
    cout << "Dwste poli proorismou: \n";
    cin >> Afiksi;
    cout << "Dwste kostos diadromis: \n";
    cin >> kostos;
    cout << "Dwste Milia diadromis: \n";
    cin >> MileDiadromi;   
	Diadromes(Anaxorisi,Afiksi,kostos,MileDiadromi);
}



void Deletedata(){
    int x=0; 
    string tempAnax;
    ifstream infile("Diadromes.txt");
    ofstream temp("temp2.txt"); // temp file for input of every flights except the one user wants to delete
	
    cout << " Eisagete thn poli Anaxorisis pou thelete na svisete apo tin Vasi " << endl;
    cin >> tempAnax;

    while(infile >> Anaxorisi >>  Afiksi >>  kostos  >> MileDiadromi)
    {
        if(tempAnax.compare(Anaxorisi) != 0){ // if there are flights with different name, input their data into temp file
            temp << Anaxorisi << " " << Afiksi << " " << kostos << " " << MileDiadromi << endl;
        }
        if(tempAnax.compare(Anaxorisi) == 0){ // if user entered correct name, x=1 for later output message that the user data has been deleted
            x=1;
        }
    }
    infile.clear(); // clear eof and fail bits
    infile.seekg(0, ios::beg);
    infile.close();
    temp.close();
    remove("Diadromes.txt"); 
    rename("temp2.txt","Diadromes.txt");
    if(x==0){ // x was set to 0 at start, so if it didn't change, it means user entered the wrong name
        cout << "Den iparxei ptisi me th sigkekrimeni poli anaxorisis" << endl;
    }
    else{ // x is not 0, it means user entered the correct name, print message that students data has been deleted
        cout << "I ptisi diagrafike." << endl;
    }
  }
  



void ShowDiadromes() {
	 cout << "----------------------------\n\n\n\n";
	 cout << "------- Diadromes ------\n";
 	ifstream infile("Diadromes.txt"); //create ifstream object
 	int i=0 ;
   while (infile >> Anaxorisi >> Afiksi >> kostos >> MileDiadromi)
    {
 	
 	cout << ++i <<"." << "Diadomi : " << Anaxorisi << " " << Afiksi << " " << kostos << " " << MileDiadromi  << endl; //display the data\	
  	}
  	 cout << "----------------------------\n";
 }

}
};

//-------------------------------------------------------------------
	std::fstream& GotoLine(std::fstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}

void epilogiptisis(){
			int ptisi=0;
 		 	cout << "Dialekse Ptisi\n";
    	    cin >> ptisi;
    	    fstream file("Diadromes.txt");
		    GotoLine(file,ptisi); 
		   	string Anaxorisi;
 			string Afiksi;
			double kostos;
 			double MileDiadromi;
            file >> Anaxorisi >> Afiksi >> kostos >> MileDiadromi;
		    cout  << "Diadomi : " << Anaxorisi << " " << Afiksi << " " << kostos << " " << MileDiadromi  << endl; //display the data
		    
		    
}

string  epilogixristi(){
	string xristis;
	string onoma;
	string eponimo;
 	int  AFM;
 	int Miles; 
 	int i;
 	int BankBalance;
    string line;
    string array[500];
	ifstream fin("fdata.txt"); //opening an input stream for file test.txt
    while (getline (fin, line)){
    	cout << line << endl;
        array[i]= line;
		i++;
	}

	cout << "Please enter username\n ";
	cin >> xristis ;
	for(int counter = 0;counter<500;counter++){
		if(array[counter] == xristis){
		   return array[i+2]; 
		}
	}

}


int main() {


 // Users t1;
 // t1.ShowUsers();
  //Users t2("Antonis","Maramathas",121212,300,1000);
 //Users t3("Mitsos","Georgiadis",15234,300,1000);
 // t3.Deletedata();
  
  //Diadromes D1;
 // D1.ShowDiadromes();
 // Diadromes D2("Athina","Kavala",1500,1000);
   
cout <<"               /								    	\n" ;
cout <<"             /  \_____________________________________  _   \n";
cout <<"            / - ______        ________________          \_`, \n";
cout <<"           -(_______            -=   -=  -=    AEGEAN     )\n";
cout <<"                    \--------=============----------------` \n";


   
         int choice =0,choice2=0,ptisi=0;
    cout << "\t \t Aegean Airlines Database" <<endl;
     cout << " \t \t-------------------------- \n";	
  	cout << " Parakalo Dwste 1 an eiste Diaxeiristis.\n Otidipote allo gia aplh provoli dromologion. \n Gia termatismo Patiste to 0 \n  "; 	
    cin >> choice ;
 	while(choice != 0)
    {
        if (choice==1)
      	  {
       			 cout << "Leitourgia Admin !\n"	;	
        		 cout << "Epiloges:  \n Pelatis \n ----------- \n 1.Prosthiki \n 2.Provoli \n 3.Diagrafi \n" ;	
        		 cout << " Diadromes: \n ----------- \n 4.Prosthiki \n 5.Provoli \n 6.Diagrafi \n 7.Prosthiki Bonus \n 8.Statistika Parakalo Patiste tin Epilogi sas\n  "	;		
        		 cin >> choice2;
       		 	 if (choice2==1)
      	 		 {
       		     cout << "Prosthiki Neou Pelati \n\n " ;
	      	  	 Users U1;
         		 U1.AddClient();
         		 }
        else if (choice2==2){
     			 Users U1;
     		 	 U1.ShowUsers();
        		 }	
           else if (choice2==3){
		 	
     			cout << "Diagrafi! \n" ;
     			Users u3;
     			u3.Deletedata();
     			exit (1);
        		 }	
           else if (choice2==4){
		 	
     			cout << "Diadromes Prosthiki Diadromis\n";
     			Diadromes D2;
     			D2.adddiadromes();
     			exit (1);
         		}		
           else if (choice2==5){
		 	
				Diadromes D3;
          		 D3.ShowDiadromes();
        	 }	
           else if (choice2==6){
		 	
			cout << "Diagrafi! \n" ;
     		Diadromes D3;
     		D3.Deletedata();
     		exit (1);
         	}	
            else if (choice2==7){
		 	
     		cout << "Prosthiki Bonus! \n Under Constraction\n " ;
     		exit (1);
         }	
                 else if (choice2==8){
		 	
     		cout << "Statistika! Under Constraction \n " ;
     		exit (1);
         }	
         
		 
		}
         else if (choice==0){
		 	
     		cout << "Eksodos! " ;
     		exit (1);
         }	
         else 
		 {
           cout << "Leitourgia Xristi !\n";
           Diadromes D1;
           D1.ShowDiadromes();
       
           epilogiptisis();
               epilogixristi();
           
           

 }
		 
		 
		 
   		 cout << "\t \t \n\n Aegean Airlines Database" <<endl;
     	cout << " \t \t-------------------------- \n";	
  		 cout << " Parakalo Dwste 1 an eiste Diaxeiristis.\n Otidipote allo gia aplh provoli dromologion. \n Gia termatismo Patiste to 0 \n  "; 	
  		 cin >> choice ;
     }     	
 
 return 0;
}





#include <bits/stdc++.h>
using namespace std;

void menu(char &scelta){

	cout << "===== GESTIONE UNIVERSITARIA =====\n";
	cout << "0. Carica dati da file.\n";
	cout << "1. Cerca corsi di uno studente (Matricola).\n";
	cout << "2. Cerca corsi di uno studente (Cognome).\n";
	cout << "3. Elenca studenti iscritti ad un corso.\n";
	cout << "4. Stampa dati esami di un corso.\n";
	cout << "5. Numero di studenti per corso.\n";
	cout << "6. Numero di materie per corso.\n";
	cout << "7. Cerca materie per descrizione.\n";
	cout << "8. Inserisci un nuovo studente.\n";
	cout << "9. Salva i dati su file.\n";
	cout << "X. Esci.\n";
	cin >> scelta;
}

struct corso{

    string codice_corso;
    string descrizione_corso;

};

struct materia{

    string codice_materia;
    string descrizione_materia;
    corso codice_corso;

};

struct studente{

    string matricola_studente;
    string cognome_studente;
    string nome_studente;
    corso codice_corso;

};

vector <string> corso;
vector <string> materia;
vector <string> studente;

void caricaDati(){

    ifstream fin("corsi.csv");
    string s;

    getline(fin, s);

    while (!fin.eof()) {

        string codice_corso, descrizione_corso, codice_materia, descrizione_materia;
        string matricola_studente, cognome_studente, nome_studente;

        getline(fin, codice_corso, ',');

        if (codice_corso == "") { // ho trovato una riga vuota

            break;

            }

        getline(fin, descrizione_corso, ',');

        getline(fin, codice_corso, ',');

        getline(fin, codice_materia, ',');

        getline(fin, descrizione_materia, ',');

        getline(fin, matricola_studente, ',');

        getline(fin, cognome_studente, ',');

        getline(fin, nome_studente);

    }

    fin.close();

}

int main(){

    char scelta;

    menu(scelta);
	while(scelta != 'X'){

	    switch(scelta){

        case '0':

            break;

        case '1':

            break;

        case '2':

            break;

        case '3':

            break;

        case '4':

            break;

        case '5':

            break;

        case '6':

            break;

        case '7':

            break;

        case '8':

            break;

        case '9':

            break;

	    }

       	system("pause");
        system("cls");

        menu(scelta);
  	  }
	cout<<"fine sessione di lavoro "<<endl;

    return 0;
}

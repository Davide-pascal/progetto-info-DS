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
	cout << "==================================\n";
	cin >> scelta;
	cout << "==================================\n";
}

struct studente{

    string codice_corso;
    string descrizione_corso;
    string codice_materia;
    string descrizione_materia;
    string matricola_studente;
    string cognome_studente;
    string nome_studente;
};

vector<studente> studenti;

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

        getline(fin, codice_materia, ',');

        getline(fin, descrizione_materia, ',');

        getline(fin, matricola_studente, ',');

        getline(fin, cognome_studente, ',');

        getline(fin, nome_studente);

        studente nuovo_studente = {codice_corso, descrizione_corso, codice_materia, descrizione_materia, matricola_studente, cognome_studente, nome_studente};
        studenti.push_back(nuovo_studente);

    }

    fin.close();

}

void stampa() {
    for ( auto s : studenti) {
        cout << "Codice Corso: " << s.codice_corso << ", Descrizione Corso: " << s.descrizione_corso << ", Codice Materia: " << s.codice_materia << ", Descrizione Materia: " << s.descrizione_materia << ", ";
        cout << "Matricola: " << s.matricola_studente << ", Nome: " << s.nome_studente << ", Cognome: " << s.cognome_studente << endl;
    }
}

int main(){
    string matricola;
    string cognome;
    char scelta;
    map<string,string> ric_c;
    map<string,vector<string>> ric_a;
    studente dati;

    menu(scelta);
	while(scelta != 'X'){

	    switch(scelta){

        case '0':

            caricaDati();
            /*for(auto s: studenti){
                ric_a[s.matricola_studente].push_back(s.descrizione_corso);
            }
            */

            for(auto s: studenti){
                ric_c[s.matricola_studente] = s.descrizione_corso;
            }
            for(auto s: studenti){
                ric_c[s.cognome_studente] = s.descrizione_corso;
            }

            stampa();

            break;

        case '1':
                cout << "inserisci la matricola da cercare: ";
                cin >> matricola;
                cout << "Corsi: ";
                /*for(auto s: ric_a[matricola]){
                    cout << s << endl;
                }
                */
                cout << ric_c[matricola] << endl;

            break;

        case '2':
                cout << "inserisci il cognome da cercare: ";
                cin >> cognome;
                cout << "Corsi: ";
                cout << ric_c[cognome] << endl;

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

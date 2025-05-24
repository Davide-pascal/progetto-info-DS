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
    for (auto s : studenti) {
        cout << "Codice Corso: " << s.codice_corso << ", Descrizione Corso: " << s.descrizione_corso << ", Codice Materia: " << s.codice_materia << ", Descrizione Materia: " << s.descrizione_materia << ", ";
        cout << "Matricola: " << s.matricola_studente << ", Nome: " << s.nome_studente << ", Cognome: " << s.cognome_studente << endl;
    }
}

int main(){
    string matricola;
    string descrizione;
    string descrizione_conta;
    string cognome;
    string codice;
    string conta_codice_corso;
    string stringa;
    string descrizione_materia;
    char scelta;
    int cont = 0;
    int i = 0;
    map<string,string> descrizione_corso_per_matricola;
    map<string,string> descrizione_corso_per_cognome;
    map<string,string> stampa_dati_per_descrizione_corso;
    map<string,vector<string>> lista_studenti_per_corso;
    map<string,vector<string>> lista_studenti_per_descrizione_corso;
    map<string,vector<string>> lista_materie_per_codice_corso;
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
                descrizione_corso_per_matricola[s.matricola_studente] = s.descrizione_corso;
            }
            for(auto s: studenti){
                descrizione_corso_per_cognome[s.cognome_studente] = s.descrizione_corso;
            }

            for(studente s: studenti){

                string cognome_studente = s.cognome_studente;
                string codice_corso = s.codice_corso;
                vector<string> lista_studenti_1 = lista_studenti_per_corso[codice_corso];

                bool trovato_1 = false;
                for (string n : lista_studenti_1) {
                    if (n == cognome_studente)
                        trovato_1 = true;
                }
                if(!trovato_1){
                    // NON E' PRESENTE
                    lista_studenti_per_corso[codice_corso].push_back(s.cognome_studente);
                }
            }

            for(studente s: studenti){

                string descrizione_corso = s.descrizione_corso;
                string cognome_studente = s.cognome_studente;
                vector<string> lista_studenti_2 = lista_studenti_per_descrizione_corso[descrizione_corso];

                bool trovato_2 = false;
                for (string n : lista_studenti_2) {
                    if (n == cognome_studente)
                        trovato_2 = true;
                }
                if(!trovato_2){
                    // NON E' PRESENTE
                    //lista_studenti_per_descrizione_corso[descrizione_corso].push_back();
                    cont ++;
                }
            }

            for(studente s: studenti){

                string codice_corso = s.codice_corso;
                string descrizione_materia = s.descrizione_materia;
                vector<string> lista_studenti_3 = lista_materie_per_codice_corso[codice_corso];

                bool trovato_3 = false;
                for (string x : lista_studenti_3) {
                    if (x == descrizione_materia)
                        trovato_3 = true;
                }
                if(!trovato_3){
                    // NON E' PRESENTE
                    //lista_studenti_per_descrizione_corso[descrizione_corso].push_back();
                    i ++;
                }
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
                cout << descrizione_corso_per_matricola[matricola] << endl;

            break;

        case '2':
                cout << "inserisci il cognome da cercare: ";
                cin >> cognome;
                cout << "Corsi: ";
                cout << descrizione_corso_per_cognome[cognome] << endl;

            break;

        case '3':
                cout << "Inserisci il codice del corso: ";
                cin >> codice;
                cout << "Studenti Iscritti: ";
                cout << endl;
                for(auto s: lista_studenti_per_corso[codice]){
                    cout << " - " << s << endl;
                }

            break;


        case '4':{
                cout << "Inserisci la descrizione del corso: ";
                cin.ignore();
                getline(cin, descrizione);

                cout << "===== Dati esami del corso " << descrizione << " =====" << endl;

                bool trovato = false;

                for (auto &s : studenti){
                    if (s.descrizione_corso == descrizione) {
                        trovato = true;
                        cout << "Materia: " << s.codice_materia << " - " << s.descrizione_materia << endl;
                        cout << "Studente: " << s.matricola_studente << " - " << s.nome_studente << " " << s.cognome_studente << endl;
                        cout << "----------------------------------------" << endl;
                    }
                }

                if (!trovato) {
                    cout << "Nessun dato trovato per il codice corso inserito." << endl;
                }

                break;
            }


        case '5':
                cout << "Inserisci descrizione del corso: ";
                cin.ignore();
                getline(cin, descrizione_conta);
                cout << "Studenti Iscritti a questo corso: ";
                cout << endl;
                /*for(auto s: lista_studenti_per_corso[descrizione_conta]){
                }*/
                cout << cont << endl;
            break;

        case '6':
                cout << "Inserisci codice del corso: ";
                cin.ignore();
                getline(cin, conta_codice_corso);
                cout << "Materie presenti nel corso: ";
                cout << endl;
                /*for(auto s: lista_studenti_per_corso[descrizione_conta]){
                }*/
                cout << i << endl;
            break;

        case '7':
                /*cout << "Inserisci una stringa: ";
                cin.ignore();
                getline(cin, stringa);
                if(descrizione_materia.find() == )
                                                                            non va, riguarda funzione 6 e 7*/
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

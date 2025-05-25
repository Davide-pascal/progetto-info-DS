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

// Struct per rappresentare ogni riga del file: dati su corso, materia e studente
struct studente{
    string codice_corso;
    string descrizione_corso;
    string codice_materia;
    string descrizione_materia;
    string matricola_studente;
    string cognome_studente;
    string nome_studente;
};

vector<studente> studenti; // Vettore globale che contiene tutti gli studenti caricati

// Funzione che legge i dati da file CSV e li inserisce nel vettore studenti
void caricaDati(){
    ifstream fin("corsi.csv");
    string s;

    getline(fin, s); // salta la prima riga (intestazione)

    while (!fin.eof()) {
        // Token
        string codice_corso, descrizione_corso, codice_materia, descrizione_materia;
        string matricola_studente, cognome_studente, nome_studente;

        getline(fin, codice_corso, ',');

        if (codice_corso == "") break; // Riga vuota

        getline(fin, descrizione_corso, ',');
        getline(fin, codice_materia, ',');
        getline(fin, descrizione_materia, ',');
        getline(fin, matricola_studente, ',');
        getline(fin, cognome_studente, ',');
        getline(fin, nome_studente);

        // Crea uno studente e lo inserisce nel vettore
        studente nuovo_studente = {codice_corso, descrizione_corso, codice_materia, descrizione_materia, matricola_studente, cognome_studente, nome_studente};
        studenti.push_back(nuovo_studente);
    }

    fin.close();
}

// Funzione di stampa dei dati caricati
void stampa() {
    for (auto s : studenti) {
        cout << "Codice Corso: " << s.codice_corso << ", Descrizione Corso: " << s.descrizione_corso << ", Codice Materia: " << s.codice_materia << ", Descrizione Materia: " << s.descrizione_materia << ", ";
        cout << "Matricola: " << s.matricola_studente << ", Nome: " << s.nome_studente << ", Cognome: " << s.cognome_studente << endl;
    }
}

int main(){
    // Variabili usate in vari casi del menu
    string matricola, descrizione, descrizione_conta, cognome, codice, input, conta_codice_corso, stringa, descrizione_materia;

    // Variabili per inserire i dati del nuovo studente
    string nuovo_codice_corso, nuova_descrizione_corso;
    string nuovo_codice_materia, nuova_descrizione_materia;
    string nuova_matricola, nuovo_cognome, nuovo_nome;

    char scelta;
    int cont = 0;
    int i = 0;
    bool trovata = false;

    // Variabili mappa per cercare in base a matricola, cognome, corso ecc.
    map<string,string> descrizione_corso_per_matricola;
    map<string,string> descrizione_corso_per_cognome;
    map<string,string> stampa_dati_per_descrizione_corso;
    map<string,vector<string>> lista_studenti_per_corso;
    map<string,vector<string>> lista_studenti_per_descrizione_corso;
    map<string,vector<string>> lista_materie_per_codice_corso;

    menu(scelta); // Mostra il menu

	while(scelta != 'X'){

	    switch(scelta){

        case '0':

            caricaDati();

            // Crea mappa da matricola a corso
            for(auto s: studenti){
                descrizione_corso_per_matricola[s.matricola_studente] = s.descrizione_corso;
            }

            // Crea mappa da cognome a corso
            for(auto s: studenti){
                descrizione_corso_per_cognome[s.cognome_studente] = s.descrizione_corso;
            }

            // Costruisce la lista degli studenti per ogni codice corso
            for(studente s: studenti){
                string cognome_studente = s.cognome_studente;
                string codice_corso = s.codice_corso;
                vector<string> lista = lista_studenti_per_corso[codice_corso];

                bool trovato = false;
                for (string n : lista) {
                    if (n == cognome_studente)
                        trovato = true;
                }
                if(!trovato){
                    lista_studenti_per_corso[codice_corso].push_back(cognome_studente);
                }
            }

            // Conta studenti unici per descrizione corso
            for(studente s: studenti){
                string descrizione_corso = s.descrizione_corso;
                string cognome_studente = s.cognome_studente;
                vector<string> lista = lista_studenti_per_descrizione_corso[descrizione_corso];

                bool trovato = false;
                for (string n : lista) {
                    if (n == cognome_studente)
                        trovato = true;
                }
                if(!trovato){
                    cont++; // Incrementa contatore globale
                }
            }

            // Crea lista di materie per codice corso (evita duplicati)
            for(studente s: studenti){
                string codice_corso = s.codice_corso;
                string descrizione_materia = s.descrizione_materia;
                vector<string> &lista = lista_materie_per_codice_corso[codice_corso];

                bool trovato = false;
                for (string x : lista) {
                    if (x == descrizione_materia){
                        trovato = true;
                        break;
                    }
                }
                if(!trovato){
                    lista.push_back(descrizione_materia);
                }
            }

            stampa(); // Stampa tutti i dati caricati

            break;

        case '1': // Cerca corsi di uno studente (matricola)
            cout << "inserisci la matricola da cercare: ";
            cin >> matricola;
            cout << "Corsi: ";
            cout << descrizione_corso_per_matricola[matricola] << endl;
            break;

        case '2': // Cerca corsi di uno studente (cognome)
            cout << "inserisci il cognome da cercare: ";
            cin >> cognome;
            cout << "Corsi: ";
            cout << descrizione_corso_per_cognome[cognome] << endl;
            break;

        case '3': // Elenca studenti iscritti a un corso
            cout << "Inserisci il codice del corso: ";
            cin >> codice;
            cout << "Studenti Iscritti:\n";
            for(auto s: lista_studenti_per_corso[codice]){
                cout << " - " << s << endl;
            }
            break;

        case '4': // Stampa dati esami di un corso
            cout << "Inserisci la descrizione del corso: ";
            cin.ignore();
            getline(cin, descrizione);

            cout << "===== Dati esami del corso " << descrizione << " =====" << endl;
            trovata = false;

            for (auto &s : studenti){
                if (s.descrizione_corso == descrizione) {
                    trovata = true;
                    cout << "Materia: " << s.codice_materia << " - " << s.descrizione_materia << endl;
                    cout << "Studente: " << s.matricola_studente << " - " << s.nome_studente << " " << s.cognome_studente << endl;
                    cout << "----------------------------------------" << endl;
                }
            }

            if (!trovata) {
                cout << "Nessun dato trovato per il codice corso inserito." << endl;
            }

            break;

        case '5': // Numero di studenti per corso (usando cont)
            cout << "Inserisci descrizione del corso: ";
            cin.ignore();
            getline(cin, descrizione_conta);
            cout << "Studenti Iscritti a questo corso: ";
            cout << cont << endl;
            break;

        case '6': // Numero di materie per corso
            cout << "Inserisci codice del corso: ";
            cin.ignore();
            getline(cin, conta_codice_corso);
            cout << "Materie presenti nel corso: ";
            cout << lista_materie_per_codice_corso[conta_codice_corso].size() << endl;
            break;

        case '7': // Cerca materie per descrizione (ricerca testuale)
            cout << "Inserisci una stringa da cercare nella descrizione delle materie: ";
            cin.ignore();
            getline(cin, input);

            // Converti input in minuscolo
            for (int i = 0; i < input.length(); i++) {
                if (input[i] >= 'A' && input[i] <= 'Z') {
                    input[i] += 'a' - 'A';
                }
            }

            trovata = false;

            for (auto s : studenti) {
                string descr_materia = s.descrizione_materia;

                // Converti descrizione materia in minuscolo
                for (int i = 0; i < descr_materia.length(); i++) {
                    if (descr_materia[i] >= 'A' && descr_materia[i] <= 'Z') {
                        descr_materia[i] += 'a' - 'A';
                    }
                }

                // Se l'input è contenuto nella descrizione
                int posizione = descr_materia.find(input);

                if (posizione >= 0) {
                    trovata = true;
                    cout << "Materia: " << s.codice_materia << " - " << s.descrizione_materia << endl;
                    cout << "Corso: " << s.codice_corso << " - " << s.descrizione_corso << endl;
                    cout << "Studente: " << s.nome_studente << " " << s.cognome_studente << " (matricola " << s.matricola_studente << ")\n";
                    cout << "----------------------------------------" << endl;
                }
            }

            if (!trovata) {
                cout << "Nessuna materia trovata con quella descrizione." << endl;
            }

            break;

        case '8':{

            // Chiedo all'utente di inserire i dati
            cout << "Inserisci codice corso: ";
            cin >> nuovo_codice_corso;
            cout << "Inserisci descrizione corso: ";
            cin.ignore(); // Pulisco il buffer per getline
            getline(cin, nuova_descrizione_corso);

            cout << "Inserisci codice materia: ";
            cin >> nuovo_codice_materia;
            cout << "Inserisci descrizione materia: ";
            cin.ignore();
            getline(cin, nuova_descrizione_materia);

            cout << "Inserisci matricola studente: ";
            cin >> nuova_matricola;
            cout << "Inserisci cognome studente: ";
            cin >> nuovo_cognome;
            cout << "Inserisci nome studente: ";
            cin >> nuovo_nome;

            // Creo un nuovo oggetto studente con i dati inseriti
                studente nuovo_studente = { nuovo_codice_corso, nuova_descrizione_corso, nuovo_codice_materia, nuova_descrizione_materia,
                nuova_matricola, nuovo_cognome, nuovo_nome
                };

            // Inserisco il nuovo studente nel vettore studenti
            studenti.push_back(nuovo_studente);

            // Aggiorno le mappe per ricerca rapida
            descrizione_corso_per_matricola[nuova_matricola] = nuova_descrizione_corso;
            descrizione_corso_per_cognome[nuovo_cognome] = nuova_descrizione_corso;

            // Aggiungo il cognome alla lista degli iscritti per codice corso (se non presente)
            {
                vector<string> &lista = lista_studenti_per_corso[nuovo_codice_corso];
                bool trovato = false;
                for (auto &cognome : lista) {
                    if (cognome == nuovo_cognome) {
                        trovato = true;
                        break;
                    }
                }
                if (!trovato) {
                    lista.push_back(nuovo_cognome);
                }
            }

            // Aggiungo il cognome alla lista per descrizione corso (se non presente)
            {
                vector<string> &lista = lista_studenti_per_descrizione_corso[nuova_descrizione_corso];
                bool trovato = false;
                for (auto &cognome : lista) {
                    if (cognome == nuovo_cognome) {
                        trovato = true;
                        break;
                    }
                }
                if (!trovato) {
                    lista.push_back(nuovo_cognome);
                }
            }

            // Aggiungo la materia al corso se non presente
            {
                vector<string> &materie = lista_materie_per_codice_corso[nuovo_codice_corso];
                bool trovato = false;
                for (auto &materia : materie) {
                    if (materia == nuova_descrizione_materia) {
                        trovato = true;
                        break;
                    }
                }
                if (!trovato) {
                    materie.push_back(nuova_descrizione_materia);
                }
            }

            cout << "Nuovo studente inserito con successo.\n";

        }

            break;

        case '9': // Salva i dati su file
            ofstream fout("corsi.csv");

            // Scrive l'intestazione
            fout << "codice_corso,descrizione_corso,codice_materia,descrizione_materia,matricola_studente,cognome_studente,nome_studente\n";

            // Scrive tutti gli studenti
            for (studente s : studenti) {
                fout << s.codice_corso << ','
                     << s.descrizione_corso << ','
                     << s.codice_materia << ','
                     << s.descrizione_materia << ','
                     << s.matricola_studente << ','
                     << s.cognome_studente << ','
                     << s.nome_studente << '\n';
            }

            fout.close();
            cout << "Dati salvati correttamente.\n";

            break;
	    }

        system("pause");
        system("cls"); // Pulisce lo schermo tra le operazioni

        menu(scelta); // Ripropone il menu
  	}

    cout << "fine sessione di lavoro" << endl;
    return 0;
}

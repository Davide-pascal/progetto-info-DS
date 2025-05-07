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

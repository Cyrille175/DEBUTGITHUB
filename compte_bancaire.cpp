#include 'comptebancaire.h'

//Verifier le mot de passe
std::string Compte_bancaire::check_password(std::string mot_de_passe) {
    return mot_de_passe == _mot_de_passe; 
}


//Constructeur de Personne
Personne::Personne(char nom, char prenom, int age,char adresse): _nom(nom), _prenom(prenom), _age(age), _adresse(adresse) {
};



//Constructeur de Compte_bancaire
Compte_bancaire::Compte_bancaire (int rib, Personne client, char mot_de_passe): _rib=rib, _client=client, _mot_de_passe=mot_de_passe, _solde=5 {
};


//Recupere les infos de mon compte 
std::string Compte_bancaire::get_info_compte (char mot_de_passe) {
if (check_password(char mot_de_passe)==true){
std::string message="Informations du compte : RIB: " + std::to_string(rib) + 
                              ", Solde: " + std::to_string(_solde) + 
                              ", Client: " + _client.get_info_personne();   
return message;
}
else return "Votre mot de passe est erronnée";
}



//Obtenir les inforamtions sur la personne
std::string Personne::get_info_personne() {
    std::string info_personne="Nom: "+ std::to_string(_nom)+
                              "Prenom: "+ std::to_string(_prenom)+
                              "Age: "+std::to_string(_age)+
                              "Adresse: "+std::to_string(_adresse);
return info_personne;
}


//Verifie si le solde est superieur a ce que l'on veut enlever 
bool Compte_bancaire::check_solde(int somme_enlevee) {
return _solde >= somme_enlevee ;
}

//ajouter l'argent dans le solde 
void Compte_bancaire::ajouter_solde(int somme) {
_solde=_solde+somme;    
}

//dimunuer l'argent dans le solde 
void Compte_bancaire::dimunuer_solde(int somme) {
_solde=_solde-somme;    
}


//Fonction helper qui fait le transfert d'argent du compte a vers le compte b  
std::string transfert(Compte_bancaire &a, std::string mot_de_passe, Compte_bancaire &b, int somme) {
    if (a.check_password(mot_de_passe)==true) {
       if  (a.check_solde(somme)==true) {
       a.dimunuer_solde(somme);
       b.ajouter_solde(somme);
       return "Votre transfert s'est deroulé avec succes";
       }
       else 
       return "Le solde de votre compte est insuffisant";

    }
    else return "Votre mot de passe est erronnée";
}



//faire une operation de depot dans son compte
std::string crediter_compte(Compte_bancaire &a,int somme) {
    a.ajouter_solde(somme);
    return "Votre depot a été effectué avec succes"
}



//retirer de l'argent dans son compte 
std::string retirer_compte(Compte_bancaire &a,std::string mot_de_passe,int somme) {
if (check_password(mot_de_passe)==true) {
a.dimunuer_solde(somme);
return "Votre retrait a été bel et bien effectué";
}
else return "Votre mot de passe est erronnée";
}





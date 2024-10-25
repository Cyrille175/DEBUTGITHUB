#include <iostream>



class Personne {
    private:
    char _nom;
    char _prenom;
    int _age;
    char _adresse;
    public:
    
    Personne(char nom, char prenom, int age,char adresse);
    
    std::string get_info_personne() const;
}

class Compte_bancaire {
    private:
    int _solde;
    Personne _client;
    std::string _mot_de_passe;
    int _rib;
    
    public:
    
    Compte_bancaire(int rib, Personne client, char mot_de_passe) const;
    
    bool check_password (std::string mot_de_passe) const;
    
    bool check_solde(int somme_enlevee) const;
    
    std::string get_info_compte (char mot_de_passe) const;

    void ajouter_solde(int somme);

    void dimunuer_solde(int somme);

    

}
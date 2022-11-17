#ifndef EVENT_H
#define EVENT_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>
class Event
{
    QString NOM_EV,TYPE_EV;
    QString DATE_EV;
    int CIN_EV;
public:
    // Constructeurs
    Event(){}
    Event(int,QString,QString,QString);
    // Getters
    QString getnom_ev(){return NOM_EV;}
    QString gettype_ev(){return TYPE_EV;}
   // QString getdate_ev(){return DATE_EV;}
    int getcin_ev(){return CIN_EV;}
    // setters
    void Setnom_ev(QString n){NOM_EV=n;}
    void Settype_ev(QString t){TYPE_EV=t;}
    void setdate_ev(QString d){DATE_EV=d;}
    void setcin_ev(int CIN_EV){this->CIN_EV=CIN_EV;}
    //Functions
    bool  ajouter_ev();
    QSqlQueryModel * afficher_ev();
    bool supprimer_ev(int);



};

#endif // EVENT_H

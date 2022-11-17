#ifndef LOCAL_H
#define LOCAL_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDate>
class Local
{
     QString rech;
    QString NOM_LO,TYPE_LO;
    int IDENTIFIANT_LO;
public:
    QSqlQueryModel* rechercher_local(QString rech);
    Local(){}
    Local(int, QString,QString);
    QString getnom_lo(){return NOM_LO;}
    QString gettype_lo(){return TYPE_LO;}

    int getidentifiant_lo(){return IDENTIFIANT_LO;}

    void Setnom_lo(QString NOM_LO){this->NOM_LO=NOM_LO;}
    void Settype_lo(QString t){TYPE_LO=t;}
    void setidentifiant_lo(int IDENTIFIANT_LO){this->IDENTIFIANT_LO=IDENTIFIANT_LO;}

    bool  ajouter_lo();
    QSqlQueryModel * afficher_lo();
    bool supprimer_lo(int);
     //QSqlQueryModel* rechercher_espace(QString rech);
    QSqlQueryModel * afficher_local_tri_nom();
    QSqlQueryModel * afficher_local_tri_id();
    QSqlQueryModel * afficher_local_chercher(QString rech);

   QString  combo;


};

#endif // LOCAL_H

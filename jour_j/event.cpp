#include "event.h"

Event::Event(int CIN_EV,QString NOM_EV,QString TYPE_EV,QString DATE_EV)
{
this->CIN_EV=CIN_EV;
this->NOM_EV=NOM_EV;
this->TYPE_EV=TYPE_EV;
this->DATE_EV=DATE_EV;
}

bool Event::ajouter_ev()
{
    QSqlQuery query;
    QString res = QString::number(CIN_EV);
    query.prepare("insert into EVENT (CIN_EV,NOM_EV,TYPE_EV,DATE_EV) values (:CIN_EV,:NOM_EV,:TYPE_EV,:DATE_EV)");
    //Creation des variable liees
    query.bindValue(":CIN_EV",res);
    query.bindValue(":NOM_EV",NOM_EV);
    query.bindValue(":TYPE_EV",TYPE_EV);
    query.bindValue(":DATE_EV",DATE_EV);

    return query.exec();

}


bool Event::supprimer_ev(int CIN_EV)
{
    QSqlQuery query;
    QString res=QString::number(CIN_EV);

    query.prepare("Delete from etudiant where CIN= :CIN_EV");
    query.bindValue(":CIN_EV",res);

    return query.exec();
}



QSqlQueryModel * Event::afficher_ev()
{
  QSqlQueryModel * model=new QSqlQueryModel();

  model->setQuery("select * from etudiant");
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE"));

     return model;
}

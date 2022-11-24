#include "local.h"

Local::Local(int IDENTIFIANT_LO,QString TYPE_LO,QString NOM_LO,QString datedispo)
{
    this->IDENTIFIANT_LO=IDENTIFIANT_LO;
    this->TYPE_LO=TYPE_LO;
    this->NOM_LO=NOM_LO;
    this->datedispo=datedispo;
}
bool Local::ajouter_lo()
{
    QSqlQuery query;
    QString iden = QString::number(IDENTIFIANT_LO);
    query.prepare("insert into LOCAL (IDENTIFIANT_LO,TYPE_LO,NOM_LO,datedispo) values (:IDENTIFIANT_LO,:TYPE_LO,:NOM_LO,:datedispo)");
    //Creation des variable liees
    query.bindValue(":IDENTIFIANT_LO",iden);
    query.bindValue(":NOM_LO",NOM_LO);
    query.bindValue(":TYPE_LO",TYPE_LO);
     query.bindValue(":datedispo",datedispo);

    return query.exec();

}


bool Local::supprimer_lo(int IDENTIFIANT_LO)
{
    QSqlQuery query;
    QString iden=QString::number(IDENTIFIANT_LO);

    query.prepare("Delete from LOCAL where IDENTIFIANT_LO= :IDENTIFIANT_LO");
    query.bindValue(":IDENTIFIANT_LO",iden);

    return query.exec();
}



QSqlQueryModel * Local::afficher_lo()
{
  QSqlQueryModel * model=new QSqlQueryModel();

  model->setQuery("select * from LOCAL");
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDENTIFIANT_LO"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_LO"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM_LO"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Datedispo"));

  return model;
}
// tri par budget :

 QSqlQueryModel * Local::afficher_local_tri_nom()
{
     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from LOCAL order by NOM_LO desc ");


     model->setHeaderData(0, Qt::Horizontal,QObject::tr("IDENTIFIANT_LO"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_LO"));
     model->setHeaderData(2, Qt::Horizontal,QObject::tr("NOM_LO"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Datedispo"));


 return model;
}

 // tri par societe :

  QSqlQueryModel * Local::afficher_local_tri_id()
 {
      QSqlQueryModel * model=new QSqlQueryModel();

      model->setQuery("select * from LOCAL order by IDENTIFIANT_LO ");


      model->setHeaderData(0, Qt::Horizontal,QObject::tr("IDENTIFIANT_LO"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_LO"));
      model->setHeaderData(2, Qt::Horizontal,QObject::tr("NOM_LO"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("Datedispo"));

  return model;
 }

  QSqlQueryModel * Local::afficher_local_Calendrier(QString rech)
 {
      QSqlQueryModel * model=new QSqlQueryModel();

      model->setQuery("select * from LOCAL where datedispo='"+rech+"'");


      model->setHeaderData(0, Qt::Horizontal,QObject::tr("IDENTIFIANT_LO"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_LO"));
      model->setHeaderData(2, Qt::Horizontal,QObject::tr("NOM_LO"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("Datedispo"));

  return model;
 }

QSqlQueryModel* Local::afficher_local_chercher(QString rech)
{
       QString sQuery="SELECT * FROM LOCAL WHERE IDENTIFIANT_LO LIKE'%"+rech+"%' or TYPE_LO LIKE'%"+rech+"%' or NOM_LO LIKE'%"+rech+"%'";

       QSqlQueryModel*model=new QSqlQueryModel();
        QSqlQuery qry;
        qry.prepare(sQuery);
        qry.exec();
        model->setQuery(qry);
        return model;
}


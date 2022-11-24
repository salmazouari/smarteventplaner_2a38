#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "event.h"
#include "QMessageBox"
#include "QApplication"
#include<QDateEdit>
#include "local.h"
#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMainWindow>
#include <QVariant>
#include <QQuickItem>
#include <QQuickWidget>
#include <QConicalGradient>
#include "connection.h"
#include<QPrinter>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
      Connection c;
     c.createconnection();
    //affichage contenu base
   //show_tables();

    //for email tab
    connect(ui->bouttonsend, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

    //maps
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                       QCoreApplication::organizationName(), QCoreApplication::applicationName());

    ui->webbrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/ESPRIT/@36.9016729,10.1713215,15z");


}
//mailing
void  MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("zouari.salma@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("zouari.salma@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("zouari.salma@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}
/*

{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher_ev());
    ui->tableView_2->setModel(local.afficher_lo());

}*/

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_close_clicked()
{

}

void MainWindow::on_pushButton_gestion_event_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_HISTORIQUES_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_RECH_TRI_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_Calendrier_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_STATISTIQUES_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_retour_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_retour_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_retour_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_retour_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_retour_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_retour_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//Boutons pour acceder aux operations ********************

void MainWindow::on_pushButton_ajouter_ev_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget_2->setCurrentIndex(0);
}


void MainWindow::on_pushButton_Eliminer_ev_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
     ui->stackedWidget_2->setCurrentIndex(2);
}


void MainWindow::on_pushButton_liste_ev_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
     ui->stackedWidget_2->setCurrentIndex(1);
}


void MainWindow::on_pushButton_ajouter_vrai_clicked()
{
   // Recuperer les informations saisie dans les 4 champs
   int CIN_EV=ui->lineEdit_CIN_EV->text().toInt();
   QString NOM_EV=ui->lineEdit_NOM_EV->text();
   QString TYPE_EV=ui->lineEdit_TYPE_EV->text();
   QString DATE_EV=ui->dateEdit_DATE_EV->text();
Event e(CIN_EV,NOM_EV,TYPE_EV,DATE_EV);
bool test=e.ajouter_ev();

if(test)
{
    //Refresh
    ui->tableView->setModel(Etmp.afficher_ev());
    QMessageBox::information(nullptr,QObject::tr("OK"),
            QObject::tr("Ajout effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);
}
    else
{
    QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
            QObject::tr("Ajout non effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);
}

}


void MainWindow::on_pushButton_supprimer_vrai_clicked()
{

    int CIN_EV=ui->lineEdit_CIN_EV->text().toInt();
    bool test=Etmp.supprimer_ev(CIN_EV);

    if(test)
    {
        //Refresh
        ui->tableView->setModel(Etmp.afficher_ev());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("suppression effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                QObject::tr("suppression non effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}

}
/////Local

void MainWindow::on_pushButton_HISTORIQUES_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_ajouter_ev_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_Eliminer_ev_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void MainWindow::on_pushButton_liste_ev_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_pushButton_ajouter_vrai_2_clicked()
{
    // Recuperer les informations saisie dans les 4 champs
    int IDENTIFIANT_LO=ui->lineEdit_ID_LO->text().toInt();
    QString TYPE_LO=ui->lineEdit_TYPE_LO->text();
    QString NOM_LO=ui->lineEdit_NOM_LO->text();
    QString dateDispo=ui->dateEdit->text();
 Local l(IDENTIFIANT_LO,TYPE_LO,NOM_LO,dateDispo);
 bool test=l.ajouter_lo();

 if(test)
 {
     //Refresh
     ui->tab_local->setModel(local.afficher_lo());
     QMessageBox::information(nullptr,QObject::tr("OK"),
             QObject::tr("Ajout LOCAL effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);
 }
     else
 {
     QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
             QObject::tr("Ajout LOCAL non effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);
 }

}

void MainWindow::on_pushButton_supprimer_vrai_2_clicked()
{
    int IDENTIFIANT_LO=ui->lineEdit_4->text().toInt();
    bool test=local.supprimer_lo(IDENTIFIANT_LO);

    if(test)
    {
        //Refresh
        ui->tab_local->setModel(local.afficher_lo());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("suppression Local effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                QObject::tr("suppression Local non effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_Calendrier_2_clicked()
{


     ui->stackedWidget->setCurrentIndex(14);

}



void MainWindow::on_webbrowser_BeforeNavigate(const QString &URL, int Flags, const QString &TargetFrameName, QVariant &PostData, const QString &Headers, bool &Cancel)
{

}


void MainWindow::on_bouton_tri_2_clicked()
{


   if(ui->Tri_B->isChecked())
{



    bool test=local.afficher_local_tri_nom();

   if(test)
   {
       //refresh

       ui->tableView_2->setModel(local.afficher_local_tri_nom());

   QMessageBox::information(nullptr,QObject::tr("Valider"),
                            QObject::tr("Tri b successful.\n"
                                        "Click Cancel to exit."),QMessageBox::Cancel);
   }
   else
      { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                                QObject::tr("Tri b failed.\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);}
 }

   else if(ui->tri_S->isChecked())
{



    bool test=local.afficher_local_tri_id();

   if(test)
   {
       //refresh

       ui->tableView_2->setModel(local.afficher_local_tri_id());

   QMessageBox::information(nullptr,QObject::tr("Valider"),
                            QObject::tr("Tri s successful.\n"
                                        "Click Cancel to exit."),QMessageBox::Cancel);
   }
   else
      { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                                QObject::tr("Tri s failed.\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);}
 }
}



/*void MainWindow::on_bouton_chercher_clicked()
{
 QString rech =ui->le_chercher->text();



 bool test=local.afficher_local_chercher(rech);

if(test)
{

ui->tableView_2->setModel(local.afficher_local_chercher(rech));
QMessageBox::information(nullptr,QObject::tr("Valider"),
                         QObject::tr("chercher s successful.\n"
                                     "Click Cancel to exit."),QMessageBox::Cancel);
}
else
   { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                             QObject::tr("chercher s failed.\n"
                                         "Click Cancel to exit."),QMessageBox::Cancel);}*/

 /*else
     if(ui->P_chercher->isChecked())
    {
     bool test=p.afficher_Partenariats_chercher(rech);

    if(test)
    {

    ui->tab_local->setModel(p.afficher_Partenariats_chercher(rech));
    QMessageBox::information(nullptr,QObject::tr("Valider"),
                             QObject::tr("chercher s successful.\n"
                                         "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
       { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                                 QObject::tr("chercher s failed.\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);}
    }*/
/* else
         if(ui->C_chercher->isChecked())
        {
         bool test=p.afficher_Partenariats_chercher(rech);

        if(test)
        {

        ui->tab_local->setModel(p.afficher_Partenariats_chercher(rech));
        QMessageBox::information(nullptr,QObject::tr("Valider"),
                                 QObject::tr("chercher s successful.\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);
        }
        else
           { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                                     QObject::tr("chercher s failed.\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel);}
        }*/
/* else
             if(ui->ID_chercher->isChecked())
            {
             bool test=local.afficher_local_chercher(rech);

            if(test)
            {

            ui->tableView_2->setModel(local.afficher_local_chercher(rech));
            QMessageBox::information(nullptr,QObject::tr("Valider"),
                                     QObject::tr("chercher s successful.\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel);
            }
            else
               { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                                         QObject::tr("chercher s failed.\n"
                                                     "Click Cancel to exit."),QMessageBox::Cancel);}
            }*/
 /*else
                 if(ui->B_chercher->isChecked())
                {
                 bool test=p.afficher_Partenariats_chercher(rech);

                if(test)
                {

                ui->tab_local->setModel(p.afficher_Partenariats_chercher(rech));
                QMessageBox::information(nullptr,QObject::tr("Valider"),
                                         QObject::tr("chercher s successful.\n"
                                                     "Click Cancel to exit."),QMessageBox::Cancel);
                }
                else
                   { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                                             QObject::tr("chercher s failed.\n"
                                                         "Click Cancel to exit."),QMessageBox::Cancel);}
                }*/
//}


/*void MainWindow::on_pushButton_PDF_clicked()
{

    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tableView_2->model()->rowCount();
                const int columnCount =ui->tableView_2->model()->columnCount();


                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("programme")
                        <<  "</head>\n"
                        "<body bgcolor=#FFFFFF link=#5000A0>\n"
                            "<h1>Liste des Partenariats</h1>"

                            "<table border=1 cellspacing=0 cellpadding=2>\n";

                // headers
                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tableView_2->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tableView_2->isColumnHidden(column)) {
                                   QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table>\n"
                           "</body>\n"
                           "</html>\n";



        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);


        //QTextDocument document;
        //document.setHtml(html);
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("myfilepdf.pdf");
        document->print(&printer);
}*/

void MainWindow::on_pdf_5_clicked()
{
    {

            QString strStream;
                        QTextStream out(&strStream);
                        const int rowCount = ui->tableView_2->model()->rowCount();
                        const int columnCount =ui->tableView_2->model()->columnCount();


                        out <<  "<html>\n"
                                "<head>\n"
                                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                <<  QString("<title>%1</title>\n").arg("programme")
                                <<  "</head>\n"
                                "<body bgcolor=#FFFFFF link=#5000A0>\n"
                                    "<h1>Liste des Programmes</h1>"

                                    "<table border=1 cellspacing=0 cellpadding=2>\n";

                        // headers
                            out << "<thead><tr bgcolor=#f0f0f0>";
                            for (int column = 0; column < columnCount; column++)
                                if (!ui->tableView_2->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";
                            // data table
                               for (int row = 0; row < rowCount; row++) {
                                   out << "<tr>";
                                   for (int column = 0; column < columnCount; column++) {
                                       if (!ui->tableView_2->isColumnHidden(column)) {
                                           QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                                           out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                       }
                                   }
                                   out << "</tr>\n";
                               }
                               out <<  "</table>\n"
                                   "</body>\n"
                                   "</html>\n";



                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);


                //QTextDocument document;
                //document.setHtml(html);
                QPrinter printer(QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setOutputFileName("program.pdf");
                document->print(&printer);
    }
}

void MainWindow::on_recherche_5_clicked()

    {
     QString rech =ui->le_chercher->text();



     bool test=local.afficher_local_chercher(rech);

    if(test)
    {

    ui->tableView_2->setModel(local.afficher_local_chercher(rech));
    QMessageBox::information(nullptr,QObject::tr("Valider"),
                             QObject::tr("chercher s successful.\n"
                                         "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
       { QMessageBox::critical(nullptr,QObject::tr("Non Valider"),
                                 QObject::tr("chercher s failed.\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);}
}



void MainWindow::on_pushButton_RECH_TRI_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_STATISTIQUES_2_clicked()
{
      ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->tableViewCal->setModel(local.afficher_local_Calendrier(ui->calendarWidget_17->selectedDate().toString("dd/MM/yyyy")));
    qDebug()<<ui->calendarWidget_17->selectedDate().toString("dd/MM/yyyy");
}

void MainWindow::on_pushButton_HISTORIQUES_2_clicked()
{
        ui->stackedWidget->setCurrentIndex(8);
}

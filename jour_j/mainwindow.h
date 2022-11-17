#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"event.h"
#include"local.h"
#include <QFile>
#include <QFileDialog>
#include "smtp.h"
#include <QSortFilterProxyModel>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
        Local tmp;
        QSortFilterProxyModel *proxy;
       void show_tables();
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void sendMail();
    void mailSent(QString);
    void browse();
    void on_close_clicked();
     void on_bouton_tri_2_clicked();
     void on_bouton_chercher_clicked();
     //void on_pushButton_PDF_clicked();

    void on_pushButton_gestion_event_clicked();

    void on_pushButton_HISTORIQUES_clicked();

    void on_pushButton_RECH_TRI_clicked();

    void on_pushButton_STATISTIQUES_clicked();

    void on_pushButton_Calendrier_clicked();

    void on_pushButton_retour_clicked();

    void on_pushButton_retour_1_clicked();

    void on_pushButton_retour_2_clicked();

    void on_pushButton_retour_3_clicked();

    void on_pushButton_retour_4_clicked();

    void on_pushButton_retour_5_clicked();

//Boutons pour acceder aux operations ********************
    void on_recherche_textChanged(const QString &arg1);
    void on_pushButton_ajouter_ev_clicked();

    void on_pushButton_Eliminer_ev_clicked();

    void on_pushButton_liste_ev_clicked();



    void on_pushButton_ajouter_vrai_clicked();

    void on_pushButton_supprimer_vrai_clicked();

    void on_pushButton_HISTORIQUES_10_clicked();

    void on_pushButton_ajouter_ev_2_clicked();

    void on_pushButton_Eliminer_ev_2_clicked();

    void on_pushButton_liste_ev_2_clicked();

    void on_pushButton_ajouter_vrai_2_clicked();


    void on_pushButton_supprimer_vrai_2_clicked();

    void on_pushButton_Calendrier_2_clicked();

    void on_webbrowser_BeforeNavigate(const QString &URL, int Flags, const QString &TargetFrameName, QVariant &PostData, const QString &Headers, bool &Cancel);

    void on_pdf_5_clicked();

    void on_recherche_5_clicked();

    void on_pushButton_RECH_TRI_2_clicked();

    void on_pushButton_STATISTIQUES_2_clicked();

private:
    QStringList files;
    Ui::MainWindow *ui;
    Event Etmp;
    Local local;
 signals:
   void setCenter(QVariant, QVariant);
   void addMarker(QVariant, QVariant);
};
#endif // MAINWINDOW_H

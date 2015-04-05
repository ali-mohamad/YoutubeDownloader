#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>

#include <QMessageBox>
#include <QClipboard>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QSize>
#include <QDebug>
#include <QList>
#include <QStringList>
#include <QPixmap>

#include "helper.h"
#include "youtubevideoquality.h"
#include "youtubedownloader.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnExit_clicked();
    void on_btnPaste_clicked();
    void on_btnGetVideo_clicked();
    void slot_netwManagerFinished(QNetworkReply *reply);
    void on_txtUrl_textChanged(const QString &arg1);

    void on_btnCopy_clicked();

    void on_btnDownload_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;

};

#endif // MAINWINDOW_H

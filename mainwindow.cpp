

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "downloader.h"
#include "ui_downloader.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->hide();
    this->setWindowIcon(QIcon(":/icon/youtubeIcon.ico"));
    ui->btnGetVideo->setEnabled(false);
    ui->btnCopy->setEnabled(false);
    ui->btnDownload->setEnabled(false);
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_netwManagerFinished(QNetworkReply*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnExit_clicked()
{
    exit(0);
}

void MainWindow::on_btnPaste_clicked()
{
    const QClipboard *clipboard = QApplication::clipboard();
    QString textInClipboard = clipboard->text();
    ui->txtUrl->setText(textInClipboard);
    ui->btnGetVideo->setEnabled(true);
}

void MainWindow::on_btnGetVideo_clicked()
{
    ui->comboBox->clear();
    QString url = ui->txtUrl->text();
    if(!Helper::isValidUrl(url) || !url.toLower().contains("www.youtube.com/watch?"))
        QMessageBox(QMessageBox::Warning,
                    "Invalid URL",
                    "You enter invalid YouTube URL, Please correct it.\r\n\nNote: URL should start with:\r\nhttp://www.youtube.com/watch?",
                    QMessageBox::Ok).exec();
    else {
        ui->btnGetVideo->setEnabled(false);
        ui->progressBar->setVisible(true);

        ui->videoImage->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);


        QSize sPic(ui->videoImage->width(),ui->videoImage->height());
        QPixmap pixmap(sPic);
        pixmap.load(":/logoWait.png");
        ui->videoImage->setScaledContents(false);
        ui->videoImage->setPixmap(pixmap);

        QString videoID = Helper::GetVideoIDFromUrl(url);
        QUrl url("http://i3.ytimg.com/vi/" + videoID + "/default.jpg");
        QNetworkRequest request(url);
        manager->get(request);

        QList<YouTubeVideoQuality> list = YoutubeDownloader::GetYouTubeVideoUrls(ui->txtUrl->text());
        ui->lblTitle->setText(list.first().getVideoTitle());
        foreach(YouTubeVideoQuality q , list) {
            ui->comboBox->addItem(q.toString(),QVariant(q.getDownloadUrl()));
        }

        ui->progressBar->hide();
        ui->btnCopy->setEnabled(true);
        ui->btnDownload->setEnabled(true);
    }

}


void MainWindow::on_txtUrl_textChanged(const QString &arg1)
{
    if(arg1.length() > 0)
        ui->btnGetVideo->setEnabled(true); else {
        ui->btnGetVideo->setEnabled(false);
    }
}

void MainWindow::slot_netwManagerFinished(QNetworkReply *reply){
    QByteArray jpegData = reply->readAll();
    QSize sPic(ui->videoImage->width(),ui->videoImage->height());
    QPixmap pixmap(sPic);
    pixmap.loadFromData(jpegData);
    ui->videoImage->setScaledContents(true);
    ui->videoImage->setPixmap(pixmap);
    //ui->progressBar->hide();
}

void MainWindow::on_btnCopy_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText( ui->comboBox->currentData().toString() );
}

void MainWindow::on_btnDownload_clicked()
{
    Downloader *downForm = new Downloader();
    downForm->show();
}

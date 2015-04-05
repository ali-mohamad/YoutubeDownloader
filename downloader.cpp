#include "downloader.h"
#include "ui_downloader.h"

Downloader::Downloader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Downloader)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());


}

Downloader::~Downloader()
{
    delete ui;
}

#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QDialog>

namespace Ui {
class Downloader;
}

class Downloader : public QDialog
{
    Q_OBJECT

public:
    explicit Downloader(QWidget *parent = 0);
    ~Downloader();

private:
    Ui::Downloader *ui;
};

#endif // DOWNLOADER_H

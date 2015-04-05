#ifndef HELPER_H
#define HELPER_H

#include <QString>
#include <QRegularExpression>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>

#include "youtubevideoquality.h"

class Helper
{
public:
   static bool isValidUrl(QString link);
   static QString GetVideoIDFromUrl(QString url);
   static QString DownloadWebPage(QString url);
   static QString GetTxtBtw(QString input,QString start,QString end,int startIndex);
   static QString GetTxtBtw(QString input,QString start,QString end,int startIndex,bool UseLastIndex);
   static bool getSize(YouTubeVideoQuality url);
private:
   static void quit();
};

#endif // HELPER_H

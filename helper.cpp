#include "helper.h"


bool Helper::isValidUrl(QString link)
{
    QRegularExpression regex("^(http|ftp|https):\\/\\/[\\w\\-_]+(\\.[\\w\\-_]+)+([\\w\\-\\.,@?^=%&amp;:/~\\+#]*[\\w\\-\\@?^=%&amp;/~\\+#])?$",QRegularExpression::CaseInsensitiveOption);
    if(regex.match(link).hasMatch())
        return true;
    else return false;
}

QString Helper::GetVideoIDFromUrl(QString url){
    url = url.mid(url.indexOf("?") + 1);
    QStringList parsed = url.split('&');

    QString videoID("");
    foreach(QString s ,parsed){
        if(s.startsWith("v="))
            videoID = s.mid(s.indexOf("v=") + 2);
    }

    return videoID;
}

QString Helper::DownloadWebPage(QString url) {


    QNetworkAccessManager manager;
    QNetworkRequest request(url);
    QNetworkReply *reply(manager.get(request));
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();


    QByteArray html(reply->readAll());
    //qDebug() << html.length();
    //qDebug() << html.mid(10,10);

    return html;
}

void quit() {
   // qDebug() << "finished";
}

QString Helper::GetTxtBtw(QString input, QString start, QString end, int startIndex){
    return Helper::GetTxtBtw(input,start,end,startIndex,true);
}

QString Helper::GetTxtBtw(QString input, QString start, QString end, int startIndex,bool UseLastIndex){
  if(UseLastIndex) {

    int index1 = input.indexOf(start,startIndex);
    if (index1 == -1 ) return "";
    index1 += start.length();
    int index2 = input.indexOf(end,index1);
    if (index2 == -1 ) return input.mid(index1);
    return input.mid(index1,index2 - index1);
  } else {
      return "";
  }
}

bool Helper::getSize(YouTubeVideoQuality url)
{
    QNetworkAccessManager manager;
    QUrl _url(url.getDownloadUrl());
    QNetworkRequest request(_url);
    QNetworkReply *reply(manager.get(request));
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(readyRead()), &loop, SLOT(quit()));
    QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),&loop,SLOT(quit()));
    loop.exec();
    QList<QByteArray> headerList = reply->rawHeaderList();
    int size = -1;
    foreach(QByteArray head, headerList) {
       // qDebug() << head << ":" << reply->rawHeader(head);
        if(head == "Content-Length")
            size = reply->rawHeader(head).toInt();
    }
    if (size > 0)
    {
        return true;
        url.setSize(size);
    }
    else return false;
}


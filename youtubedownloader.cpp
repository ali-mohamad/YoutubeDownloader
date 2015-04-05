#include "youtubedownloader.h"
#include "helper.h"


QList<YouTubeVideoQuality> YoutubeDownloader::GetYouTubeVideoUrls(QString VideoUrl){
    //void YoutubeDownloader::GetYouTubeVideoUrls(QString VideoUrl){


    QList<YouTubeVideoQuality> urls;// = new QList<YouTubeVideoQuality>();
    qDebug() << VideoUrl << endl;


    QString html = Helper::DownloadWebPage(VideoUrl);

    qDebug() << "html";
    QString title = GetTitle(html);
    qDebug() << title << endl;
    foreach(QString videoLink, ExtractUrls(html)) {

        YouTubeVideoQuality q;
        q.setVideoUrl(VideoUrl);
        q.setVideoTitle(title);
        q.setDownloadUrl(videoLink + "&title=" + title);
        //if(!Helper::getSize(q)) continue;
        //QString Length = Helper::GetTxtBtw(html,"\"length_seconds\": \"", "\"",1);
        q.setLength(Helper::GetTxtBtw(html,"\"length_seconds\":\"", "\"",1).toLong());
        //bool isWide = IsWideScreen(html);
        //setSizeDimensionExtension(q);
        if(getQuality(q))
            urls.append(q);
    }

    return urls;
}

bool YoutubeDownloader::getQuality(YouTubeVideoQuality &q){

    int iTagValue;
    QRegExp re("itag=([1-9]?[0-9]?[0-9])");
    if(re.indexIn(q.getDownloadUrl()) != -1 ){
        QString itag = re.cap(1);

        iTagValue = itag.toInt();
        switch(iTagValue){
        case 5: q.SetQuality("flv",  QSize(320,180)); break;
        case 6: q.SetQuality("flv",  QSize(480,270)); break;
        case 17: q.SetQuality("3gp",  QSize(176,99)); break;
        case 18: q.SetQuality("mp4",  QSize(640,360)); break;
        case 22: q.SetQuality("mp4",  QSize(1280,720)); break;
        case 34: q.SetQuality("flv",  QSize(640,360)); break;
        case 35: q.SetQuality("flv",  QSize(854,480)); break;
        case 36: q.SetQuality("3gp",  QSize(320,180)); break;
        case 37: q.SetQuality("mp4",  QSize(1920,1080)); break;
        case 38: q.SetQuality("mp4",  QSize(2048,1152)); break;
        case 43: q.SetQuality("webm",  QSize(640,360)); break;
        case 44: q.SetQuality("webm",  QSize(854,480)); break;
        case 45: q.SetQuality("webm",  QSize(1280,720)); break;
        case 46: q.SetQuality("webm",  QSize(1920,1080)); break;
        case 82: q.SetQuality("3D.mp4",  QSize(480,270)); break;        // 3D
        case 83: q.SetQuality("3D.mp4",  QSize(640,360)); break;        // 3D
        case 84: q.SetQuality("3D.mp4",  QSize(1280,720)); break;       // 3D
        case 85: q.SetQuality("3D.mp4",  QSize(1920,1080)); break;     // 3D
        case 100: q.SetQuality("3D.webm",  QSize(640,360)); break;      // 3D
        case 101: q.SetQuality("3D.webm",  QSize(640,360)); break;      // 3D
        case 102: q.SetQuality("3D.webm",  QSize(1280,720)); break;     // 3D
        case 120: q.SetQuality("live.flv",  QSize(1280,720)); break;    // Live-streaming - should be ignored?
        default: q.SetQuality("itag-" + itag,  QSize(0, 0)); break;       // unknown or parse error

        }
        return true;
    }
    return false;
}


QStringList YoutubeDownloader::ExtractUrls(QString html) {


    QStringList qualityLinks;

    QRegExp re("\"url_encoded_fmt_stream_map\":\"([^\"]*)", Qt::CaseInsensitive, QRegExp::RegExp2);
    QRegExp urls("url=(.*)");
    if(re.indexIn(html) != -1) {

        QString result = re.cap(1);
        foreach (QString line, result.split("\\u0026")) {
            if (urls.indexIn(QUrl::fromPercentEncoding(line.toUtf8())) != -1) {
                qualityLinks.append(urls.cap(1));
            }
        }
    }


    //    if (expression.indexIn(html)!=-1 && expression.cap(1) != "")
    //    {
    //        qualityLinks << expression.cap(1).split(",");
    //    }
    //    if (!qualityLinks.isEmpty())
    //    {

    //        qualityLinks.replaceInStrings("\\u0026", ",");
    //    }
    //    int startIndexOfUrls = html.indexOf("url_encoded_fmt_stream_map",1);
    //    html = Helper::GetTxtBtw(html, "url=", "\"", startIndexOfUrls);
    //    QStringList urls = html.split("url=");

    return qualityLinks;
}

QString YoutubeDownloader::GetTitle(QString RssDoc) {
    //qDebug() << RssDoc;
    QString str14 = Helper::GetTxtBtw(RssDoc,"'VIDEO_TITLE': '", "'",1);
    // qDebug() << str14;
    if (str14 == "") str14 =  Helper::GetTxtBtw(RssDoc,"\"title\" content=\"", "\"", 1);
    if (str14 == "") str14 = Helper::GetTxtBtw(RssDoc, "&title=", "&", 1);
    qDebug() << RssDoc;
    qDebug() << str14;
    str14 = str14.replace("'", "&#39;").replace("\"", "&quot;").replace("<", "&lt;").replace(">", "&gt;").replace("+", " ");
    return str14;
}

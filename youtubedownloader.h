#ifndef YOUTUBEDOWNLOADER_H
#define YOUTUBEDOWNLOADER_H

#include <QList>
#include <QStringList>
#include <QRegExp>
#include <QDebug>
#include <QString>
#include <QUrl>
#include <QRegularExpression>

#include "youtubevideoquality.h"

class YoutubeDownloader
{
public:
    static QList<YouTubeVideoQuality> GetYouTubeVideoUrls(QString VideoUrl);
    // static void GetYouTubeVideoUrls(QString videoUrl);
    static QString GetTitle(QString RssDoc);
    static QStringList ExtractUrls(QString html);

    static bool getQuality(YouTubeVideoQuality &q);
};

#endif // YOUTUBEDOWNLOADER_H

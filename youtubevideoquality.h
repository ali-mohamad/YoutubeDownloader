#ifndef YOUTUBEVIDEOQUALITY_H
#define YOUTUBEVIDEOQUALITY_H

#include <QString>
#include <QSize>

class YouTubeVideoQuality
{
public:

    QString getVideoTitle();
    QString getExtension();
    QString getDownloadUrl();

    QSize getDimension();
    long getVideoSize();
    long getLength();

    void setVideoTitle(QString);
    void setExtension(QString);
    void setDownloadUrl(QString);

    void setDimension(QSize);
    void setVideoSize(long);
    void setLength(long);

    void setVideoUrl(QString);
    QString getVideoUrl();

    QString toString();

    void setSize(long size);
    void SetQuality(QString Extention, QSize Dimension);

    //void SetQuality(QString Quality);
    void SetItag(int itag);
private:
    QString VideoTitle;
    QString VideoUrl;
    QString Extension;
    QString DownloadUrl;
    QSize Dimension;
    long VideoSize;
    long Length;
    int Itag;
    QString Quality;
    QString formatSize(QSize value);
};

#endif // YOUTUBEVIDEOQUALITY_H

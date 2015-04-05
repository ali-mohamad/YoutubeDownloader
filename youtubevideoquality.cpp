#include "youtubevideoquality.h"

QSize YouTubeVideoQuality::getDimension() {
    return this->Dimension;
}

void YouTubeVideoQuality::setDimension(QSize size){
    this->Dimension = size;
}

QString YouTubeVideoQuality::getDownloadUrl() {
    return this->DownloadUrl;
}

void YouTubeVideoQuality::setDownloadUrl(QString str) {
    this->DownloadUrl = str;
}

QString YouTubeVideoQuality::getExtension() {
    return this->Extension;
}

long YouTubeVideoQuality::getLength(){
    return this->Length;
}

long YouTubeVideoQuality::getVideoSize() {
    return this->VideoSize;
}
QString YouTubeVideoQuality::getVideoTitle() {
    return this->VideoTitle;
}

void YouTubeVideoQuality::setExtension(QString str)
{
    this->Extension = str;
}
void YouTubeVideoQuality::setLength(long str){
    this->Length = str;
}
void YouTubeVideoQuality::setVideoSize(long str) {
    this->VideoSize = str;
}
void YouTubeVideoQuality::setVideoTitle(QString str) {
    this->VideoTitle = str;
}

QString YouTubeVideoQuality::formatSize(QSize value) {
    QString s = value.height() >= 720 ? " HD" : "";
    QString Width(QString::number(value.width()));
    QString Height(QString::number(value.height()));
    return Width + " x " +  Height + " " + s;
}

void YouTubeVideoQuality::setSize(long size) {
    this->VideoSize = size;
}

void YouTubeVideoQuality::SetQuality(QString Extension,QSize Dimension)
{
   this->Extension = Extension;
   this->Dimension = Dimension;
}

void YouTubeVideoQuality::SetItag(int itag) {
    this->Itag = itag;
}



QString YouTubeVideoQuality::toString(){
    QString videoExtension = getExtension();
    QString videoDimension(formatSize(getDimension()));
    //Need to implement size
    QString VidSize = QString::number(getVideoSize());
    return videoExtension.toUpper() + " ( " + videoDimension + " ) - " + VidSize + " B";
}

QString YouTubeVideoQuality::getVideoUrl() {
    return this->VideoUrl;
}

void YouTubeVideoQuality::setVideoUrl(QString str) {
    this->VideoUrl = str;
}

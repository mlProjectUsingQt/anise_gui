#include "FileReader.h"


void FileReader::loadFile(QString path){

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    //open a file
    file = new QFile(path);
    file->open(QIODevice::ReadOnly);

    //read each line of that file and save it as a List
    //(line1)->(line2)->(line3)-> etc...
    while (file->bytesAvailable()) {

        QByteArray line = file->readLine();
        // !! Fehler ist hier. die Liste bleibt leer!
        // !! Hier debuggen!
        LineList << line;
    }

    file->close();
}


void FileReader::parseFile(){


}

void FileReader::printFile(){
    if (LineList.isEmpty()) {
        qDebug() << "LineList.isEmpty()! \n the parser didnt read the file correctly!";
    }else{
        foreach (QString line, LineList) {
            qDebug()<< line;
        }
    }
}

void FileReader::writeFile(){


}

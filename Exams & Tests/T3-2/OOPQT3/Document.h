#pragma once
#include <QString>

class Document {
private:
    QString name;
    QString content;
public:
    Document(QString name, QString content);
    QString getName() const;
    QString getContent() const;
    QString toString() const;
};

#include "Document.h"

Document::Document(QString name, QString content)
    : name(name), content(content) {
}

QString Document::getName() const {
    return name;
}

QString Document::getContent() const {
    return content;
}

QString Document::toString() const {
    return name + " | " + content;
}

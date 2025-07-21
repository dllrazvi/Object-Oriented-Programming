#include "OOPQT3.h"
#include <algorithm>
#include "Document.h"


OOPQT3::OOPQT3(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.searchLineEdit, &QLineEdit::textChanged, this, &OOPQT3::filterDocuments);
    connect(ui.bestMatchButton, &QPushButton::clicked, this, &OOPQT3::showBestMatch);
    repo.loadFromFile("input.txt");
    loadDocumentsToList();
}

void OOPQT3::loadDocumentsToList() {
    ui.listWidget->clear();
    const std::vector<Document>& docs = repo.getAll();

    std::vector<Document> sortedDocs = docs;
    std::sort(sortedDocs.begin(), sortedDocs.end(), [](const Document& a, const Document& b) {
        return a.getName().toLower() < b.getName().toLower();
        });

    for (const auto& doc : sortedDocs) {
        ui.listWidget->addItem(doc.toString());
    }
}
void OOPQT3::filterDocuments() {
    QString keyword = ui.searchLineEdit->text().toLower();
    ui.listWidget->clear();

    for (const auto& doc : repo.getAll()) {
        if (doc.getName().toLower().contains(keyword) ||
            doc.getContent().toLower().contains(keyword)) {
            ui.listWidget->addItem(doc.toString());
        }
    }
}
int longestCommonSubstringLength(const QString& a, const QString& b) {
    int maxLen = 0;
    std::vector<std::vector<int>> dp(a.length() + 1, std::vector<int>(b.length() + 1, 0));

    for (int i = 1; i <= a.length(); ++i) {
        for (int j = 1; j <= b.length(); ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLen = std::max(maxLen, dp[i][j]);
            }
        }
    }
    return maxLen;
}

void OOPQT3::showBestMatch() {
    QString input = ui.searchLineEdit->text().toLower();
    if (input.isEmpty()) return;

    const auto& docs = repo.getAll();
    double maxSim = -1;
    const Document* bestDoc = nullptr;

    for (const auto& doc : docs) {
        QString name = doc.getName().toLower();
        int lcsLen = longestCommonSubstringLength(input, name);
        double sim = static_cast<double>(lcsLen) / name.length();
        if (sim > maxSim) {
            maxSim = sim;
            bestDoc = &doc;
        }
    }

    ui.listWidget->clear();
    if (bestDoc) {
        ui.listWidget->addItem(bestDoc->toString());
    }
}


OOPQT3::~OOPQT3()
{
}

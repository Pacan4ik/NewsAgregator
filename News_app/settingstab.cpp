#include "settingstab.h"
#include "ui_settingstab.h"
#include <QMessageBox>
#include <QFile>
#include <QRegularExpression>


const QRegularExpression SettingsTab::lineSeparatorRegex("[\r\n]");


SettingsTab::SettingsTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsTab)
{
    ui->setupUi(this);
    connect(ui->rssTextEdit->document(), SIGNAL(contentsChanged()), this, SLOT(onRssTextEditChanged()));
    loadRssUrlsFromFile();
}

SettingsTab::~SettingsTab()
{
    delete ui;
}


void SettingsTab::saveRssUrlsToFile()
{
    QFile file("rss_urls.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (const QString& rssUrl : rssUrls) {
            out << rssUrl << "\n";
        }
        file.close();
    }
}

void SettingsTab::loadRssUrlsFromFile()
{
    QFile file("rss_urls.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            rssUrls.append(line);
        }
        file.close();
        ui->rssTextEdit->setPlainText(rssUrls.join("\n"));
    }
}


void SettingsTab::onRssTextEditChanged()
{
    QString rssText = ui->rssTextEdit->toPlainText();

    rssUrls = rssText.split(lineSeparatorRegex, Qt::SkipEmptyParts);

    saveRssUrlsToFile();
}

QList<QString> SettingsTab::getRssUrls() const
{
    return rssUrls;
}

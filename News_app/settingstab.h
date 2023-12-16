#ifndef SETTINGSTAB_H
#define SETTINGSTAB_H

#include <QWidget>
#include <QSettings>

namespace Ui {
class SettingsTab;
}

class SettingsTab : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsTab(QWidget *parent = 0);
    ~SettingsTab();

    void saveRssUrlsToFile();
    void loadRssUrlsFromFile();

    QList<QString> getRssUrls() const;

private slots:
    void onRssTextEditChanged();

signals:
    void hideMainWindow();
private:
    Ui::SettingsTab *ui;
    QList<QString> rssUrls;
    static const QRegularExpression lineSeparatorRegex;
};

#endif // SETTINGSTAB_H

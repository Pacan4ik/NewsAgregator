#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->allNewsTab, SIGNAL(readNewsSignal(QString)), this, SLOT(nextPage()));
    QObject::connect(ui->settingsTab, SIGNAL(hideMainWindow()), this, SLOT(hide()));
    connect(ui->allNewsTab, &AllNewsTab::requestUpdateNews, this, &MainWindow::updateNewsTab);
    updateNewsTab();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::nextPage()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::prevoiusPage()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::updateNewsTab()
{

    ui->allNewsTab->clearList();
    ui->allNewsTab->clearAllNews();

    QStringList newsUrls = ui->settingsTab->getRssUrls();

    for (const QString& url : newsUrls) {
        qDebug() << url;
    }

    if (!newsUrls.isEmpty()) {
        ui->allNewsTab->loadNews(newsUrls);
    }
}



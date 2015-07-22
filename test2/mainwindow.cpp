#include <iostream>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createActions();
    createMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createActions()
{
    // action: new file
    action_newfile = new QAction(tr("&New file"), this);
    action_newfile->setShortcut(QKeySequence::New);
    action_newfile->setStatusTip(tr("Create a new file"));
    connect(action_newfile, SIGNAL(triggered()), this, SLOT(on_newFile()));

    // action: save file
    action_savefile = new QAction(tr("&Save file"), this);
    action_savefile->setShortcut(QKeySequence::New);
    action_savefile->setStatusTip(tr("Save file"));
    connect(action_savefile, SIGNAL(triggered()), this, SLOT(on_saveFile()));

}

void MainWindow::createMenu()
{
    menu_file = menuBar()->addMenu(tr("&File"));
    menu_file->addAction(action_newfile);
    menu_file->addAction(action_savefile);
}


void MainWindow::on_newFile()
{
    qDebug() << "new file";

}

void MainWindow::on_saveFile()
{
    qDebug() << "save file";
}

void MainWindow::on_clearLabel()
{

}

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>

#include "test2.h"
#include "ui_test2.h"

Test2::Test2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Test2)
{
    ui->setupUi(this);
    //loadTextFile();

    setFixedSize(787, 326);
}

Test2::~Test2()
{
    delete ui;
}

void Test2::on_findButton_clicked()
{
    QString searchString = ui->lineEdit->text();
    ui->textEdit->find(searchString, QTextDocument::FindWholeWords);

    qDebug() << searchString;
}

void Test2::loadTextFile(QString path)
{
    QFile inputfile(path);

    inputfile.open(QIODevice::ReadOnly);

    QTextStream in(&inputfile);
    QString line = in.readAll();
    inputfile.close();

    ui->textEdit->setPlainText(line);
    QTextCursor cusor = ui->textEdit->textCursor();
    cusor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);


}

void Test2::on_loadButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "C://", "Text file (*.txt)" );
    qDebug() << "File path=" << fileName;
    loadTextFile(fileName);
}

void Test2::on_jpegButton_clicked()
{
    jpegName = QFileDialog::getOpenFileName(this, tr("Open file"),
                                            "C://", "JPG (*.jpg) ;; JPEG (*.jpeg) ;; all (*.*)" );
    if(!jpegName.isEmpty())
    {
        ui->jpegPathEdit->setText(jpegName);

        imageObject = new QImage();
        imageObject->load(jpegName);
        *imageObject = imageObject->scaled(
                    ui->graphicsView->width(),
                    ui->graphicsView->height(),
                    Qt::KeepAspectRatio,
                    Qt::FastTransformation);


        image = QPixmap::fromImage(*imageObject);
        scene = new QGraphicsScene(this);
        scene->addPixmap(image);
        scene->setSceneRect(ui->graphicsView->rect());
        ui->graphicsView->setScene(scene);
    }
}

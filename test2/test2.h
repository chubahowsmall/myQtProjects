#ifndef TEST2_H
#define TEST2_H

#include <QWidget>
#include <QString>
#include <QGraphicsScene>

namespace Ui {
class Test2;
}

class Test2 : public QWidget
{
    Q_OBJECT

public:
    explicit Test2(QWidget *parent = 0);
    ~Test2();

private slots:
    void on_findButton_clicked();

    void on_loadButton_clicked();

    void on_jpegButton_clicked();

private:
    Ui::Test2 *ui;
    QString fileName;
    QString jpegName;

    QPixmap image;
    QImage *imageObject;
    QGraphicsScene *scene;

    void loadTextFile(QString path);
};

#endif // TEST2_H

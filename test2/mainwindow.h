#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_newFile();
    void on_saveFile();
    void on_clearLabel();

private:
    Ui::MainWindow *ui;

    QMenu *menu_file;
    QMenu *menu_about;

    QAction *action_newfile;
    QAction *action_savefile;
    QAction *action_clearlabel;


    // private methods
    void createActions();
    void createMenu();

};

#endif // MAINWINDOW_H

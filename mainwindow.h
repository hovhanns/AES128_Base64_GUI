#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

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
    void on_pushButton_brws_file_clicked();

    void on_pushButton_start_clicked();

    void on_pushButton_gen_key_clicked();

    void on_pushButton_brws_key_clicked();

    void on_pushButton_b64_clicked();

    void on_pushButton_brws_file_b64_clicked();

    void on_pushButton_start_b64_clicked();

private:
    void show_hide_base64();
    Ui::MainWindow *ui;
    QString m_file;
    QString m_key;
    QString m_file_b64;
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <time.h>
#include <stdio.h>
#include <QFile>
#include <string>
#include <iostream>
#include <fstream>
#include "aes_with_file.h"
#include "aes.h"
#include "base64_with_file.h"
char * to_char_array(QString str);

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setGeometry(400, 250, 535,300);
    this->setFixedWidth(510);
    show_hide_base64();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_brws_file_clicked()
{
    m_file = QFileDialog::getOpenFileName(
                this,
                "open file",
                ui->lineEdit_file->text().isEmpty()?"/home/harut": ui->lineEdit_file->text());

    ui->lineEdit_file->setText(m_file);

    //QMessageBox::information(this, "file name", file_name);
}

void MainWindow::on_pushButton_start_clicked()
{
    if(ui->lineEdit_file->text().length() < 2 || ui->lineEdit_key->text().length() < 2)
    {
        ui->statusBar->showMessage("select file and key", 3000);
        return;
    }

    if(ui->radioButton_enc->isChecked())
    {
        encrypt(to_char_array(ui->lineEdit_file->text()),to_char_array(ui->lineEdit_key->text()));
        ui->statusBar->showMessage("File encrypted", 1500);
    }
    else
    {
        decrypt(to_char_array(ui->lineEdit_file->text()),to_char_array(ui->lineEdit_key->text()));
        ui->statusBar->showMessage("File decrypted", 1500);
    }

}

void MainWindow::on_pushButton_gen_key_clicked()
{
    m_key = "/home/harut/APP_AES_KEY.txt";
    generate_key(to_char_array(m_key));
    ui->lineEdit_key->setText(m_key);
}

void MainWindow::on_pushButton_brws_key_clicked()
{
    m_key = QFileDialog::getOpenFileName(
                this,
                "open file",
                ui->lineEdit_key->text().isEmpty()?"/home/harut": ui->lineEdit_key->text());

    ui->lineEdit_key->setText(m_key);
}

char *to_char_array(QString str)
{
    QByteArray bt = str.toLatin1();
    char *ret = NULL;
    ret = (char*)calloc(strlen(bt.data())+1, sizeof(char));
    strcpy(ret, bt.data());
    return ret;
}

void MainWindow::show_hide_base64()
{

    ui->label_base64->setHidden(!ui->label_base64->isHidden());
    ui->label_file_b64->setHidden(!ui->label_file_b64->isHidden());
    ui->lineEdit_file_b64->setHidden(!ui->lineEdit_file_b64->isHidden());
    ui->pushButton_brws_file_b64->setHidden(!ui->pushButton_brws_file_b64->isHidden());
    ui->radioButton_b64_encode->setHidden(!ui->radioButton_b64_encode->isHidden());
    ui->pushButton_start_b64->setHidden(!ui->pushButton_start_b64->isHidden());
    ui->radioButton_b64_decode->setHidden(!ui->radioButton_b64_decode->isHidden());

}

void MainWindow::on_pushButton_b64_clicked()
{
    static bool t = false;
    t = !t;

    this->setFixedHeight(t?460:300);

    show_hide_base64();
}

void MainWindow::on_pushButton_brws_file_b64_clicked()
{
    m_file_b64 = QFileDialog::getOpenFileName(
                this,
                "open file",
                ui->lineEdit_file_b64->text().isEmpty()?"/home/harut": ui->lineEdit_file->text());

    ui->lineEdit_file_b64->setText(m_file_b64);
}

void MainWindow::on_pushButton_start_b64_clicked()
{
    if(ui->lineEdit_file_b64->text().length() < 2)
    {
        ui->statusBar->showMessage("select file for encode/decode", 3000);
        return;
    }

    if(ui->radioButton_b64_encode->isChecked())
    {
        encode_base_64(to_char_array(ui->lineEdit_file_b64->text()));
        ui->statusBar->showMessage("File encoded!", 1500);

    }
    else
    {
        decode_base_64(to_char_array(ui->lineEdit_file_b64->text()));
        ui->statusBar->showMessage("File decoded!", 1500);
    }

}

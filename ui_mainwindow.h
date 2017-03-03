/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QApplication>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QStatusBar>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_start;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_key;
    QLineEdit *lineEdit_key;
    QPushButton *pushButton_brws_key;
    QPushButton *pushButton_gen_key;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_enc;
    QRadioButton *radioButton_dec;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_file;
    QLineEdit *lineEdit_file;
    QPushButton *pushButton_brws_file;
    QLabel *label_base64;
    QPushButton *pushButton_b64;
    QPushButton *pushButton_start_b64;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_file_b64;
    QLineEdit *lineEdit_file_b64;
    QPushButton *pushButton_brws_file_b64;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *radioButton_b64_encode;
    QRadioButton *radioButton_b64_decode;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(535, 455);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(200, 170, 101, 41));
        QFont font;
        font.setPointSize(11);
        pushButton_start->setFont(font);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 80, 471, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_key = new QLabel(layoutWidget);
        label_key->setObjectName(QString::fromUtf8("label_key"));

        horizontalLayout_2->addWidget(label_key);

        lineEdit_key = new QLineEdit(layoutWidget);
        lineEdit_key->setObjectName(QString::fromUtf8("lineEdit_key"));

        horizontalLayout_2->addWidget(lineEdit_key);

        pushButton_brws_key = new QPushButton(layoutWidget);
        pushButton_brws_key->setObjectName(QString::fromUtf8("pushButton_brws_key"));

        horizontalLayout_2->addWidget(pushButton_brws_key);

        pushButton_gen_key = new QPushButton(layoutWidget);
        pushButton_gen_key->setObjectName(QString::fromUtf8("pushButton_gen_key"));

        horizontalLayout_2->addWidget(pushButton_gen_key);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 130, 241, 24));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButton_enc = new QRadioButton(layoutWidget1);
        radioButton_enc->setObjectName(QString::fromUtf8("radioButton_enc"));
        radioButton_enc->setChecked(true);

        horizontalLayout_3->addWidget(radioButton_enc);

        radioButton_dec = new QRadioButton(layoutWidget1);
        radioButton_dec->setObjectName(QString::fromUtf8("radioButton_dec"));

        horizontalLayout_3->addWidget(radioButton_dec);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 30, 371, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_file = new QLabel(layoutWidget2);
        label_file->setObjectName(QString::fromUtf8("label_file"));

        horizontalLayout->addWidget(label_file);

        lineEdit_file = new QLineEdit(layoutWidget2);
        lineEdit_file->setObjectName(QString::fromUtf8("lineEdit_file"));

        horizontalLayout->addWidget(lineEdit_file);

        pushButton_brws_file = new QPushButton(layoutWidget2);
        pushButton_brws_file->setObjectName(QString::fromUtf8("pushButton_brws_file"));

        horizontalLayout->addWidget(pushButton_brws_file);

        label_base64 = new QLabel(centralWidget);
        label_base64->setObjectName(QString::fromUtf8("label_base64"));
        label_base64->setGeometry(QRect(220, 270, 91, 31));
        QFont font1;
        font1.setPointSize(12);
        label_base64->setFont(font1);
        pushButton_b64 = new QPushButton(centralWidget);
        pushButton_b64->setObjectName(QString::fromUtf8("pushButton_b64"));
        pushButton_b64->setGeometry(QRect(200, 220, 101, 41));
        pushButton_b64->setFont(font);
        pushButton_start_b64 = new QPushButton(centralWidget);
        pushButton_start_b64->setObjectName(QString::fromUtf8("pushButton_start_b64"));
        pushButton_start_b64->setGeometry(QRect(170, 390, 181, 41));
        pushButton_start_b64->setFont(font);
        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(30, 310, 421, 29));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_file_b64 = new QLabel(layoutWidget3);
        label_file_b64->setObjectName(QString::fromUtf8("label_file_b64"));

        horizontalLayout_4->addWidget(label_file_b64);

        lineEdit_file_b64 = new QLineEdit(layoutWidget3);
        lineEdit_file_b64->setObjectName(QString::fromUtf8("lineEdit_file_b64"));

        horizontalLayout_4->addWidget(lineEdit_file_b64);

        pushButton_brws_file_b64 = new QPushButton(layoutWidget3);
        pushButton_brws_file_b64->setObjectName(QString::fromUtf8("pushButton_brws_file_b64"));

        horizontalLayout_4->addWidget(pushButton_brws_file_b64);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(30, 350, 221, 24));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        radioButton_b64_encode = new QRadioButton(layoutWidget4);
        radioButton_b64_encode->setObjectName(QString::fromUtf8("radioButton_b64_encode"));
        radioButton_b64_encode->setChecked(true);

        horizontalLayout_5->addWidget(radioButton_b64_encode);

        radioButton_b64_decode = new QRadioButton(layoutWidget4);
        radioButton_b64_decode->setObjectName(QString::fromUtf8("radioButton_b64_decode"));

        horizontalLayout_5->addWidget(radioButton_b64_decode);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setSizeGripEnabled(false);
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "AES-128, Base64", 0));
        pushButton_start->setText(QApplication::translate("MainWindow", "Start!", 0));
        label_key->setText(QApplication::translate("MainWindow", "Key:", 0));
        pushButton_brws_key->setText(QApplication::translate("MainWindow", "Browse", 0));
        pushButton_gen_key->setText(QApplication::translate("MainWindow", "Generate key", 0));
        radioButton_enc->setText(QApplication::translate("MainWindow", "Encryption", 0));
        radioButton_dec->setText(QApplication::translate("MainWindow", "Decryption", 0));
        label_file->setText(QApplication::translate("MainWindow", "File:", 0));
        pushButton_brws_file->setText(QApplication::translate("MainWindow", "Browse", 0));
        label_base64->setText(QApplication::translate("MainWindow", "Base 64", 0));
        pushButton_b64->setText(QApplication::translate("MainWindow", "Base64", 0));
        pushButton_start_b64->setText(QApplication::translate("MainWindow", "Start encode/decode", 0));
        label_file_b64->setText(QApplication::translate("MainWindow", "File:", 0));
        pushButton_brws_file_b64->setText(QApplication::translate("MainWindow", "Browse", 0));
        radioButton_b64_encode->setText(QApplication::translate("MainWindow", "Encode", 0));
        radioButton_b64_decode->setText(QApplication::translate("MainWindow", "Decode", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

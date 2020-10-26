/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *InputText;
    QPushButton *pushButton;
    QTableWidget *Table;
    QPushButton *DeleteAll;
    QPushButton *Archivator;
    QScrollBar *verticalScrollBar;
    QPushButton *Archive;
    QPushButton *Notes;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1274, 639);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        InputText = new QTextEdit(centralwidget);
        InputText->setObjectName(QString::fromUtf8("InputText"));
        InputText->setGeometry(QRect(30, 20, 540, 391));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 410, 93, 28));
        Table = new QTableWidget(centralwidget);
        if (Table->columnCount() < 2)
            Table->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        Table->setObjectName(QString::fromUtf8("Table"));
        Table->setGeometry(QRect(640, 20, 590, 511));
        Table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        Table->setSelectionBehavior(QAbstractItemView::SelectRows);
        Table->horizontalHeader()->setCascadingSectionResizes(true);
        Table->horizontalHeader()->setDefaultSectionSize(180);
        Table->horizontalHeader()->setStretchLastSection(true);
        DeleteAll = new QPushButton(centralwidget);
        DeleteAll->setObjectName(QString::fromUtf8("DeleteAll"));
        DeleteAll->setGeometry(QRect(1140, 530, 90, 28));
        Archivator = new QPushButton(centralwidget);
        Archivator->setObjectName(QString::fromUtf8("Archivator"));
        Archivator->setGeometry(QRect(1050, 530, 90, 28));
        verticalScrollBar = new QScrollBar(centralwidget);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(570, 20, 20, 391));
        verticalScrollBar->setOrientation(Qt::Vertical);
        Archive = new QPushButton(centralwidget);
        Archive->setObjectName(QString::fromUtf8("Archive"));
        Archive->setGeometry(QRect(730, 530, 90, 28));
        Notes = new QPushButton(centralwidget);
        Notes->setObjectName(QString::fromUtf8("Notes"));
        Notes->setGeometry(QRect(640, 530, 90, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1274, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        InputText->setPlaceholderText(QCoreApplication::translate("MainWindow", "Express your minds here...", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        QTableWidgetItem *___qtablewidgetitem = Table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Data", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = Table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Note", nullptr));
        DeleteAll->setText(QCoreApplication::translate("MainWindow", "Delete All", nullptr));
        Archivator->setText(QCoreApplication::translate("MainWindow", "AddToArchive", nullptr));
        Archive->setText(QCoreApplication::translate("MainWindow", "Archive", nullptr));
        Notes->setText(QCoreApplication::translate("MainWindow", "Notes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

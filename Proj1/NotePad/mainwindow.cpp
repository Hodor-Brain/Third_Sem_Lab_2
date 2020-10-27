#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "helpwindow.h"
#include "QDateTime"
#include <QDebug>
#include "QFile"
#include "QVector"
#include "QtAlgorithms"
#include "algorithm"

#define FILENAME "AllTheNotes"
#define ARCHIVE "ArchiveFile"

struct Note
{
    QString CurNote;
    QDateTime CurData = QDateTime::currentDateTime();
    int ID = -1;
    bool IsArchived = false;
};



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    StartReading();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::StartReading()
{
    QFile file(ARCHIVE);
    file.open(QIODevice::Append);
    file.close();

    QVector<Note> notes;

    FileReading(FILENAME, notes, false);

    for (int i = 0; i < notes.length(); i++)
    {
        QString str = notes[i].CurData.toString();

        QTableWidgetItem* q = new QTableWidgetItem(str);
        QTableWidgetItem* qq = new QTableWidgetItem(notes[i].CurNote );

        ui->Table->insertRow(0);
        ui->Table->setItem(0,0,q);
        ui->Table->setItem(0,1,qq);
    }
}


void MainWindow::ArchiveReading()
{
    QVector<Note> notes;

    FileReading(ARCHIVE, notes, true);

    for (int i = 0; i < notes.length(); i++)
    {
        QString str = notes[i].CurData.toString();

        QTableWidgetItem* q = new QTableWidgetItem(str);
        QTableWidgetItem* qq = new QTableWidgetItem(notes[i].CurNote );

        ui->Table->insertRow(0);
        ui->Table->setItem(0,0,q);
        ui->Table->setItem(0,1,qq);
    }
}


void FileWriting(QString filename, Note note)
{
    QFile file(filename);

    file.open(QIODevice::Append);

    QDataStream out(&file);

    out << note.CurData;
    out << note.CurNote;
    out << note.ID;
    out << note.IsArchived;

    file.close();
}

void FileReading(QString filename, QVector<Note> &notes, bool isArch)
{
    QFile file(filename);

    file.open(QIODevice::ReadOnly);

    QDataStream in(&file);

    while (!in.atEnd())
    {
        Note n;

        in >> n.CurData;
        in >> n.CurNote;
        in >> n.ID;
        in >> n.IsArchived;

        if (n.IsArchived == false || isArch)
        {
            notes.push_back(n);
        }
    }

    file.close();
}

int LastIndex(QString filename)
{
    QFile file(filename);

    file.open(QIODevice::ReadOnly);

    QDataStream in(&file);

    Note n;

    while (!in.atEnd())
    {
        in >> n.CurData;
        in >> n.CurNote;
        in >> n.ID;
        in >> n.IsArchived;
    }

    file.close();

    return n.ID;
}


void MainWindow::on_pushButton_clicked()
{
    //ui->Table->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    Note note;

    note.CurNote  = ui->InputText->toPlainText();

    if (note.CurNote  == "")
    {
        return;
    }

    note.ID = LastIndex(FILENAME) + 1;

    QString datastr = note.CurData.toString();

    QTableWidgetItem* q = new QTableWidgetItem(datastr);
    QTableWidgetItem* qq = new QTableWidgetItem(note.CurNote );

    ui->Table->insertRow(0);
    ui->Table->setItem(0,0,q);
    ui->Table->setItem(0,1,qq);

    FileWriting(FILENAME, note);

    ui->InputText->clear();
}


void MainWindow::on_Table_cellDoubleClicked(int row, int column)
{
    if (column == 0)
           return;

       QTableWidgetItem* q;
       q = ui->Table->item(row, column);

       QString str;

       str = q->text();

       HelpWindow help;

       help.InsertStr(str);

       //help.setModal(true);
       help.exec();


       //ui->InputText->insertPlainText(str);
}

void MainWindow::on_DeleteAll_clicked()
{
    if (ui->Title2->text() == "Notes List")
    {
        QFile file(FILENAME);
        file.open(QIODevice::WriteOnly);
        file.close();
    }
    else if (ui->Title2->text() == "Archive List")
    {
        QFile file1(ARCHIVE);
        file1.open(QIODevice::WriteOnly);
        file1.close();
    }

    for (int i = ui->Table->rowCount(); i >= 0 ; i--)
    {
        ui->Table->removeRow(i);
    }
}


void MainWindow::AddToArchive(QVector<int> indexes)
{
    long long pos;

    QFile file(FILENAME);
    QFile file1(ARCHIVE);

    file1.open(QIODevice::Append);
    file.open(QIODevice::ReadWrite);

    Note temp;

    QDataStream inn(&file1);
    QDataStream in(&file);

    while (!in.atEnd())
    {
        pos = file.pos();

        in >> temp.CurData;
        in >> temp.CurNote;
        in >> temp.ID;
        in >> temp.IsArchived;

        for (int i = 0; i < indexes.length(); i++)
        {
            QTableWidgetItem* q;
            q = ui->Table->item(indexes[i], 0);

            QString str;

            str = q->text();

            if (temp.CurData.toString() == str)
            {
                file.seek(pos);

                temp.IsArchived = true;

                in << temp.CurData;
                in << temp.CurNote;
                in << temp.ID;
                in << temp.IsArchived;

                inn << temp.CurData;
                inn << temp.CurNote;
                inn << temp.ID;
                inn << temp.IsArchived;

                break;
            }
        }
    }

    file.close();
    file1.close();
}


void MainWindow::on_Archivator_clicked()
{
    /*QVector<Note> v;
    FileReading(FILENAME, v);

    for (int i = 0; i < v.length(); i++)
    {
        qDebug() << v[i].ID;
    }*/

    QModelIndexList selection = ui->Table->selectionModel()->selectedRows();

    QVector<int> indexes;

    for(int i = 0; i < selection.count(); i++)
    {
        QModelIndex index = selection.at(i);
        indexes.push_back(index.row());

        //qDebug() << indexes[i];
    }

    std::sort(indexes.begin(), indexes.end());

    /*for (int i = 0; i < indexes.length(); i++)
    {
        qDebug() << indexes[i];
    }*/

    AddToArchive(indexes);

    for(int i = indexes.length() - 1; i >= 0; i--)
    {
        ui->Table->removeRow(indexes[i]);
    }
}


void MainWindow::on_Notes_clicked()
{
    ui->Title2->clear();
    ui->Title2->insert("Notes List");

    int count = ui->Table->rowCount();

    for (int i = count - 1; i >= 0; i--)
    {
        ui->Table->removeRow(i);
    }

    StartReading();
}

void MainWindow::on_Archive_clicked()
{
    ui->Title2->clear();
    ui->Title2->insert("Archive List");

    int count = ui->Table->rowCount();

    for (int i = count - 1; i >= 0; i--)
    {
        ui->Table->removeRow(i);
    }

    ArchiveReading();
}



void MainWindow::DeleteElements(QVector<int> indexes, QString filename)
{
    QFile file(filename);
    QFile newfile("TEMP");

    newfile.open(QIODevice::WriteOnly);
    file.open(QIODevice::ReadWrite);

    Note temp;

    bool isDel = false;

    QDataStream in(&newfile);
    QDataStream out(&file);

    while (!out.atEnd())
    {
        out >> temp.CurData;
        out >> temp.CurNote;
        out >> temp.ID;
        out >> temp.IsArchived;

        for (int i = 0; i < indexes.length(); i++)
        {
            QTableWidgetItem* q;
            q = ui->Table->item(indexes[i], 0);

            QString str;

            str = q->text();

            if (temp.CurData.toString() == str)
            {
                isDel = true;
                break;
            }
        }

        if (!isDel)
        {
            in << temp.CurData;
            in << temp.CurNote;
            in << temp.ID;
            in << temp.IsArchived;
        }

        isDel = false;
    }

    file.close();
    newfile.close();

    remove(filename.toStdString().c_str());
    rename("TEMP", filename.toStdString().c_str());
}


void MainWindow::on_Delete_clicked()
{
    QString filename;

    if (ui->Title2->text() == "Notes List")
        filename = FILENAME;
    else
        filename = ARCHIVE;

    QModelIndexList selection = ui->Table->selectionModel()->selectedRows();

    QVector<int> indexes;

    for(int i = 0; i < selection.count(); i++)
    {
        QModelIndex index = selection.at(i);
        indexes.push_back(index.row());
    }

    std::sort(indexes.begin(), indexes.end());

    DeleteElements(indexes, filename);

    for(int i = indexes.length() - 1; i >= 0; i--)
    {
        ui->Table->removeRow(indexes[i]);
    }
}

void MainWindow::on_Dearchivate_clicked()
{
    if (ui->Title2->text() == "Notes List")
        return;


}






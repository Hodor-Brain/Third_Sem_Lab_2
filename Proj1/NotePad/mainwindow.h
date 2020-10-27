#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "helpwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void StartReading();

    void ArchiveReading();

    void on_pushButton_clicked();

    void on_Table_cellDoubleClicked(int row, int column);

    void on_DeleteAll_clicked();

    void on_Archivator_clicked();

    void AddToArchive(QVector<int> indexes);

    void on_Notes_clicked();

    void on_Archive_clicked();

    void DeleteElements(QVector<int> indexes, QString filename);

    void on_Delete_clicked();

    void on_Dearchivate_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

struct Note ;

void FileWriting(QString filename, Note note);
void FileReading(QString filename, QVector<Note> &notes, bool isArch);

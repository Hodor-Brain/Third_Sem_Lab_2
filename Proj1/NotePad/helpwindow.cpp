#include "helpwindow.h"
#include "ui_helpwindow.h"

HelpWindow::HelpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
}

HelpWindow::~HelpWindow()
{
    delete ui;
}

void HelpWindow::InsertStr(QString q)
{
    ui->DialText->insertPlainText(q);
}

/*void HelpWindow::on_pushButton_clicked()
{
    this->close();
}*/



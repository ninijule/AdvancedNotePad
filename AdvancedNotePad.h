#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AdvancedNotePad.h"
#include "qfile.h"
#include "qmessagebox.h"
#include "qfiledialog.h"
#include "qtextstream.h"

class AdvancedNotePad : public QMainWindow
{
    Q_OBJECT

public:
    AdvancedNotePad(QWidget *parent = Q_NULLPTR);

private:
    Ui::AdvancedNotePadClass ui;
    QString currentFile = "";


private slots:
    void on_actionQuit_triggered();
    void on_actionNew_File_triggered();
    void on_actionOpen_triggered();
};

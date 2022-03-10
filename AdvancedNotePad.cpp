#include "AdvancedNotePad.h"
#include <QApplication>
#include "stdafx.h"
#include "qdebug.h"

AdvancedNotePad::AdvancedNotePad(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setCentralWidget(ui.textEdit);
}


void AdvancedNotePad::on_actionNew_File_triggered() {
	qDebug("New File");
	currentFile.clear();
	ui.textEdit->setText(QString());

}

void AdvancedNotePad::on_actionOpen_triggered() {
	qDebug("Opening file");
	QString filename = QFileDialog::getOpenFileName(this, "Open the file");
	QFile file(filename);
	currentFile = filename;
	if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
		QMessageBox::warning(this, "Warning", "Cannot open file :" + file.errorString());
		return;
	}
	setWindowTitle(filename);
	QTextStream in(&file);
	QString text = in.readAll();
	ui.textEdit->setText(text);
	file.close();
}

void AdvancedNotePad::on_actionSave_as_triggered() {
	qDebug("Save As");
	QString filename = QFileDialog::getSaveFileName(this, "Saved as");
	QFile file(filename);
	currentFile = filename;
	if (!file.open(QFile::WriteOnly | QFile::Text)) {
		QMessageBox::warning(this, "Warning", "Cannot save file :" + file.errorString());
		return;
	}
	currentFile = filename;
	setWindowTitle(filename);
	QTextStream ou(&file);
	QString text = ui.textEdit->toPlainText();
	ou << text;
	file.close();

}

void AdvancedNotePad::on_actionAbout_triggered()
{
	qDebug("About application");
	QMessageBox::information(this, "Information", "This software has been developed in C++ by Julian Beutin");
}


void AdvancedNotePad::on_actionQuit_triggered()
{
	qDebug("Closing application");
	QCoreApplication::quit();
}
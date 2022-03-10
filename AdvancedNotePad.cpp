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
	qDebug("Bonjour dfkljgbn");
	currentFile.clear();
	ui.textEdit->setText(QString());

}

void AdvancedNotePad::on_actionOpen_triggered() {
	QString filename = QFileDialog::getOpenFileName(this, "Open the file");

	QFile file(filename);
	currentFile = filename;
	if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
		QMessageBox::warning(this, "Warning", "Cannot open file :" + file.errorString());
	}
	setWindowTitle(filename);
	QTextStream in(&file);
	QString text = in.readAll();
	ui.textEdit->setText(text);
	file.close();
}

void AdvancedNotePad::on_actionQuit_triggered()
{
	qDebug("Closing application");
	QCoreApplication::quit();

}
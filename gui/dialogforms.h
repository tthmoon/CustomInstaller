#ifndef DIALOGFORMS_H
#define DIALOGFORMS_H

#include <QMessageBox>
#include <QFileDialog>
#include <QDir>

class DialogForms: QWidget
{
  Q_OBJECT
public:
  DialogForms();
  static bool question(const QString &title, const QString &text, QWidget *parent= Q_NULLPTR);
};

#endif // DIALOGFORMS_H

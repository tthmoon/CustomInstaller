#include "dialogforms.h"

#include <QString>
#include <QWidget>
#include <QIcon>

bool DialogForms::question(const QString& title, const QString& text, QWidget* parent)
{
  QMessageBox messageBox(
    QMessageBox::Question,
    title,
    text,
    QMessageBox::Yes | QMessageBox::No,
    parent
  );
  messageBox.setButtonText(QMessageBox::Yes, tr("Yes"));
  messageBox.setButtonText(QMessageBox::No,  tr("No"));
  messageBox.setWindowIcon(QIcon(":/images/icon"));

  if (messageBox.exec() == QMessageBox::Yes)
    return true;
  return false;
}

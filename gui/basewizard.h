#ifndef BASEWIZARD_H
#define BASEWIZARD_H

#include <QWizard>
#include <QTranslator>

class BaseWizard : public QWizard
{
  Q_OBJECT
public:
  BaseWizard(QWidget* parent);
private slots:
  void slotCancelEvent();
};

#endif // BASEWIZARD_H

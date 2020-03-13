#ifndef BASEPAGE_H
#define BASEPAGE_H

#include <QWizardPage>
#include "../data/dataprovider.h"

class BasePage: public QWizardPage
{
  Q_OBJECT
public:
  BasePage(QWidget* parent = Q_NULLPTR);
protected:
  void setBody(QWidget *content);
};

#endif // BASEPAGE_H

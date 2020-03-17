#ifndef FINISHPAGE_H
#define FINISHPAGE_H

#include <QWidget>

#include "../../basepage.h"

namespace Ui {
  class FinishPage;
}

class FinishPage : public BasePage
{
  Q_OBJECT

public:
  explicit FinishPage(QWidget *parent = 0);
  ~FinishPage();

private:
  Ui::FinishPage *ui;
};

#endif // FINISHPAGE_H

#ifndef INTROPAGE_H
#define INTROPAGE_H

#include <QWidget>
#include "../../basepage.h"

namespace Ui {
  class IntroPage;
}

class IntroPage : public BasePage
{
  Q_OBJECT
public:
  explicit IntroPage(QWidget *parent = 0);
  ~IntroPage();

private:
  Ui::IntroPage *ui;
};

#endif // INTROPAGE_H

#ifndef READYFORINSTALLPAGE_H
#define READYFORINSTALLPAGE_H
#include <QWidget>

#include "../../basepage.h"


namespace Ui {
  class ReadyForInstallPage;
}

class ReadyForInstallPage : public BasePage
{
  Q_OBJECT

public:
  explicit ReadyForInstallPage(QWidget *parent = 0);
  ~ReadyForInstallPage();
  void initializePage();

private:
  Ui::ReadyForInstallPage *ui;
};

#endif // READYFORINSTALLPAGE_H

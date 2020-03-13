#ifndef INSTALLPROCESSPAGE_H
#define INSTALLPROCESSPAGE_H

#include "../../basepage.h"
#include "../../../cores/installationcore.h"

namespace Ui {
  class InstallProcessPage;
}

class InstallProcessPage : public BasePage
{
  Q_OBJECT

public:
  explicit InstallProcessPage(DataProvider* data_provider, InstallationCore* core, QWidget *parent = 0);
  ~InstallProcessPage();

  void initializePage();
private:
  Ui::InstallProcessPage *ui;
  DataProvider* data_provider_;
  InstallationCore* core_;
};

#endif // INSTALLPROCESSPAGE_H

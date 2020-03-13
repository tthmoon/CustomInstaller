#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <QWidget>

#include "../../basepage.h"

namespace Ui {
  class SettingsPage;
}

class SettingsPage : public BasePage
{
  Q_OBJECT

public:
  explicit SettingsPage(DataProvider* data_provider, QWidget *parent = 0);
  ~SettingsPage();

private:
  Ui::SettingsPage *ui;
  DataProvider* data_provider_;
  void initializePage();
  bool validatePage();
};

#endif // SETTINGSPAGE_H

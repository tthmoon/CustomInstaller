#ifndef ADDINGSTARTMENUPAGE_H
#define ADDINGSTARTMENUPAGE_H

#include <QWidget>

#include "../../basepage.h"

namespace Ui {
  class AddingStartMenuPage;
}

class AddingStartMenuPage : public BasePage
{
  Q_OBJECT

public:
  explicit AddingStartMenuPage(DataProvider* data_provider, QWidget *parent = 0);
  ~AddingStartMenuPage();

  bool validatePage();
  bool createStartMenuEntry();
  void initializePage();
  void fillFoldersList();
private slots:
  void on_lw_existing_folders_clicked(const QModelIndex &index);

private:
  Ui::AddingStartMenuPage *ui;
  DataProvider* data_provider_;
};

#endif // ADDINGSTARTMENUPAGE_H

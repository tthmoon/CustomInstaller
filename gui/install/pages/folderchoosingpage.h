#ifndef FOLDERCHOOSINGPAGE_H
#define FOLDERCHOOSINGPAGE_H

#include <QWidget>

#include "../../basepage.h"
#include "../../wdirectory.h"

namespace Ui {
  class FolderChoosingPage;
}

class FolderChoosingPage : public BasePage
{
  Q_OBJECT

public:
  explicit FolderChoosingPage(DataProvider* data_provider, QWidget* parent = 0);
  ~FolderChoosingPage();

  bool validatePage();
private slots:
  void on_pb_explore_clicked();

private:
  Ui::FolderChoosingPage *ui;
  DataProvider* data_provider_;
  void initializePage();
};

#endif // FOLDERCHOOSINGPAGE_H

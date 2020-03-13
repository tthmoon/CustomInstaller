#ifndef PAGESMANAGER_H
#define PAGESMANAGER_H

#include "../basepage.h"
#include "pages/intropage.h"
#include "pages/folderchoosingpage.h"
#include "pages/settingspage.h"
#include "pages/addingstartmenupage.h"
#include "pages/readyforinstallpage.h"
#include "pages/installprocesspage.h"

class PagesManager
{
public:
  IntroPage* getIntroPage();
  FolderChoosingPage* getFolderChoosingPage(DataProvider* data_provider);
  SettingsPage* getSettingsPage(DataProvider* data_provider);
  AddingStartMenuPage* getAddingStartMenuPage(DataProvider* data_provider);
  ReadyForInstallPage *getReadyForInstallPage();
//  InstallProcessPage *getInstallProcessPage(DataProvider *data_provider);
  InstallProcessPage *getInstallProcessPage(DataProvider *data_provider, InstallationCore *core);
};

#endif // PAGESMANAGER_H

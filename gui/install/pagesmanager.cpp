#include "pagesmanager.h"

IntroPage* PagesManager::getIntroPage(){
  IntroPage* page = new IntroPage();
  return page;
}

FolderChoosingPage* PagesManager::getFolderChoosingPage(DataProvider* data_provider){
  FolderChoosingPage* page = new FolderChoosingPage(data_provider);
  return page;
}

SettingsPage* PagesManager::getSettingsPage(DataProvider* data_provider){
  SettingsPage* page = new SettingsPage(data_provider);
  return page;
}

AddingStartMenuPage* PagesManager::getAddingStartMenuPage(DataProvider* data_provider){
  AddingStartMenuPage* page = new AddingStartMenuPage(data_provider);
  return page;
}

ReadyForInstallPage* PagesManager::getReadyForInstallPage(){
  ReadyForInstallPage* page = new ReadyForInstallPage();
  return page;
}

InstallProcessPage* PagesManager::getInstallProcessPage(DataProvider* data_provider, InstallationCore* core){
  InstallProcessPage* page = new InstallProcessPage(data_provider, core);
  return page;
}

FinishPage* PagesManager::getFinishPage(){
  FinishPage* page = new FinishPage();
  return page;
}



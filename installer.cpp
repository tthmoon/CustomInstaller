#include <QApplication>
#include <QTranslator>

#include "installer.h"
#include "gui/install/pagesmanager.h"
#include "gui/install/installerwizard.h"
#include "data/dataprovider.h"
#include "cores/installationcore.h"

int Installer::run(int argc, char *argv[]){
  QApplication a(argc, argv);

  QTranslator translator;
  translator.load(":/lang/installer_ru.qm");
  a.installTranslator(&translator);

  PagesManager pages_manager;
  InstallerWizard wizard;
  DataProvider data_provider;
  InstallationCore* core = new InstallationCore(&data_provider);

  wizard.addPage(pages_manager.getIntroPage());
  wizard.addPage(pages_manager.getFolderChoosingPage(&data_provider));
  wizard.addPage(pages_manager.getSettingsPage(&data_provider));
  wizard.addPage(pages_manager.getAddingStartMenuPage(&data_provider));
  wizard.addPage(pages_manager.getReadyForInstallPage());
  wizard.addPage(pages_manager.getInstallProcessPage(&data_provider, core));
  wizard.addPage(pages_manager.getFinishPage());


  wizard.show();

  int app_result = a.exec();
  return app_result;
}

Installer::~Installer()
{

}

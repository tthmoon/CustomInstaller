#include <QSettings>

#include "dataprovider.h"
#include "constants.h"

DataProvider::DataProvider()
{
  load();
}
void DataProvider::load()
{
  QSettings settings(CONST::COMPANY, CONST::PRODUCT);

//  auto loadInt = [&](int& number, const char* system_path, int default_value)
//  {
//    number = settings.value(system_path, QVariant(default_value)).toInt();
//  };
//  auto loadDouble = [&](double& number, const char* system_path, int default_value)
//  {
//    number = settings.value(system_path, QVariant(default_value)).toDouble();
//  };
  auto loadBool = [&](bool& boolean, const char* system_path, bool default_value)
  {
    boolean = settings.value(system_path, QVariant(default_value)).toBool();
  };
  auto loadString = [&](QString& string, const char* system_path, QString default_value)
  {
    string = settings.value(system_path, QVariant(default_value)).toString();
  };

  loadString(installer_.folders_.program_path_, "Installer/Folders/Program", "C:\\Program Files (x86)\\Simicon Tools");
  loadString(installer_.folders_.base_path_, "Installer/Folders/Base", "C:\\ProgramData\\SimiconData");
  loadString(installer_.folders_.work_path_, "Installer/Folders/Work", "C:\\ProgramData\\SimiconWork");
  loadString(installer_.folders_.tar_path_, "Installer/Folders/Tar", "C:\\ProgramData\\SimiconTars");

  loadBool(installer_.if_clear_base_dir_, "Installer/ClearBaseDir", false);

  loadString(
    installer_.shortcut_.target_path_,
    "Installer/Folders/StartMenuFolder",
    installer_.folders_.program_path_ + "\\ParkonA-Server\\parkona_server.exe"
  );
  loadString(installer_.shortcut_.start_menu_folder_, "Installer/Folders/ShortcutTarget", "Simicon Tools");
  loadString(installer_.shortcut_.link_name_, "Installer/Folders/ShortcutLinkName", "Паркон-А Сервер.lnk");
  loadString(installer_.shortcut_.shortcut_disription_, "Installer/Folders/ShortcutLinkName", "Паркон-А Сервер");
}

void DataProvider::save()
{
  QSettings settings(CONST::COMPANY, CONST::PRODUCT);

  settings.setValue("Installer/Folders/Program", QVariant(installer_.folders_.program_path_));
  settings.setValue("Installer/Folders/Base", QVariant(installer_.folders_.base_path_));
  settings.setValue("Installer/Folders/Work", QVariant(installer_.folders_.work_path_));
  settings.setValue("Installer/Folders/Tar", QVariant(installer_.folders_.tar_path_));

  settings.setValue("IInstaller/ClearBaseDir", QVariant(installer_.if_clear_base_dir_));
}

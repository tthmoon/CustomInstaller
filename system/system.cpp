#include "system.h"



QString System::getOsName()
{
  QSysInfo::productType();
}

QString System::getOsArch()
{
  QSysInfo::currentCpuArchitecture();
}
System::SystemNames System::getPrettyOsName()
{
  QString os_name {getOsName()};
  if (os_name == "windows") { // Возможность учета архитектуры процессора
    return SystemNames::WINDOWS
  }
  else  { // временный костыль, требуется учет всех возможных ос
    return SystemNames::LINUX
  }
}

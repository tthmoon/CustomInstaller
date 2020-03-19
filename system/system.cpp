#include "system.h"



QString System::getOssName()
{
  return QSysInfo::productType();
}

QString System::getOsArch()
{
  return QSysInfo::currentCpuArchitecture();
}
System::SystemNames System::getPrettyOsName()
{
  QString os_name {getOssName()};
  if (os_name == "windows") { // Возможность учета архитектуры процессора
    return SystemNames::WINDOWS;
  }
  else  { // временный костыль, требуется учет всех возможных ос
    return SystemNames::LINUX;
  }
}

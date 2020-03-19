#ifndef SYSTEM_H
#define SYSTEM_H

#include <QString>
#include <QString>

class System
{
public:
  enum SystemNames {
    WINDOWS,
    LINUX
  };
  System();
  static SystemNames getPrettyOsName();
private:
  static QString getOssName();
  static QString getOsArch();
};

#endif // SYSTEM_H

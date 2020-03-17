#include "installalgorithm.h"

#include <QProcess>
#include <QDir>

InstallAlgorithm::InstallAlgorithm(const QString& sql_path, const QString& db_path)
  : process_ {new Process()},
    database_ {new DataBase(sql_path, db_path)},
    files_ {new Files()},
    folders_ {new Folders()}
{
}

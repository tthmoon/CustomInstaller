#include <QFileDialog>

#include "wdirectory.h"

QString WDirectory::choose(
  const QString& title,
  const QString& start_path
)
{
  QString dir_path =
    QFileDialog::getExistingDirectory(
      0,
      title,
      start_path,
      QFileDialog::ShowDirsOnly
    );
  QDir dir(dir_path);

  if (dir_path.isEmpty() || !dir.exists()) {
    return start_path;
  }
  else {
    return dir.absolutePath();
  }
}

#include "files.h"
#include "../qzipreader_p.h"
#include "../qzipwriter_p.h"

#include <QTextStream>


Files::Files()
  : system_name_ {System::getPrettyOsName()}
{
}

QString Files::addCmdCommas(QString string)
{
  return "\"" + string + "\"";
}

void Files::runApp(const QString& app_path, QStringList args, int msec_timeout)
{
  QProcess app;
  if (system_name_ == SystemNames::WINDOWS){
    app.start(app_path , args);
    app.waitForFinished(msec_timeout);
  }
}

void Files::extractZip(const QString& zip_path, const QString& output_path)
{
  QZipReader* zip = new QZipReader(QDir::toNativeSeparators(zip_path));
  zip->extractAll(QDir::toNativeSeparators(output_path));
  zip->close();
  delete  zip;
}

void Files::appendToFile(const QString& file_path, QString txt)
{
  QFile file_a(file_path);
  if(file_a.open(QIODevice::Append|QIODevice::Text)){
      QTextStream outLog(&file_a);
      outLog << txt<<endl;
  }
  file_a.close();
}
void Files::copyFile(const QString& file_path, const QString& dist_file_path){
  QFile distIni (dist_file_path);
  if (distIni.exists()){
    distIni.remove();
  }
  QFile::copy(file_path, dist_file_path);
}



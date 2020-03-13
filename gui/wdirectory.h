#ifndef PARKONA_SERVER_GUI_WDIRECTORY_H
#define PARKONA_SERVER_GUI_WDIRECTORY_H

namespace Parkona {
  namespace Server {
    namespace Gui {
      class WDirectory;
    }
  }
}

#include <QString>

class WDirectory
{
public:
  static QString choose(
    const QString& title,
    const QString& start_path
  );
};

#endif // PARKONA_SERVER_GUI_WDIRECTORY_H

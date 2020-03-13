#ifndef DATAPROVIDER_H
#define DATAPROVIDER_H

#include <QString>

class DataProvider
{
public:
  DataProvider();
  struct {
    struct
    {
      QString program_path_;
      QString base_path_;
      QString work_path_;
      QString tar_path_;
      QString start_menu_folder_;
    }folders_;

    struct
    {
      QString target_path_;
      QString start_menu_folder_;
      QString link_name_;
      QString shortcut_disription_;
    } shortcut_;
    bool if_clear_base_dir_;
  } installer_;
  void save();

private:
  void load();
};

#endif // DATAPROVIDER_H

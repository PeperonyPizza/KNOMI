
#pragma once

#include "log.h"
#include "ui/ResourceImage.h"
#include <Arduino.h>
#include <vector>

class KnownResourceImages {
public:
  static std::vector<const char *> enumerateFiles();

  static ResourceImage *get_AP_Config(int x = 0, int y = 0);

  static ResourceImage *get_AP_Config_Back(int x = 0, int y = 0);

  static ResourceImage *get_AfterPrinting(int x = 0, int y = 0);

  static ResourceImage *get_BTT_LOGO(int x = 0, int y = 0);

  static ResourceImage *get_BeforePrinting(int x = 0, int y = 0);

  static ResourceImage *get_Disconnect_Back(int x = 0, int y = 0);

  static ResourceImage *get_Home(int x = 0, int y = 0);

  static ResourceImage *get_Print_ok(int x = 0, int y = 0);

  static ResourceImage *get_Printing(int x = 0, int y = 0);

  static ResourceImage *get_Standby(int x = 0, int y = 0);

  static ResourceImage *get_Voron(int x = 0, int y = 0);

  static ResourceImage *get_bed_temp(int x = 0, int y = 0);

  static ResourceImage *get_ext_temp(int x = 0, int y = 0);

  static ResourceImage *get_levelling(int x = 0, int y = 0);
};
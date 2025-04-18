
#include "generated/images.h"

const PROGMEM char *FILE_AP_Config = "AP_Config.gif";
const PROGMEM char *FILE_AP_Config_Back = "AP_Config_Back.gif";
const PROGMEM char *FILE_AfterPrinting = "AfterPrinting.gif";
const PROGMEM char *FILE_BTT_LOGO = "BTT_LOGO.gif";
const PROGMEM char *FILE_BeforePrinting = "BeforePrinting.gif";
const PROGMEM char *FILE_Disconnect_Back = "Disconnect_Back.gif";
const PROGMEM char *FILE_Home = "Home.gif";
const PROGMEM char *FILE_Print_ok = "Print_ok.gif";
const PROGMEM char *FILE_Printing = "Printing.gif";
const PROGMEM char *FILE_Standby = "Standby.gif";
const PROGMEM char *FILE_Voron = "Voron.gif";
const PROGMEM char *FILE_bed_temp = "bed_temp.gif";
const PROGMEM char *FILE_ext_temp = "ext_temp.gif";
const PROGMEM char *FILE_levelling = "levelling.gif";

std::vector<const char *> KnownResourceImages::enumerateFiles() {
  auto result = std::vector<const char *>();

  result.push_back(FILE_AP_Config);
  result.push_back(FILE_AP_Config_Back);
  result.push_back(FILE_AfterPrinting);
  result.push_back(FILE_BTT_LOGO);
  result.push_back(FILE_BeforePrinting);
  result.push_back(FILE_Disconnect_Back);
  result.push_back(FILE_Home);
  result.push_back(FILE_Print_ok);
  result.push_back(FILE_Printing);
  result.push_back(FILE_Standby);
  result.push_back(FILE_Voron);
  result.push_back(FILE_bed_temp);
  result.push_back(FILE_ext_temp);
  result.push_back(FILE_levelling);
  return result;
}

ResourceImage *KnownResourceImages::get_AP_Config(int x, int y) { return new ResourceImage(FILE_AP_Config, x, y); }

ResourceImage *KnownResourceImages::get_AP_Config_Back(int x, int y) {
  return new ResourceImage(FILE_AP_Config_Back, x, y);
}

ResourceImage *KnownResourceImages::get_AfterPrinting(int x, int y) {
  return new ResourceImage(FILE_AfterPrinting, x, y);
}

ResourceImage *KnownResourceImages::get_BTT_LOGO(int x, int y) { return new ResourceImage(FILE_BTT_LOGO, x, y); }

ResourceImage *KnownResourceImages::get_BeforePrinting(int x, int y) {
  return new ResourceImage(FILE_BeforePrinting, x, y);
}

ResourceImage *KnownResourceImages::get_Disconnect_Back(int x, int y) {
  return new ResourceImage(FILE_Disconnect_Back, x, y);
}

ResourceImage *KnownResourceImages::get_Home(int x, int y) { return new ResourceImage(FILE_Home, x, y); }

ResourceImage *KnownResourceImages::get_Print_ok(int x, int y) { return new ResourceImage(FILE_Print_ok, x, y); }

ResourceImage *KnownResourceImages::get_Printing(int x, int y) { return new ResourceImage(FILE_Printing, x, y); }

ResourceImage *KnownResourceImages::get_Standby(int x, int y) { return new ResourceImage(FILE_Standby, x, y); }

ResourceImage *KnownResourceImages::get_Voron(int x, int y) { return new ResourceImage(FILE_Voron, x, y); }

ResourceImage *KnownResourceImages::get_bed_temp(int x, int y) { return new ResourceImage(FILE_bed_temp, x, y); }

ResourceImage *KnownResourceImages::get_ext_temp(int x, int y) { return new ResourceImage(FILE_ext_temp, x, y); }

ResourceImage *KnownResourceImages::get_levelling(int x, int y) { return new ResourceImage(FILE_levelling, x, y); }

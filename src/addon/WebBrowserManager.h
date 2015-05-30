#pragma once
/*
 *      Copyright (C) 2015 Team KODI
 *      http:/kodi.tv
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <map>

#include "include/cef_app.h"
#include "include/cef_client.h"
#include "platform/threads/threads.h"

#include "SettingsMain.h"
#include "WebBrowserClient.h"

class CWebBrowserManager : public PLATFORM::CThread
{
public:
  CWebBrowserManager();
  virtual ~CWebBrowserManager();

  bool Create();
  void Destroy();

  bool IsActive() const { return m_isActive; }

  WEB_ADDON_ERROR CreateControl(const WEB_ADDON_GUI_PROPS &props, unsigned int webType, ADDON_HANDLE handle);
  bool DestroyControl(const ADDON_HANDLE handle);
  bool SetLanguage(const char *language);
  void Render(const ADDON_HANDLE handle);
  bool OpenWebsite(const ADDON_HANDLE handle, const char* strURL, bool single, bool allowMenus);
  void Stop(const ADDON_HANDLE handle);
  bool Dirty(const ADDON_HANDLE handle);
  bool OnInit(const ADDON_HANDLE handle);
  bool OnAction(const ADDON_HANDLE handle, int actionId, int &nextItem);
  bool OnMouseEvent(const ADDON_HANDLE handle, int id, double x, double y, double offsetX, double offsetY, int state);

  bool LoadUserSettings(void);
  bool SaveUserSettings(void);

protected:
  virtual void *Process(void);

private:
  void SetCEFPaths();

  static int        m_iUniqueClientId;

  CefSettings       m_CefSettings;
  CefRefPtr<CefApp> m_CefApp;
  std::string       m_strHTMLCacheDir;
  std::string       m_strCookiePath;
  std::string       m_strResourcesPath;
  std::string       m_strLocalesPath;
  std::string       m_strLibPath;

  PLATFORM::CMutex  m_Mutex;
  std::map<int, CWebBrowserClient*> m_BrowserClients;
  std::map<std::string, CWebBrowserClient*> m_BrowserClientsInactive;

  CSettingsMain     m_setting;
  bool              m_isActive;
};
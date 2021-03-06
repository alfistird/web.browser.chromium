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

#if defined(HAVE_GL)
#include "WebBrowserClientOpenGL.h"
typedef CWebBrowserClientOpenGL CWebBrowserClient;
#elif defined(HAS_DX)
#include "WebBrowserClientDirectX.h"
typedef CWebBrowserClientDirectX CWebBrowserClient;
#error Render system is currently not implemented.
#elif defined(HAVE_GLES2)
#include "WebBrowserClientOpenGLES2.h"
typedef CWebBrowserClientOpenGLES2 CWebBrowserClient;
#error Render system is currently not implemented.
#else
#error Render system is not supported.
#endif

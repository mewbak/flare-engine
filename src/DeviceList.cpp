/*
Copyright © 2014 Justin Jacobs

This file is part of FLARE.

FLARE is free software: you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation,
either version 3 of the License, or (at your option) any later version.

FLARE is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
FLARE.  If not, see http://www.gnu.org/licenses/
*/

#include <stdio.h>
#include <string>

#include "DeviceList.h"

#include "SDLSoftwareRenderDevice.h"
#include "SDLHardwareRenderDevice.h"

#include "SDLFontEngine.h"
#include "SDLSoundManager.h"
#include "SDLInputState.h"

RenderDevice* getRenderDevice(const std::string& name) {
#if defined(__ANDROID__) || defined (__IPHONEOS__)
	// Android and IOS always use the hardware renderer
	return new SDLHardwareRenderDevice();
#endif

	// "sdl" is the default
	if (name != "") {
		if (name == "sdl") return new SDLSoftwareRenderDevice();
		else if (name == "sdl_hardware") return new SDLHardwareRenderDevice();
		else {
			logError("DeviceList: Render device '%s' not found. Falling back to the default.", name.c_str());
			return new SDLSoftwareRenderDevice();
		}
	}
	else {
		return new SDLSoftwareRenderDevice();
	}
}

FontEngine* getFontEngine() {
	return new SDLFontEngine();
}

SoundManager* getSoundManager() {
	return new SDLSoundManager();
}

InputState* getInputManager() {
	return new SDLInputState();
}

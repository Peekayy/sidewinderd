/**
 * Copyright (c) 2014 - 2016 Tolga Cakir <tolga@cevel.net>
 *
 * This source file is part of Sidewinder daemon and is distributed under the
 * MIT License. For more information, see LICENSE file.
 */

#ifndef LOGITECH_G105_CLASS_H
#define LOGITECH_G105_CLASS_H

#include <core/keyboard.hpp>
#include <core/led.hpp>
#include <core/led_group.hpp>

class LogitechG105 : public Keyboard {
	public:
		LogitechG105(sidewinderd::DeviceData *deviceData, sidewinderd::DevNode *devNode, libconfig::Config *config, Process *process);

	protected:
		struct KeyData getInput();
		void recordMacro(std::string path);
		void handleKey(struct KeyData *keyData);
		void handleRecordMode();

	private:
		LedGroup group_;
		Led ledProfile1_;
		Led ledProfile2_;
		Led ledProfile3_;
		Led ledRecord_;
		void setProfile(int profile);
		void disableGhostInput();
};

#endif
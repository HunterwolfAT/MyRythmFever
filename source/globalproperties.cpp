#include "globalproperties.h"

GlobalProperties::GlobalProperties() {
	base_window_width = 1920;
	base_window_height = 1080;
}

void GlobalProperties::updateResolution( int new_base_height, int new_base_width ) {
	true_window_width = new_base_width;
	true_window_height = new_base_height;
	screenscale_factor = true_window_height / base_window_height;
	scaled_window_width = base_window_width * screenscale_factor;
	scaled_window_height = base_window_height * screenscale_factor;
}

int GlobalProperties::get_base_window_height() {
	return base_window_height;
}

int GlobalProperties::get_base_window_width() {
	return base_window_width;
}

int GlobalProperties::get_scaled_window_height() {
	return scaled_window_height;
}

int GlobalProperties::get_scaled_window_width() {
	return scaled_window_width;
}

//globalproperties = new GlobalProperties();

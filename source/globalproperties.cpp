#include "globalproperties.h"

GlobalProperties::GlobalProperties() {

}

GlobalProperties::~GlobalProperties() {

}

GlobalProperties* GlobalProperties::getInstance() {
	static GlobalProperties instance;
	return &instance;
}

void GlobalProperties::updateResolution( int new_base_height, int new_base_width ) {
	true_window_width = new_base_width;
	true_window_height = new_base_height;
	screenscale_factor = true_window_height / base_window_height;
	scaled_window_width = base_window_width * screenscale_factor;
	scaled_window_height = base_window_height * screenscale_factor;
}

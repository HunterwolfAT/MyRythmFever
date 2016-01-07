#include "globalproperties.h"

GlobalProperties::GlobalProperties( int base_window_y = 720, int base_window_x = 1280 ) {
	base_window_width = base_window_x;
	base_window_height = base_window_y;

	resolution_set = false;
}

void GlobalProperties::updateResolution( int new_base_height, int new_base_width ) {
	true_window_width = new_base_width;
	true_window_height = new_base_height;
	screenscale_factor = true_window_height / base_window_height;
	scaled_window_width = base_window_width * screenscale_factor;
	scaled_window_height = base_window_height * screenscale_factor;
	resolution_set = true;
}

int GlobalProperties::get_base_window_height() {
	if (resolution_set)
		return base_window_height;
	else
		error( 1 );
	return -1;
}

int GlobalProperties::get_base_window_width() {
	if (resolution_set)
		return base_window_width;
	else
		error( 1 );
	return -1;
}

int GlobalProperties::get_scaled_window_height() {
	if (resolution_set)
		return scaled_window_height;
	else
		error( 1 );
	return -1;
}

int GlobalProperties::get_scaled_window_width() {
	if (resolution_set)
		return scaled_window_width;
	else
		error( 1 );
	return -1;
}

void GlobalProperties::error( int error_id ) {
	if (error_id == 1 )
		std::cout << "Tried accessing resolution, when resolution has not been set yet!" << std::endl;
}

//globalproperties = new GlobalProperties();

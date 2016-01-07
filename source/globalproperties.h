#ifndef GLOBALPROPERTIES_H
#define GLOBALPROPERTIES_H

class GlobalProperties {
	private:

		// Resolution / Graphics
		int base_window_width;
		int base_window_height;
		int true_window_width;
		int true_window_height;
		int scaled_window_width;
		int scaled_window_height;

	public:
		GlobalProperties();
		void updateResolution( int new_base_height, int new_base_width );
		int get_base_window_height();
		int get_base_window_width();
		int get_scaled_window_height();
		int get_scaled_window_width();

		int screenscale_factor;
};

#endif

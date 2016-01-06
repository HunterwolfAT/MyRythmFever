#ifndef GLOBALPROPERTIES_H
#define GLOBALPROPERTIES_H

class GlobalProperties {

	private:
		GlobalProperties();
		~GlobalProperties();

		// Resolution / Graphics
		int base_window_width = 1920;
		int base_window_height = 1080;
		int true_window_width;
		int true_window_height;
		int scaled_window_width;
		int scaled_window_height;
	
	public:
		static GlobalProperties *getInstance();
		void updateResolution( int new_base_height, int new_base_width );

		int screenscale_factor;
};

#endif

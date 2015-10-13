#copy this file to ~/.config/fish/functions/ to autoload it at startup

function debug
	mkdir build
	if make
		echo "Compilation Done. Starting myRythmFever..."
		./myRythmFever magalovania.mp3
		echo "Done."
	end
end

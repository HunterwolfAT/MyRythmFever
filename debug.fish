#copy this file to ~/.config/fish/functions/ to autoload it at startup

function debug
	if g++ -o myRythmFever main.cpp editor.cpp -lSDL2
		echo "Compilation Done. Starting myRythmFever..."
		./myRythmFever
		echo "Done."
	end
end

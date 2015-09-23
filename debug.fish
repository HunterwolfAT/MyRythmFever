#copy this file to ~/.config/fish/functions/ to autoload it at startup

function debug
	if make
		echo "Compilation Done. Starting myRythmFever..."
		./myRythmFever
		echo "Done."
	end
end

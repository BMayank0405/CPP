if $1; then
	g++ -Wshadow -Wall -Weffc++ -Wextra -g ./$2 -o ./$3 -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG

else
	if [ ! -f "./$3" ]; then
		g++ -Wshadow -Wall -Weffc++ -Wextra -g ./$2 -o ./$3 -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG 
	fi
fi

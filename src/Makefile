--check-%:
	@if [ "`command -v ${*}`" = "" ]; then \
		echo "Command ${*} not found in path";  \
		exit 1; \
	fi

build: --check-clang
	clang -Wall hello.c lang.c -o hello
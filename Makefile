make all:
	mkdir -p build
	cmake -GNinja -Bbuild .
	ninja -C build

all:
	g++ src/shop.cpp src/InventoryManager.cpp src/inventory.c -o app

clean:
	rm -f app inventory.dat
#include <iostream>
#include "InventoryManager.h"

int main() {
    InventoryManager manager;
    int choice;

    while (true) {
        std::cout << "\n1 Add\n2 View\n3 Update\n4 Delete\n5 List\n6 Exit\nChoice: ";
        std::cin >> choice;

        if (choice == 6) break;

        Item item;
        int id;

        switch (choice) {
            case 1:
                std::cout << "ID Name Qty Price: ";
                std::cin >> item.id >> item.name >> item.quantity >> item.price;
                item.is_deleted = 0;
                manager.addItem(item);
                break;

            case 2:
                std::cout << "ID: ";
                std::cin >> id;
                manager.viewItem(id);
                break;

            case 3:
                std::cout << "ID: ";
                std::cin >> id;
                std::cout << "Name Qty Price: ";
                std::cin >> item.name >> item.quantity >> item.price;
                item.id = id;
                item.is_deleted = 0;
                manager.updateItem(id, item);
                break;

            case 4:
                std::cout << "ID: ";
                std::cin >> id;
                manager.deleteItem(id);
                break;

            case 5:
                manager.listAll();
                break;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include "InventoryManager.h"

void InventoryManager::addItem(Item item) {
    if (item.id <= 0 || item.quantity < 0 || item.price < 0 || strlen(item.name) == 0) {
        std::cout << "Invalid input!\n";
        return;
    }

    if (add_item(item))
        std::cout << "Item added\n";
    else
        std::cout << "Duplicate ID!\n";
}

void InventoryManager::viewItem(int id) {
    Item item;
    if (get_item(id, &item)) {
        std::cout << item.id << " " << item.name << " "
                  << item.quantity << " " << item.price << "\n";
    } else {
        std::cout << "Not found\n";
    }
}

void InventoryManager::updateItem(int id, Item item) {
    if (update_item(id, item))
        std::cout << "Updated\n";
    else
        std::cout << "Failed\n";
}

void InventoryManager::deleteItem(int id) {
    if (delete_item(id))
        std::cout << "Deleted\n";
    else
        std::cout << "Failed\n";
}

void InventoryManager::listAll() {
    Item buffer[100];
    int n = list_items(buffer, 100);

    std::vector<Item> items(buffer, buffer + n);

    std::sort(items.begin(), items.end(), [](Item a, Item b) {
        return a.id < b.id;
    });

    for (auto &i : items) {
        std::cout << i.id << " " << i.name
                  << " " << i.quantity << " " << i.price << "\n";
    }
}
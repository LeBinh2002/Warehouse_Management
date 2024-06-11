#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

struct Product {
    int id;
    string name;
    string category;
    int quantity;
    double price;
};

class Warehouse {
private:
    vector<Product> products;

public:
    void addProduct() {
        system("cls");
        Product p;
        cout << "--- Add Product ---\n";
        cout << "Enter Product ID: ";
        cin >> p.id;
        cin.ignore();
        cout << "Enter Product Name: ";
        getline(cin, p.name);
        cout << "Enter Product Category: ";
        getline(cin, p.category);
        cout << "Enter Product Quantity: ";
        cin >> p.quantity;
        cout << "Enter Product Price: ";
        cin >> p.price;
        products.push_back(p);
        cout << "Product added successfully!" << endl;
    }

    void removeProduct() {
        system("cls");
        int id;
        cout << "--- Remove Product ---\n";
        cout << "Enter Product ID to remove: ";
        cin >> id;
        auto it = remove_if(products.begin(), products.end(), [id](Product &p) { return p.id == id; });
        if (it != products.end()) {
            products.erase(it, products.end());
            cout << "Product removed successfully!" << endl;
        } else {
            cout << "Product not found!" << endl;
        }
    }

    void displayProducts() {
        system("cls");
        cout << "--- Display Products ---\n";
        if (products.empty()) {
            cout << "No products in the warehouse!" << endl;
            return;
        }
        for (const auto &p : products) {
            cout << "ID: " << p.id << ", Name: " << p.name << ", Category: " << p.category;
            cout << ", Quantity: " << p.quantity << ", Price: " << p.price << endl;
        }
    }

    void searchProduct() {
        system("cls");
        int id;
        cout << "--- Search Product ---\n";
        cout << "Enter Product ID to search: ";
        cin >> id;
        for (const auto &p : products) {
            if (p.id == id) {
                cout << "Product found:\n";
                cout << "ID: " << p.id << ", Name: " << p.name << ", Category: " << p.category;
                cout << ", Quantity: " << p.quantity << ", Price: " << p.price << endl;
                return;
            }
        }
        cout << "Product not found!" << endl;
    }

    void exportToFile() {
        system("cls");
        cout << "--- Export Products to File ---\n";
        ofstream outFile("products.txt");
        if (!outFile) {
            cerr << "Error opening file for writing!" << endl;
            return;
        }
        for (const auto &p : products) {
            outFile << "ID: " << p.id << "\nName: " << p.name << "\nCategory: " << p.category;
            outFile << "\nQuantity: " << p.quantity << "\nPrice: " << p.price << "\n\n";
        }
        outFile.close();
        cout << "Products exported to products.txt successfully!" << endl;
    }
};

int main() {
    Warehouse warehouse;
    int choice;
    do {
        system("cls");
        cout << "\n--- Warehouse Management System ---\n";
        cout << "1. Add Product\n";
        cout << "2. Remove Product\n";
        cout << "3. Display Products\n";
        cout << "4. Search Product\n";
        cout << "5. Export Products to File\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                warehouse.addProduct();
                system("pause");
                break;
            case 2:
                warehouse.removeProduct();
                system("pause");
                break;
            case 3:
                warehouse.displayProducts();
                system("pause");
                break;
            case 4:
                warehouse.searchProduct();
                system("pause");
                break;
            case 5:
                warehouse.exportToFile();
                system("pause");
                break;
            case 6:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                system("pause");
        }
    } while (choice != 6);
    return 0;
}

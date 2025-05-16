#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

const int TABLE_SIZE = 2000;
const int P = 31;

struct Company {
    string name;
    string profit_tax;
    string address;
};

struct HashTable {
    vector<Company> table[TABLE_SIZE];
};

vector<Company> readCompanyList(string file_name) {
    vector<Company> list;
    ifstream file(file_name);
    string line;
    getline(file, line); 
    while (getline(file, line)) {
        stringstream ss(line);
        string name, tax, address;
        getline(ss, name, '|');
        getline(ss, tax, '|');
        getline(ss, address);
        list.push_back({ name, tax, address });
    }
    return list;
}

long long hashString(string company_name) {
    string s = company_name;
    if (s.size() > 20) s = s.substr(s.size() - 20);
    long long hash = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash = (hash + (c * p_pow)) % TABLE_SIZE;
        p_pow = (p_pow * P) % TABLE_SIZE;
    }
    return hash;
}

HashTable* createHashTable(vector<Company> list_company) {
    HashTable* ht = new HashTable();
    for (Company c : list_company) {
        long long idx = hashString(c.name);
        ht->table[idx].push_back(c);
    }
    return ht;
}

void insert(HashTable* hash_table, Company company) {
    long long idx = hashString(company.name);
    hash_table->table[idx].push_back(company);
}

Company* search(HashTable* hash_table, string company_name) {
    long long idx = hashString(company_name);
    for (Company& c : hash_table->table[idx]) {
        if (c.name == company_name) {
            return &c;
        }
    }
    return nullptr;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: ./main MST.txt input.txt output.txt" << endl;
        return 1;
    }

    vector<Company> list = readCompanyList(argv[1]);
    HashTable* ht = createHashTable(list);

    ifstream input(argv[2]);
    ofstream output(argv[3]);

    string name;
    while (getline(input, name)) {
        Company* found = search(ht, name);
        if (found) {
            output << found->name << "|" << found->profit_tax << "|" << found->address << endl;
        }
    }

    return 0;
}

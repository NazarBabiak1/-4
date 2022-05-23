#include <iostream>
#include <list>
using namespace std;

class HashTable
{
    int capacity;
    list<string>* table;

public:
    HashTable(int V);
    void INSERT(int key, string data);
    void DELETE(int key);

    int checkPrime(int n)
    {
        int i;
        if (n == 1 || n == 0)
        {
            return 0;
        }
        for (i = 2; i < n / 2; i++)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
    int getPrime(int n)
    {
        if (n % 2 == 0)
        {
            n++;
        }
        while (!checkPrime(n))
        {
            n += 2;
        }
        return n;
    }

    int hash(int key)
    {
        return (key % capacity);
    }
    void PRINT();
};
HashTable::HashTable(int c)
{
    int size = getPrime(c);
    this->capacity = size;
    table = new list<string>[capacity];
}
void HashTable::INSERT(int key,string data)
{
    int index = hash(key);
    table[index].push_back(data);
}

void HashTable::DELETE(int key)
{
    int index = hash(key);
    list<string>::iterator i;
    i = table[index].begin();
  
    table[index].erase(i);

}

void HashTable::PRINT()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << "table[" << i << "]";
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}

int main()
{
    int key[] = { 231, 321, 212, 321, 431, 262,543,983,183,672,871,982,464,511,323 };
    string data[] = { "Nazar", "Andriy","Dmytro","Oleg","Igor","Mykyta","Vitaliy","Taras","Lyubomyr","Oleksander","Victor","Yuriy","Vasyl","Ivan","Petro"};
    int size = sizeof(key) / sizeof(key[0]);
    HashTable h(size);

    for (int i = 0; i < 15; i++)
        h.INSERT(key[i], data[i]);

    h.DELETE(231); //delete NAZAR
    h.PRINT();
}
// Created by User on 031 31.08.20 .

// templates need to be instantiated with initialization

/* to use example:
    hashTable<int> tabled(300); // save type and size
    tabled.push("get", 2139123); // key and data

    for (int i : tabled.GetAllBlocks())  // vector
        std::cout << i << std::endl;

    std::cout << tabled.get("get") << std::endl;
 */

#ifndef CPP_FILES_HASHTABLE_H
#define CPP_FILES_HASHTABLE_H

#include <string>
#include <vector>

template <class T>
class hashTable {
private:
    int hashFunc(const std::string& k) {
        unsigned long hval = 0;
        for (int i : k)
            hval = (hval << 6) + (hval * 423) ^ (i * 234) ^ int(i * 1.43 + tableSize);

        hval %= tableSize;
        return hval;
    };

protected:
    struct datablock
    {
        std::string label = "Null";
        T data = T();
        datablock *pointer = nullptr;
    };
public:
    int tableSize;
    std::vector<datablock*> table;

    explicit hashTable(int size = 10){
        table.resize(size);
        for (int i = 0; i < size; i++)
        {
            table[i] = new datablock;
        }
        tableSize = size;
    };

    void push(std::string label, T data){
        int hashedLabel = this-> hashFunc(label);
        datablock *workingRow = table[hashedLabel];

        while (workingRow-> pointer != nullptr)
            workingRow = workingRow->pointer;

        *workingRow =  {
                label,
                data,
                new datablock
        };
    };

    T get(const std::string& label){
        datablock *workingRow = table[hashFunc(label)];

        if (workingRow-> pointer == nullptr)
            return 0;

        while (workingRow-> pointer != nullptr &&
               workingRow-> label != label)
            workingRow = workingRow->pointer;

        return workingRow-> data;
    };

    std::vector<T> GetAllBlocks(){
        std::vector<T> mas;
        int level = 0;
        for (int i = 0; i < tableSize; i++)
        {
            datablock *workingRow = table[i];
            while (workingRow-> pointer != nullptr){
                mas.push_back(workingRow-> data);
                workingRow = workingRow->pointer;
                level++;
            }
        }
        return mas;
    };

    ~hashTable(){
        for (int i = 0; i < tableSize; i++) {
            if (table[i]->pointer != nullptr) {
                int level = 0;
                datablock *workingRow = table[i];
                while (workingRow->pointer != nullptr) {
                    workingRow = workingRow->pointer;
                    level++;
                }
                while (level > 0) {
                    int incr = 0;
                    workingRow= table[i];
                    while (incr < level) {
                        workingRow = workingRow->pointer;
                        incr++;
                    }
                    //cout << "to del " << i << "." << level-1 << endl;
                    delete workingRow;
                    level--;
                }

            } else {
                delete table[i];
            }
        }
    };
};

#endif //CPP_FILES_HASHTABLE_H

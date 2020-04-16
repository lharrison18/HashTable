#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;

class HashTable {

private:
    const static int CAP = 33;
    list<string> myTable[CAP];

    int hashFunc(string str) {
        int sum = 0;
        for (int i = 0; i < str.size(); i++)
        {
            sum += str[i];
            return sum % CAP;
        }


    }

public:

    void insert(string str) {

        if (locate(str))return;

        int index = hashFunc(str);
        myTable[index].push_back(str);
    }

    bool locate(string str) {

        int index = hashFunc(str);
        list<string>::iterator word = myTable[index].begin();
        while (word != myTable[index].end() && (*word) != str)
            word++;

        if (word == myTable[index].end()) return false;

        return true;
    }


    void print() {
        for (int i = 0; i < CAP; i++)
        {
            cout << "[" << i << "] : ";

        }
    }

    void printlist(int i) {
        for (auto const& i : myTable[i])

            cout << i << "->";
        cout << "**" << endl;
    }


};

int main() {



    ifstream fin("FourLetterWords.txt"); //infile

    if (fin) {
        cout << "The file was found." << endl;
    }
    else
    {
        cout << "The file was not found." << endl;
    }

    HashTable test;

    string str;
    while (fin >> str) {
       // test.insert(str);
    }

   

    test.print();

    system("pause");
    return 0;
}

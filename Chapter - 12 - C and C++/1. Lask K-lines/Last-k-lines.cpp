#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void printlastKLines(string fileName,int K) {

        ifstream file;
        file.open(fileName.c_str());
        string L[K];
        int size = 0;
        /* read file line by line into circular array */
        /* peek() so an EOF following a line ending is not considered a separate line */
        while (file.peek() != EOF) {
                getline(file, L[size % K]);
                size++;
        }

        /* compute start of circular array, and the size of it */
        int start= size> K? (size% K) : 0;
        int count= min(K, size);
        /* print elements in the order they were read */
        for (int i= 0; i < count; i++) {
                cout << L[(start + i) % K] << endl;
        }
        file.close();
 }

 int main ()
{
    string str;
    int K;
    cout << "Please enter file name: \n";
    cin >> str;
    cout << "Please enter the value of K (No. of lines) :\n";
    cin >> K;
    printlastKLines(str,K);
    return 0;
}

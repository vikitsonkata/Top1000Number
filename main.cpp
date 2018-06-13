#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> //find, sort
using namespace std;

#define count 1000

vector<int> numbers(count, -2147483648);

void writeInFile(const string& fileName = "/home/default/projects/task_Mitaka/top1000.txt");
void printNumbers();

int main(int argc, char **argv)
{
    string fileName("/home/default/projects/task_Mitaka/");
    if(argc == 1)
        fileName.append("set.txt");
    else
        fileName.append(argv[1]);
    cout << fileName << endl;
    ifstream file(fileName);
    numbers.reserve(2*count);
    int num, min = -2147483648;

    if(file.is_open())
    {
        while(file >> num)
        {
            if(num > min )//&& !(find(numbers.begin(), numbers.end(), num) != numbers.end()))
            {
                //top1000
                numbers.push_back(num);
                if(numbers.size() > 2*count)
                {
                    sort(numbers.begin(), numbers.end(), greater<int>());
                    numbers.erase(numbers.begin()+count, numbers.end());
                    min = numbers[count-1];
                }
            }
            file.ignore(); //numbers divided with ','
        }
        file.close();

        //LAST STEP OF SORTING
        if(numbers.size() > count)
        {
            sort(numbers.begin(), numbers.end(), greater<int>());
            numbers.erase(numbers.begin()+count, numbers.end());
        }

//        printNumbers();
        writeInFile();
    }

    return 0;
}

void writeInFile(const string& fileName)
{
    ofstream sorted(fileName);
    if(sorted.is_open())
    {
        for(auto &i: numbers)
            sorted << i << endl;
        sorted.close();
    }
}

void printNumbers()
{
//        for(auto &i: numbers)
//            cout << i << endl;
}
